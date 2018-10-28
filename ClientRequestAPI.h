#pragma once

#include <QString>
#include <QTcpSocket>

#include "Socket.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	A client request a pi. </summary>
///
/// <remarks>	gan songlin, 2017/9/30. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class ClientRequestAPI
{
public:
	ClientRequestAPI();
	~ClientRequestAPI();

	static ClientRequestAPI *instance();

	bool isConnect() const { return _isConnect; }

	bool connect();

	//注册
	bool registerAPI(const QString & userName, const QString & passWord, const QString & name, const QString & id, const QString & sex, const QString & phone, const QString & email, const QString & address, const QString & weight, const QString & height);
	//登录
	bool loginAPI(const QString & userName, const QString & passWord);
	//获取用户信息 
	bool getUserInfoAPI(QString & userName, QString & passWord, QString & name, QString & id, QString & sex, QString & phone, QString & email, QString & address, QString & weight, QString & height);	bool depositAPI(const QString & userName, const QString & money);

	bool getAPI(const QString & userName, const QString & money);

	bool transferAPI(Socket *s, const QString & srcUserName, const QString & srcPassWord, const QString & destUserName, const QString & destPassWord, const QString & money);

	bool detailAPI(const QString & srcUserName, const QString & srcPassWord, const QString & startDate, const QString & endDate);

private:

	/// <summary>	True if this object is connect. </summary>
	bool _isConnect;
private:
	//Socket * _socket;


	QTcpSocket * m_tcpSocket; //tcp协议套接字
};

