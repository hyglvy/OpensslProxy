#pragma once


class  DeviceIoCtrl
{
	public:
		DeviceIoCtrl();
		 virtual ~DeviceIoCtrl();

		 //���ƽӿ�
		 BOOLEAN	OpenDev();
		 void				CloseDev();

		 BOOLEAN	RuleMatchEnable();
		 BOOLEAN	RuleMatchDisable();


	private:
		HANDLE	m_hDev;
		ULONG	m_nErrorCode;
};





