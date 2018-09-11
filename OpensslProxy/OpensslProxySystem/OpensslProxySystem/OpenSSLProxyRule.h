

/*�������������*/
typedef struct tagRuleMgrContext
{
	RESOURCE_LOCK_S					stResLock;				/*��Դ��*/
	LIST_ENTRY								stRulePortList;			/*0.0.0.0:8080, �����ַ�Ķ˿�ƥ��*/
	LIST_ENTRY								stRuleIPaddrList;		/*10.10.10.1:0, ����˿ڵĵ�ַƥ��*/
	LIST_ENTRY								stRuleIPPortList;		/*��ȫƥ��*/
}RULE_MGR_CTX_S, *PRULE_MGR_CTX_S;

typedef struct tagRuleInfoEntry
{
	LIST_ENTRY		listEntry;
	UINT32			uiRuleIP;
	UINT32			uiRulePort;
}RULE_INFO_ENTRY, *PRULE_INFO_ENTRY;

NTSTATUS	OpenSSLProxy_RuleInit();

VOID			OpenSSLProxy_RuleUnInit();

PRULE_INFO_ENTRY OpenSSLProxy_RuleEntryAllocate(IN UINT32 uiRuleIP, IN USHORT usRulePort);

VOID			OpenSSLProxy_RuleEntryFree(IN PRULE_INFO_ENTRY pRuleEntry);

BOOLEAN	OpenSSLProxy_RuleIsMatch(IN UINT32 uiIPAddr, IN USHORT usPort);



