

// Regmanager.h : RegManager���涯̬��·���Ϳؼ��汾�������

// Regmanager : �й�ʵ�ֵ���Ϣ������� Regmanager.cpp
#ifndef __REG_MANAGER_H__
#define __REG_MANAGER_H__

class CRegManager
{
public:
	// ���캯��
	CRegManager();

	// ��������
	~CRegManager();

	/// ==============================================
	/// @par ���� 
	/// ��ʼ��ע�����ü����
	/// @param 
	/// [in,out]	<������>		<����˵��>
	///	
	/// @return 	-
	/// @note 		Creat By wu.f 2014/08/14 
	/// ==============================================
	BOOL InitData(const char* pszKeyPath);

	/// ==============================================
	/// @par ���� 
	/// 
	/// @param 
	/// [in,out]	<������>		<����˵��>
	///	
	/// @return 	-
	/// @note 		Creat By li.xl 2015/05/25 
	/// ==============================================
	BOOL e_CreatHKey();

	/// ==============================================
	/// @par ���� 
	/// ��ȡ��ǰ����ֵ
	/// @param 
	/// [in,out]	<������>		<����˵��>
	/// [in]		pszKeyName		Ҫ��ȡ��ע����ֵ
	/// [in]		strKeyValueRet	����ֵ
	/// @return 	-
	/// @note 		Creat By wu.f 2014/08/14 
	/// ==============================================
	string GetRegProp(char* pszKeyName);

	/// ==============================================
	/// @par ���� 
	/// ����һ����ֵ,����˼�ֵ�������Ѵ���,���޸Ĵ�ֵ
	/// @param 
	/// [in,out]	<������>		<����˵��>
	/// [in]		pszKeyName		�����ӵļ�ֵ	
	/// [in]		pszKeyValue		��ֵ
	/// @return 	-
	/// @note 		Creat By wu.f 2014/08/14 
	/// ==============================================
	BOOL RegSetValue(const char* pszKeyName, const char* pszKeyValue);

	/// ==============================================
	/// @par ���� 
	/// ɾ��һ����ֵ
	/// @param 
	/// [in,out]	<������>		<����˵��>
	/// [in]		pszKeyName		Ҫɾ����ע����ֵ
	/// @return 	-
	/// @note 		Creat By wu.f 2014/08/14 
	/// ==============================================
	BOOL RegDelValue(const char* pszKeyName);

private:
	///  �Ӽ�·��
	string		m_strKeyPath;
	/// �Ӽ����
	HKEY		m_hKey;
};
#endif // __REG_MANAGER_H__
