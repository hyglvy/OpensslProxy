// OpensslProxyClient.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <openssl\ssl.h>

#pragma comment(lib, "libssl.lib")
#pragma comment(lib, "libcrypto.lib")

int main()
{
	WSADATA    wsaData;
	WORD	         wVersionRequested = 0;
	int                 iError = 0;
	SSL_CTX		*pstSSlCtx = NULL;
	SSL				*pstSSL = NULL;




	/*��ʼ��winsock32����*/
	wVersionRequested = MAKEWORD(2, 2);
	iError = WSAStartup(wVersionRequested, &wsaData);
	if (iError != 0) {
		return NULL;
	}

	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
		WSACleanup();
		return NULL;
	}

    return 0;
}

