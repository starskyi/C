#include <Windows.h>

int main(void)
{
	HANDLE hMapping = NULL;

	hMapping = OpenFileMappingA(FILE_MAP_ALL_ACCESS,FALSE,"STAR");

	if (hMapping == NULL)
	{
		//����Mapping����
		hMapping = CreateFileMappingA(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 4, "STAR");
	}
	

	//����ӳ��
	DWORD* number = (DWORD*)MapViewOfFile(hMapping, FILE_MAP_ALL_ACCESS, 0, 0, 4);
	if (*number >= 3)
	{
		MessageBox(0, L"������������ܳ���3��", 0, 0);
		return 0;
	}
	*number += 1;
	system("pause");
	*number -= 1;
	return 0;
}