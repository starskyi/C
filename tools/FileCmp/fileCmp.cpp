#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>
int main(void)
{
	DWORD count = 0;
	char fileName1[100] = "unpack1_.exe";
	char fileName2[100] = "uppack_.exe";

	HANDLE hFile1 = CreateFileA(fileName1, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	HANDLE hFile2 = CreateFileA(fileName2, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	DWORD size1 = GetFileSize(hFile1, 0);
	DWORD size2 = GetFileSize(hFile2, 0);

	unsigned char *file1 = new unsigned char[size1];
	unsigned char* file2 = new unsigned char[size2];
	DWORD realRead = 0;
	BOOL flag1 = ReadFile(hFile1, file1, size1, &realRead, NULL);
	BOOL flag2 = ReadFile(hFile2, file2, size2, &realRead, NULL);

	if (!flag1 || !flag2)
	{
		MessageBoxA(0, "文件打开失败", "error", MB_OK);
		delete[] file1;
		delete[] file2;
		return 0;
	}
	/*FILE *fp1 = fopen(fileName1, "rb");
	FILE* fp2 = fopen(fileName2, "rb");*/
	
	for (DWORD i = 0; i < size1; i++)
	{
		if (file1[i] != file2[i])
		{
			printf("%0.8X\t%0.2X %0.2X\n", i, file1[i], file2[i]);
			count++;
		}
	}
	printf("\ntotal %d\n", count);
	delete[] file1;
	delete[] file2;
	return 0;
}