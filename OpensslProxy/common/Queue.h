#ifndef _QUEUE_H_
#define _QUEUE_H_

/*����ֱֵ���趨����������Ϊ2000�����ң�ÿ��8K������ʱҲ������16M�ڴ����Ҵ�С��*/
#define		SYS_QUE_NUMS				2000

/*���ν��յ��������������ݴ�С��Ϊ16K, ��Ϊ���ܱ��ؽ��պܿ죬����ת��������
��������ϴ��ļ�������ܻ���ֶ��кĹ�����*/
#define		SYS_QUE_BUF_LEN			16384

#define		SYS_QUE_TYPE_DATA		1		/*������Ϊ������*/
#define		SYS_QUE_TYPE_CTRL		2		/*������Ϊ������*/

typedef struct tagQueNodeHead	NODE_HEAD_S,*PNODE_HEAD_S;

struct tagQueNodeHead
{
	struct tagQueNodeHead *next;
	struct tagQueNodeHead *prev;
};

/*�Զ����޸Ľṹ*/
typedef struct tagUserDataInfo
{
	UINT32		uiType;					/*���������ͣ����ƻ���������*/
	UINT32		uiLength;				/*��ȡ�İ����ݳ���*/
	CHAR			acBuf[SYS_QUE_BUF_LEN];	/*����buf���ȣ����г�ʼ�����Ѿ��̶�����*/
}USER_DATA_INFO_S, *PUSER_DATA_INFO_S;

typedef struct tagQueueEntryNode
{
	NODE_HEAD_S				stHead;			/*����ͷ*/
	USER_DATA_INFO_S		stDataInfo;		/*���ݽṹ*/
}QUE_ENTRY_S, *PQUE_ENTRY_S;

/*�򵥵Ķ��гع���*/
typedef struct tagSysQueue
{
	NODE_HEAD_S					stFreeList;					/*���ж��У����ڻ�ȡ���еĽڵ�*/
	UINT32								uiFreeNums;				/*���ж����еĸ��������ڼ���쳣*/
	NODE_HEAD_S					stUsedList;					/*�Ѿ�ʹ�õĽڵ㣬�����ã�������ڴ�й©��ʹ���껹Ҫ����ȥ*/
	UINT32								uiUsedNums;				/*���м���*/
	CRITICAL_SECTION				stCriticalSection;			/*ͳһ��*/

	SYS_SEM_T							hSemNotify;					/*�ź���֪ͨ*/
}SYS_QUE_S;


#define SYS_QUE_PROTECT(pQueue)			EnterCriticalSection(&pQueue->stCriticalSection)
#define SYS_QUE_UNPROTECT(pQueue)		LeaveCriticalSection(&pQueue->stCriticalSection)

QUE_ENTRY_S* SYS_QueNode_Create();

VOID SYS_QueNode_Free(QUE_ENTRY_S* pstQueNode);

QUE_ENTRY_S* SYS_Queue_FreePop(SYS_QUE_S* pstQueue);

INT32 SYS_Queue_FreePush(SYS_QUE_S* pstQueue, QUE_ENTRY_S*pstNode);

QUE_ENTRY_S* SYS_Queue_UsedPop(SYS_QUE_S* pstQueue);

INT32 SYS_Queue_UsedPush(SYS_QUE_S* pstQueue, QUE_ENTRY_S*pstNode);

SYS_QUE_S* SYS_Queue_Create(ULONG ulQueNums);

VOID  SYS_Queue_Free(SYS_QUE_S*pstQueue);

INT32 SYS_Queue_UsedListWaitfor(SYS_QUE_S *pstQueue);

#endif