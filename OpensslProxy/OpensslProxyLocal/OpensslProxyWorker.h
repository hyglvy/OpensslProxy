#pragma once

typedef struct tagWorkerContext
{
	PSOCK_MGR_S				pstArrySockHandler[MGR_ARRYNUMS];		/*�����߳��������*/
	UINT32							uiNums;															/*�������̸߳���*/
}WORKER_CTX_S, *PWORKER_CTX_S;




