#include "CPeUtil.h"
#include <iostream>
int main(void)
{
	CPeUtil pe;
	//BOOL isSuccess = pe.loadFile("D:\\code\\C\\disassembling\\DLL\\mydll1\\Debug\\mydll1.dll");
	BOOL isSuccess = pe.loadFile("D:\\code\\C\\Demo\\��������\\Debug\\��������.exe");
	if (!isSuccess)
	{
		printf("����ʧ��\n");
		return 0;
	}
	//pe.printSectionHeaders();
	//pe.GetImportTable();
	pe.GetRelocation();
	
}