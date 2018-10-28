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
	// ����socket��̬���ӿ�(dll)  
	WORD wVersionRequested;
	// ��ṹ�����ڽ���Wjndows Socket�Ľṹ��Ϣ��  
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD(1, 1);   // ����1.1�汾��WinSock��  

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("��װʧ�ܣ�"));
		return -1;          // ����ֵΪ���ʱ���Ǳ�ʾ�ɹ�����WSAStartup  
	}

	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1) {
		// ���������ֽ��ǲ���1�����ֽ��ǲ���1��ȷ���Ƿ������������1.1�汾  
		// ����Ļ�������WSACleanup()�����Ϣ����������  
		WSACleanup();
		return -1;
	}

	// ����socket������������ʽ�׽��֣������׽��ֺ�sockSrv  
	// SOCKET socket(int af, int type, int protocol);  
	// ��һ��������ָ����ַ��(TCP/IPֻ����AF_INET��Ҳ��д��PF_INET)  
	// �ڶ�����ѡ���׽��ֵ�����(��ʽ�׽���)�����������ض���ַ�������Э�飨0Ϊ�Զ���  
	_socket = ::socket(AF_INET, SOCK_STREAM, 0);
	return 0;
}

bool Socket::connect(QString & ip, int port)
{
	_flag = 0;
	SOCKADDR_IN addrSrv;  //����һ��socket��ַ 
	addrSrv.sin_addr.S_un.S_addr = inet_addr(ip.toLocal8Bit().data());      // ���ػ�·��ַ��127.0.0.1;   
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(port);
	int ret = ::connect(_socket, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
	if (ret)
	{
		QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("����ʧ�ܣ�"));
		return false;
	}
	return true;
}

void Socket::bind(int port)
{
	_flag = 1;
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY); // ��INADDR_ANYת��Ϊ�����ֽ��򣬵��� htonl(long��)��htons(����)  
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
		int len = ::send(_connectSocket, buf, strlen(buf) + 1, 0);  // ������ʾ��ӭ��Ϣ  
		return len;
	}
	else
	{
		int len = ::send(_socket, buf, strlen(buf), 0);  // ������ʾ��ӭ��Ϣ  
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
