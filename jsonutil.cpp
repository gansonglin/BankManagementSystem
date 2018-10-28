#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>

#include "jsonutil.h"

JsonUtil::JsonUtil(QObject *parent)
	: QObject(parent)
{
	m_tcpSocket = new QTcpSocket(); //创建套接字 

	m_tcpSocket->connectToHost("127.0.0.1", 8080);
	if (!m_tcpSocket->waitForConnected(3000))
	{
		qDebug() << QStringLiteral("连接失败...");
	}
}

JsonUtil::~JsonUtil()
{
}

JsonUtil * JsonUtil::getInstance()
{
	static JsonUtil instance;
	return &instance;
}

bool JsonUtil::login(const QString & username, const QString & password)
{
	QJsonObject jsonObject;
	jsonObject.insert("type", 100);
	jsonObject.insert("username", username);
	jsonObject.insert("password", password);

	QJsonDocument document;
	document.setObject(jsonObject);
	QByteArray byteArray = document.toJson(QJsonDocument::Compact);

	qint64 len = m_tcpSocket->write(byteArray);
	if (len < 0)
	{
		qDebug() << QStringLiteral("发送失败...");
		return false;
	}
	while (true)
	{
		if (m_tcpSocket->waitForReadyRead(5000))
		{
			QByteArray byteArray = m_tcpSocket->readAll();
			if (!byteArray.isEmpty())
			{
				QJsonParseError jsonParseError;
				QJsonDocument jsonDocument = QJsonDocument::fromJson(byteArray, &jsonParseError);
				//if (jsonParseError.error != QJsonParseError::NoError) {
				//	return;
				//}
				int result = 0;
				QJsonObject jsonObject = jsonDocument.object();
				if (jsonObject.contains("result"))
				{
					QJsonValue JsonValue = jsonObject.value("result");
					result = JsonValue.toInt();
					if (result == 0)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				return false;
			}
		}
	}
}

bool JsonUtil::addUser(const char * data)
{
	return false;
}
