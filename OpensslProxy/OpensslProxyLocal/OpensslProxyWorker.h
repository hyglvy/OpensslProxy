#pragma once

typedef struct tagWorkerContext
{
	PSOCK_MGR_S				pstArryWorker[MGR_ARRYNUMS];		/*�����߳��������*/
	UINT32							uiWorkerNums;									/*�������̸߳���*/
	CRITICAL_SECTION			stWorkerLock;										/*ͳһ��*/
}WORKER_CTX_S, *PWORKER_CTX_S;




