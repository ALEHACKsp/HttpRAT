#pragma once
#include <iostream>

#include <windows.h>
#include <winhttp.h>

#pragma comment(lib,"Winhttp.lib")

using std::string;
using std::wstring;

//����ÿ�ζ�ȡ���ݵĻ�������С 4KB
#define READ_BUFFER_SIZE		4096

enum REQUEST_TYPE
{
	Get = 0,
	Post,
};

class CWinHttp
{
public:
	CWinHttp();
	virtual ~CWinHttp();
	std::string	Request(LPCWSTR lpUrl, REQUEST_TYPE type, LPCSTR lpPostData = NULL, LPCWSTR lpHeader = NULL);
private:
	BOOL Open();
	VOID Release();
	BOOL Connect(LPCWSTR lpUrl, REQUEST_TYPE type, LPCSTR lpPostData = NULL, LPCWSTR lpHeader = NULL);
	VOID ParseUrlW(LPCWSTR lpUrl, wstring& strHostName, wstring& strPage, WORD& sPort);
	BOOL			m_bHttps;
	HANDLE	m_hInternet;
	HANDLE	m_hConnect;
	HANDLE	m_hRequest;
	INT			m_nConnTimeout;
	INT			m_nSendTimeout;
	INT			m_nRecvTimeout;
	PVOID		m_params;
};

