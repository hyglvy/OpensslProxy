#pragma once

typedef struct tagResourceLock
{
	ERESOURCE					stLockResource;					//��Դ��
	KSPIN_LOCK				stLockKSpin;						//irql̫��ʱʹ��
}RESOURCE_LOCK_S, *PRESOURCE_LOCK_S;


VOID	LocalHostIPStringToSockAddr(IN_ADDR *pstInAddr);

VOID	OpenSSLProxy_ResourceLock(PRESOURCE_LOCK_S pLock, PKIRQL OldIrql);

VOID	OpenSSLProxy_ResourceUnLock(PRESOURCE_LOCK_S pLock, KIRQL OldIrql);

