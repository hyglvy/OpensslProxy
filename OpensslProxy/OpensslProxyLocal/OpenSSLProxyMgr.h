#pragma once


/*�����Ĺ�����*/
typedef struct tagMgrContext
{
	PWORKER_CTX_S				pstWorkerCtx;				/*�����̹߳���������*/
	PDISPATCHPACK_CTX_S		pstDispatchPackCtx;	/*�������߳�*/
	PHANDLER_CTX_S				pstHandlerCtx;				/*�����̹߳���������*/
}MGR_CTX_S, *PMGR_CTX_S;


INT32 OpenSSLProxy_MgrInit();

VOID OpenSSLProxy_MgrUnInit();

