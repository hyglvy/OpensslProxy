#pragma once


/*�����ı��ص�socket��Ϣ*/
typedef struct tagLocalSockInfo
{
	SOCKET			sLocalFD;					/*���ص�Socket��Ϣ*/
	SOCKADDR		stLocalInfo;				/*���ص�Socket��Ϣ*/
}CLIENT_INFO_S, *PCLIENT_INFO_S;

/*����ת��������: TODO: ������һЩ���˵Ĳ���*/
typedef struct tagDispatchPackContext
{
	CLIENT_INFO_S	stClientInfo;			/*�µĿͻ���������Ϣ*/
	ULONG				ulBlanceAlgm;		/*�ַ��ľ����㷨*/
}DISPATCHPACK_CTX_S, *PDISPATCHPACK_CTX_S;





