#include <Windows.h>

int main(void)
{
	//创建文件句柄
	HANDLE hFile = CreateFileA(
		"test.txt",
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ,
		NULL,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		0
	);

	//创建Mapping对消
	HANDLE hMapping = CreateFileMappingA(hFile, NULL, PAGE_READWRITE, 0, GetFileSize(hFile, 0), NULL);

	//建立映射
	char *fileBuff = (char*)MapViewOfFile(hMapping, FILE_MAP_ALL_ACCESS, 0, 0, 0);
	return 0;
}