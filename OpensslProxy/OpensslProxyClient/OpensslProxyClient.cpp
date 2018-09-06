// OpensslProxyClient.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <WinSock2.h>
#include <Windows.h>
#include <openssl\ssl.h>

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "libssl.lib")
#pragma comment(lib, "libcrypto.lib")

int main()
{
	WSADATA		wsaData;
	WORD		wVersionRequested = 0;
	int			iError = 0;
	SSL_CTX		*pstSSlCtx = NULL;
	SSL			*pstSSL = NULL;

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


	/* SSL ���ʼ��*/
	SSL_library_init();
	OPENSSL_malloc_init();
	SSLeay_add_ssl_algorithms();
	OpenSSL_add_all_algorithms();
	SSL_load_error_strings();
	ERR_load_BIO_strings(); 
	
	printf("openSSL1.1.1 info:\n");
	printf("%s\n", SSLeay_version(OPENSSL_VERSION));
	printf("%s\n", SSLeay_version(OPENSSL_CFLAGS));
	printf("%s\n", SSLeay_version(OPENSSL_BUILT_ON));
	printf("%s\n", SSLeay_version(OPENSSL_PLATFORM));
	printf("%s\n", SSLeay_version(OPENSSL_DIR));
	printf("%s\n", SSLeay_version(OPENSSL_ENGINES_DIR));


	/*pstSSlCtx = SSL_CTX_new(TLSv1_2_server_method());
	if (NULL == pstSSlCtx)
	{
		printf("[SSL-Client]: Error-->SSL_CTX_new error!\n");
		return -1;
	}*/


	system("pause");
    return 0;
}

