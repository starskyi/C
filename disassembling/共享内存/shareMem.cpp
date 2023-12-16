#include <Windows.h>

int main(void)
{
	HANDLE hMapping = NULL;

	hMapping = OpenFileMappingA(FILE_MAP_ALL_ACCESS,FALSE,"STAR");

	if (hMapping == NULL)
	{
		//创建Mapping对象
		hMapping = CreateFileMappingA(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 4, "STAR");
	}
	

	//建立映射
	DWORD* number = (DWORD*)MapViewOfFile(hMapping, FILE_MAP_ALL_ACCESS, 0, 0, 4);
	if (*number >= 3)
	{
		MessageBox(0, L"程序打开数量不能超过3个", 0, 0);
		return 0;
	}
	*number += 1;
	system("pause");
	*number -= 1;
	return 0;
}