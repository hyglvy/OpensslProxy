
/*���ֿ����������ͷ��*/
#define		IOBUF_MAXSIZE			16384+1024

typedef struct tagCommIoBuf
{
	LIST_ENTRY						stNode;
	UCHAR								acBuf[IOBUF_MAXSIZE];					/*�ڴ��С*/
	UINT32							uiBufSize;											/*Ͷ�ݵ��ڴ��С*/
	UINT32							uiDatalen;										/*���ݳ���*/
}COM_IOBUF, *PCOM_IOBUF;


COM_IOBUF* COMM_IOBUF_Create();

VOID COMM_IOBUF_Free(COM_IOBUF* pstIoBuf);

