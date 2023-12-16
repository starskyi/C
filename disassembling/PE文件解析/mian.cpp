#include "CPeUtil.h"
#include <iostream>
int main(void)
{
	CPeUtil pe;
	//BOOL isSuccess = pe.loadFile("D:\\code\\C\\disassembling\\DLL\\mydll1\\Debug\\mydll1.dll");
	BOOL isSuccess = pe.loadFile("D:\\code\\C\\Demo\\导入表测试\\Debug\\导入表测试.exe");
	if (!isSuccess)
	{
		printf("加载失败\n");
		return 0;
	}
	//pe.printSectionHeaders();
	//pe.GetImportTable();
	pe.GetRelocation();
	
}