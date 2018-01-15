
#include "Common/CommTypes.h"
#include "RegManager.h"


CRegManager::CRegManager():
	m_hKey(NULL)
{

}

CRegManager::~CRegManager()
{
	if(NULL != m_hKey)
	{
		RegCloseKey(m_hKey);
	}
}

BOOL CRegManager::InitData(const char* pszKeyPath)
{
	BOOL bRet = FALSE;

	if(NULL != m_hKey)
	{
		RegCloseKey(m_hKey);
	}
	/// 赋值路径
	m_strKeyPath = pszKeyPath;
	if(ERROR_SUCCESS == RegOpenKeyEx(HKEY_CURRENT_USER, m_strKeyPath.c_str(),
		0, KEY_WRITE | KEY_READ, &m_hKey))
	{
		printf("Get Key ....\r\n");
		bRet = TRUE;
	}
	return bRet;
}

BOOL CRegManager::e_CreatHKey()
{
	BOOL bRet = FALSE;

	if(ERROR_SUCCESS != RegCreateKey(HKEY_CURRENT_USER, m_strKeyPath.c_str(), &m_hKey))
	{
		m_hKey = NULL;
	}
	else
	{
		if(ERROR_SUCCESS != RegOpenKeyEx(HKEY_CURRENT_USER, m_strKeyPath.c_str(),
			0, KEY_WRITE | KEY_READ, &m_hKey))
		{
			m_hKey = NULL;
		}
		else
		{
			printf("Get Key ....\r\n");

			bRet = TRUE;
		}
	}

	return bRet;
}

string CRegManager::GetRegProp(char* pszKeyName)
{
	string strKeyValueRet = "";
	DWORD dwMAXLen = MAX_PATH;
	DWORD dwDataLength = MAX_PATH;
	DWORD dwType = REG_NONE;
	char szKeyValue[MAX_PATH + 1];
	memset(szKeyValue, 0x00, sizeof(szKeyValue));
	if(NULL == m_hKey)
	{
		return strKeyValueRet;
	}
	// 从注册表读取相应的键值
	if(ERROR_SUCCESS == RegQueryValueEx(m_hKey, pszKeyName, NULL, 
		&dwType, (BYTE* )szKeyValue, &dwDataLength))
	{
		strKeyValueRet = szKeyValue;
	}
	return strKeyValueRet;
}

BOOL CRegManager::RegSetValue(const char* pszKeyName, const char* pszKeyValue)
{
	BOOL bRet = FALSE;
	if(NULL == m_hKey || NULL == pszKeyName || NULL == pszKeyValue)
	{
		return bRet;
	}

	if(ERROR_SUCCESS == RegSetValueEx(m_hKey, pszKeyName, 0, REG_SZ, 
		(const unsigned char*)pszKeyValue, strlen(pszKeyValue)))
	{
		bRet = TRUE;
	}
	return bRet;
}

BOOL CRegManager::RegDelValue(const char* pszKeyName)
{
	BOOL bRet = FALSE;
	if(NULL == m_hKey)
	{
		return bRet;
	}
	
	if(ERROR_SUCCESS == RegDeleteValue(m_hKey, pszKeyName))
	{
		bRet = TRUE;
	}

	return bRet;
}

