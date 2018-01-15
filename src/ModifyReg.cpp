// ModifyReg.cpp : 定义控制台应用程序的入口点。
//

#include "Common/CommTypes.h"
#include "RegManager.h"


#define REG_ROOT_PATH "SOFTWARE\\FWAY\\FMCPCTI\\Server\\"

int main(int argc, char* argv[])
{

	CRegManager RegManger;

	BOOL bRet = RegManger.InitData(REG_ROOT_PATH);

	if(FALSE == bRet)
	{
		bRet = RegManger.e_CreatHKey();
	}

	if (TRUE == bRet)
	{
		string strTemp = RegManger.GetRegProp("IP");
		strTemp = RegManger.GetRegProp("Port");
		strTemp = RegManger.GetRegProp("Database");
	}

	printf("Success ---------------------\r\n");

	getchar();

	return 0;
}

