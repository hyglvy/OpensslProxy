
/*ͨ������ķ�ʽ���й���*/
/*��Worker��Handler��WSAEvent�У�����Ҫʹ��*/
typedef struct tagSockInfo
{
	LIST_ENTRY		stNode;					/*�ڵ�*/
	SOCKET			sSockfd;					/*��Socket�¼�FD*/
	HANDLE			hEvtHandle;				/*�¼����*/
	ULONG			ulEvtsIndex;				/*���ڵ�Evts����������*/
	LIST_ENTRY		stIoBufList;				/*��˳������: ���������ݰ��Ϳ��ư��������ţ��������ӱ���Ĵ���һ����*/
}SOCKINFO_S, *PSOCKINFO_S;

/*WSAEvent�̵߳�socket��������Worker��Handler����ʹ��*/
/*ÿ���̶߳��иù�����*/
typedef struct tagSocketMgr
{
	UINT32			uiMgrIndex;											/*���ڹ�������������, ��ԭ�����߳�ʱ����Ҫ*/
	SOCKET			sMsgFd;												/*ͨ�ŵ�FD, ֱ����UDPͨ��, ������������Ϣ���̼߳�ͨ��*/
	LIST_ENTRY		stSockList;											/*��ǰ��socket��Ϣ����*/
	ULONG			ulSockNums;										/*��ǰ��û�г���64-4���Ϳ�����, һ������ͨ����, Ȼ�󱣳ֳɶ�*/
	WSAEVENT		arrWSAEvts[WSAEVT_NUMS];				/*��ǰ��socket�¼�����*/
	SOCKET			arrSocketEvts[WSAEVT_NUMS];			/*�¼���Ӧ��socket����*/
}SOCK_MGR_S, *PSOCK_MGR_S;


