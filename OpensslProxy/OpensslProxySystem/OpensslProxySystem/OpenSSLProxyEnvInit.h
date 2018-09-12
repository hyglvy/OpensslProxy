#pragma once


typedef struct tagEnvContext
{
	IN_ADDR		stLocalSockaddr;		/*���ص�ַ*/
	UINT32		ulLocalProxyPID;		/*���ط���PID*/
	USHORT		usLocalPort;				/*����TCP�˿�*/
	USHORT		Resv;
}ENV_CTX_S, *PENV_CTX_S;


NTSTATUS	OpenSSLProxy_EnvInit();

VOID			OpenSSLProxy_EnvUnInit();

NTSTATUS	OpenSSLProxy_SetLocalProxyInfo(UINT32 uiLocalPid, USHORT usPort);

NTSTATUS	OpenSSLProxy_GetSrcPortRange(UINT32 *puiPortStart, UINT32 *puiPortEnd);

ULONG		OpenSSLProxy_GetLocalProxyPID();

USHORT		OpenSSLProxy_GetLocalProxyPort();

IN_ADDR		*OpenSSLProxy_GetLocalSockaddr();