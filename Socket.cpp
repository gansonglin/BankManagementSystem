#include "Socket.h"
#include "QMessageBox"


Socket::Socket() :_flag(1)
{
}


Socket::~Socket()
{
}

int Socket::create()
{
	// 加载socket动态链接库(dll)  
	WORD wVersionRequested;
	// 这结构是用于接收Wjndows Socket的结构信息的  
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD(1, 1);   // 请求1.1版本的WinSock库  

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("安装失败！"));
		return -1;          // 返回值为零的时候是表示成功申请WSAStartup  
	}

	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1) {
		// 检查这个低字节是不是1，高字节是不是1以确定是否我们所请求的1.1版本  
		// 否则的话，调用WSACleanup()清除信息，结束函数  
		WSACleanup();
		return -1;
	}

	// 创建socket操作，建立流式套接字，返回套接字号sockSrv  
	// SOCKET socket(int af, int type, int protocol);  
	// 第一个参数，指定地址簇(TCP/IP只能是AF_INET，也可写成PF_INET)  
	// 第二个，选择套接字的类型(流式套接字)，第三个，特定地址家族相关协议（0为自动）  
	_socket = ::socket(AF_INET, SOCK_STREAM, 0);
	return 0;
}

bool Socket::connect(QString & ip, int port)
{
	_flag = 0;
	SOCKADDR_IN addrSrv;  //定义一个socket地址 
	addrSrv.sin_addr.S_un.S_addr = inet_addr(ip.toLocal8Bit().data());      // 本地回路地址是127.0.0.1;   
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(port);
	int ret = ::connect(_socket, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
	if (ret)
	{
		QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("连接失败！"));
		return false;
	}
	return true;
}

void Socket::bind(int port)
{
	_flag = 1;
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY); // 将INADDR_ANY转换为网络字节序，调用 htonl(long型)或htons(整型)  
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(port);
	::bind(_socket, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
}

void Socket::listen(int count)
{
	::listen(_socket, count);
}

SOCKET Socket::accept(Socket *socket)
{
	int len = sizeof((SOCKADDR*)&socket->_addrClient);
	socket->_connectSocket = ::accept(_socket, (SOCKADDR*)&socket->_addrClient, &len);
	return socket->_connectSocket;
}

int Socket::send(const char buf[])
{
	if (_flag)
	{
		int len = ::send(_connectSocket, buf, strlen(buf) + 1, 0);  // 发送显示欢迎信息  
		return len;
	}
	else
	{
		int len = ::send(_socket, buf, strlen(buf), 0);  // 发送显示欢迎信息  
		return len;
	}
}

int Socket::recv(char buf [])
{
	if (_flag)
	{
		int len = ::recv(_connectSocket, buf, 100, 0);
		return len;
	}
	else
	{
		int len = ::recv(_socket, buf, 100000, 0);
		return len;
	}

}
