

// Regmanager.h : RegManager保存动态库路径和控件版本类的声明

// Regmanager : 有关实现的信息，请参阅 Regmanager.cpp
#ifndef __REG_MANAGER_H__
#define __REG_MANAGER_H__

class CRegManager
{
public:
	// 构造函数
	CRegManager();

	// 析构函数
	~CRegManager();

	/// ==============================================
	/// @par 功能 
	/// 初始化注册表并获得键句柄
	/// @param 
	/// [in,out]	<参数名>		<参数说明>
	///	
	/// @return 	-
	/// @note 		Creat By wu.f 2014/08/14 
	/// ==============================================
	BOOL InitData(const char* pszKeyPath);

	/// ==============================================
	/// @par 功能 
	/// 
	/// @param 
	/// [in,out]	<参数名>		<参数说明>
	///	
	/// @return 	-
	/// @note 		Creat By li.xl 2015/05/25 
	/// ==============================================
	BOOL e_CreatHKey();

	/// ==============================================
	/// @par 功能 
	/// 获取当前键的值
	/// @param 
	/// [in,out]	<参数名>		<参数说明>
	/// [in]		pszKeyName		要获取的注册表键值
	/// [in]		strKeyValueRet	返回值
	/// @return 	-
	/// @note 		Creat By wu.f 2014/08/14 
	/// ==============================================
	string GetRegProp(char* pszKeyName);

	/// ==============================================
	/// @par 功能 
	/// 增加一个键值,如果此键值项名称已存在,则修改此值
	/// @param 
	/// [in,out]	<参数名>		<参数说明>
	/// [in]		pszKeyName		待增加的键值	
	/// [in]		pszKeyValue		键值
	/// @return 	-
	/// @note 		Creat By wu.f 2014/08/14 
	/// ==============================================
	BOOL RegSetValue(const char* pszKeyName, const char* pszKeyValue);

	/// ==============================================
	/// @par 功能 
	/// 删除一个键值
	/// @param 
	/// [in,out]	<参数名>		<参数说明>
	/// [in]		pszKeyName		要删除的注册表键值
	/// @return 	-
	/// @note 		Creat By wu.f 2014/08/14 
	/// ==============================================
	BOOL RegDelValue(const char* pszKeyName);

private:
	///  子键路径
	string		m_strKeyPath;
	/// 子键句柄
	HKEY		m_hKey;
};
#endif // __REG_MANAGER_H__
