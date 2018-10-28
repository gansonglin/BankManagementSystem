#pragma once

#include <QObject>
#include <QTcpSocket>

class JsonUtil : public QObject
{
	Q_OBJECT

public:
	JsonUtil(QObject *parent = Q_NULLPTR);
	~JsonUtil();

	static JsonUtil * getInstance();

	bool login(const QString & username,const QString & password); //100 

	bool addUser(const char * data); //101 
private:
	QTcpSocket * m_tcpSocket;
};
