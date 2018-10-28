#include <QDebug>

#include "ClientRequestAPI.h"
#include "QMessageBox"
#include "Parse.h"


ClientRequestAPI::ClientRequestAPI() :_isConnect(false)
{
	//_socket = new Socket; //原始套接字，已废弃。
	m_tcpSocket = new QTcpSocket(); //创建套接字 
}

ClientRequestAPI::~ClientRequestAPI()
{
}

ClientRequestAPI * ClientRequestAPI::instance()
{
	static ClientRequestAPI t;
	return &t;
}

bool ClientRequestAPI::connect()
{
	//_socket->create();
	//QString str = "127.0.0.1";
	//bool ret = _socket->connect(str, 8080);
	//if (!ret)
	//{
	//	QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("连接失败..."));
	//}

	m_tcpSocket->connectToHost("127.0.0.1", 8080);
	if (!m_tcpSocket->waitForConnected(3000))
	{
		qDebug() << QStringLiteral("连接失败...");
	}

	_isConnect = true;
	return true;
}

//1号协议 注册 
bool ClientRequestAPI::registerAPI(const QString & userName, const QString & passWord, const QString & name, const QString & id, const QString & sex, const QString & phone, const QString & email, const QString & address, const QString & weight, const QString & height)
{
	char Send[1024] = "";
	sprintf(Send, "type=\"%s\"userName=\"%s\"passWord=\"%s\"name=\"%s\"id=\"%s\" sex=\"%s\"phone=\"%s\"email=\"%s\"address=\"%s\"weight=\"%s\"height=\"%s\"", "1", userName.toLocal8Bit().data(),
		passWord.toLocal8Bit().data(), name.toLocal8Bit().data(), id.toLocal8Bit().data(), sex.toLocal8Bit().data(),phone.toLocal8Bit().data(), email.toLocal8Bit().data(), address.toLocal8Bit().data(), weight.toLocal8Bit().data(), height.toLocal8Bit().data());
	//int len = _socket->send(Send);
	//if (!len)
	//{
	//	//QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("发送失败！"));
	//	return false;
	//}
	//char buf[1024] = "";
	//char userName1[64] = "";
	//char result[64] = "";
	//while (true)
	//{
	//	if (_socket->recv(buf) != 0)
	//	{
	//		if (Parse::instance()->getType(buf) == 1001)
	//		{
	//			Parse::instance()->Para1001(buf, userName1, result);
	//			if (atoi(result) != 0)
	//			{
	//				return false;
	//			}
	//		}
	//		return true;
	//	}
	//}
	//发送
	qint64 len = m_tcpSocket->write(Send);
	if (len < 0) 
	{
		qDebug() << QStringLiteral("发送失败..."); 
		return false;
	}
	char userName1[64] = "";
	char result[64] = "";
	//接收
	while (true)
	{
		if (m_tcpSocket->waitForReadyRead(5000))
		{
			QByteArray ba = m_tcpSocket->readAll();
			if (!ba.isEmpty())
			{
				if (Parse::instance()->getType(ba.data()) == 1001)
				{
					Parse::instance()->Para1001(ba.data(), userName1, result);
					if (atoi(result) != 0)
					{
						return false;
					}
					return true;
				}
			}
		}
		else
		{
			qDebug() << QStringLiteral("不好意思，超时了，接收失败...");
			return false;
		}
	}
	return true;
}

//2号协议 登录 
bool ClientRequestAPI::loginAPI(const QString & userName, const QString & passWord)
{
	char Send[1024] = "";
	sprintf(Send, "type=\"%s\"userName=\"%s\"passWord=\"%s\"", "2",
		userName.toLocal8Bit().data(), passWord.toLocal8Bit().data());
	qDebug() << "Send:" << Send;
	//int len = _socket->send(Send);
	//if (len == -1)
	//{
	//	//QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("发送失败！"));
	//	return false;
	//}
	//char buf[1024] = "";
	//char userName1[64] = "";
	//char result[64] = "";
	//while (true)
	//{
	//	if (_socket->recv(buf) != 0)
	//	{
	//		if (Parse::instance()->getType(buf) == 1002)
	//		{
	//			Parse::instance()->Para1002(buf, userName1, result);
	//			if (atoi(result) != 0)
	//			{
	//				return false;
	//			}
	//		}	
	//		qDebug() << "==========buf==========" << QString::fromLocal8Bit(buf);
	//		return true;
	//	
	//	}
	//}
	qint64 len = m_tcpSocket->write(Send);
	if (len < 0)
	{
		qDebug() << QStringLiteral("发送失败...");
		return false;
	}
	char userName1[64] = "";
	char result[64] = "";
	//接收
	while (true)
	{
		if (m_tcpSocket->waitForReadyRead(5000))
		{
			QByteArray ba = m_tcpSocket->readAll();
			if (!ba.isEmpty())
			{
				if (Parse::instance()->getType(ba.data()) == 1002)
				{
					Parse::instance()->Para1002(ba.data(), userName1, result);
					if (atoi(result) != 0)
					{
						return false;
					}
					return true;
				}
			}
		}
		else
		{
			qDebug() << QStringLiteral("不好意思，超时了，接收失败...");
			return false;
		}
	}
	return true;
}
// 3 获取用户信息
bool ClientRequestAPI::getUserInfoAPI( QString & userName,  QString & passWord,  QString & name,  QString & id,  QString & sex,  QString & phone,  QString & email,  QString & address,  QString & weight,  QString & height)
{
	char Send[1024] = "";
	sprintf(Send, "type=\"%s\"userName=\"%s\"", "3",
		userName.toLocal8Bit().data());
	//int len = _socket->send(Send);
	//if (len == -1)
	//{
	//	//QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("发送失败！"));
	//	return false;
	//}
	//char buf[2024] = "";
	//char userName2[64] = "";
	//char passWord2[64] = "";
	//char name2[64] = "";
	//char id2[64] = "";
	//char sex2[64] = "";
	//char phone2[64] = "";
	//char email2[64] = "";
	//char address2[64] = "";
	//char weight2[64] = "";
	//char height2[64] = "";
	//char result[64] = "";
	////int count = 0;
	//while (true)
	//{
	//	if (_socket->recv(buf) != 0)
	//	{
	//		if (Parse::instance()->getType(buf) == 1003)
	//		{
	//			Parse::instance()->Para1003(buf, userName2, passWord2, name2, id2, sex2, phone2, email2, address2, weight2, height2);
	//			
	//			userName = QString::fromLocal8Bit(userName2);
	//			passWord = QString::fromLocal8Bit(passWord2);
	//			name = QString::fromLocal8Bit(name2);
	//			id = QString::fromLocal8Bit(id2);
	//			sex = QString::fromLocal8Bit(sex2);
	//			phone = QString::fromLocal8Bit(phone2);
	//			email = QString::fromLocal8Bit(email2);
	//			address = QString::fromLocal8Bit(address2);
	//			weight = QString::fromLocal8Bit(weight2);
	//			height = QString::fromLocal8Bit(height2);
	//			
	//			if (atoi(result) != 0)
	//			{
	//				return false;
	//			}
	//		}
	//		//count++;
	//		//if (count == 2)
	//		//{
	//		//	return true;
	//		//}
	//		return true;
	//	}
	//}


	//发送
	qint64 len = m_tcpSocket->write(Send);
	if (len < 0)
	{
		qDebug() << QStringLiteral("发送失败...");
		return false;
	}
	char userName2[64] = "";
	char passWord2[64] = "";
	char name2[64] = "";
	char id2[64] = "";
	char sex2[64] = "";
	char phone2[64] = "";
	char email2[64] = "";
	char address2[64] = "";
	char weight2[64] = "";
	char height2[64] = "";
	char result[64] = "";
	//接收
	while (true)
	{
		if (m_tcpSocket->waitForReadyRead(5000))
		{
			QByteArray ba = m_tcpSocket->readAll();
			if (!ba.isEmpty())
			{
				if (Parse::instance()->getType(ba.data()) == 1003)
				{
					Parse::instance()->Para1003(ba.data(), userName2, passWord2, name2, id2, sex2, phone2, email2, address2, weight2, height2);

					userName = QString::fromLocal8Bit(userName2);
					passWord = QString::fromLocal8Bit(passWord2);
					name = QString::fromLocal8Bit(name2);
					id = QString::fromLocal8Bit(id2);
					sex = QString::fromLocal8Bit(sex2);
					phone = QString::fromLocal8Bit(phone2);
					email = QString::fromLocal8Bit(email2);
					address = QString::fromLocal8Bit(address2);
					weight = QString::fromLocal8Bit(weight2);
					height = QString::fromLocal8Bit(height2);
					if (atoi(result) != 0)
					{
						return false;
					}
					return true;
				}
			}
		}
		else
		{
			qDebug() << QStringLiteral("不好意思，超时了，接收失败...");
			return false;
		}
	}




	return true;
}

//4 号协议 存款 
bool ClientRequestAPI::depositAPI(const QString & userName, const QString & money)
{
	//char Send[1024] = "";
	//sprintf(Send, "type=\"%s\"userName=\"%s\"money=\"%s\"", "4",
	//	userName.toLocal8Bit().data(), money.toLocal8Bit().data());
	//int len = _socket->send((char *)Send);
	//if (len == -1)
	//{
	//	QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("发送失败！"));
	//	return false;
	//}
	//char buf[1024] = "";
	//char userName1[64] = "";
	//char result[64] = "";
	//int count = 0;
	//while (true)
	//{
	//	if (count > 1000) return false;
	//	
	//	if (_socket->recv(buf) != 0)
	//	{
	//		if (Parse::instance()->getType(buf) == 1004)
	//		{
	//			Parse::instance()->Para1004(buf, userName1, result);
	//			if (atoi(result) != 0)
	//			{
	//				return false;
	//			}
	//		}
	//		return true;
	//	}
	//	count++;
	//}
	return true;
}
//5号协议  取款
bool ClientRequestAPI::getAPI(const QString & userName, const QString & money)
{
	/*char Send[1024] = "";
	sprintf(Send, "type=\"%s\"userName=\"%s\"money=\"%s\"", "5",
		userName.toLocal8Bit().data(), money.toLocal8Bit().data());
	int len = _socket->send((char *)Send);
	if (len == -1)
	{
		QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("发送失败！"));
		return false;
	}
	char buf[1024] = "";
	char userName1[64] = "";
	char result[64] = "";
	while (true)
	{
		if (_socket->recv(buf) != 0)
		{
			if (Parse::instance()->getType(buf) == 1004)
			{
				Parse::instance()->Para1005(buf, userName1, result);
				if (atoi(result) != 0)
				{
					return false;
				}
			}
			return true;
		}
	}*/
	return true;
}

bool ClientRequestAPI::transferAPI(Socket *s, const QString & srcUserName, const QString & srcPassWord, const QString & destUserName, const QString & destPassWord, const QString & money)
{
	return false;
}

bool ClientRequestAPI::detailAPI(const QString & srcUserName, const QString & srcPassWord, const QString & startDate, const QString & endDate)
{
	return false;
}

