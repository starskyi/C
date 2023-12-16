#include <Windows.h>
#include <iostream>

int main(void)
{
	setlocale(LC_ALL, "chs");

	//1.ɾ���ļ�
	//DeleteFile(L"D://13.txt");

	//2.�����ļ�
	//CopyFile(L"D://a.txt", L"D://b.txt", TRUE);

	//3.�ƶ��ļ�
	//MoveFile(L"D://a.txt", L"D://c.txt");

	//4.�����ļ�
	/*HANDLE hFile = CreateFile(L"D://d.txt", GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);*/
	//д���ļ�
	//WriteFile(hFile, "Hello World", sizeof("Hello World"), NULL, NULL);

	WIN32_FIND_DATA fileData{ 0 };
	HANDLE hFile = FindFirstFile(L"D://tmp//*", &fileData);

	if (hFile != INVALID_HANDLE_VALUE) {

		FILETIME fileTime{ 0 };
		SYSTEMTIME systemTime{ 0 };

		FileTimeToLocalFileTime(&fileData.ftCreationTime, &fileTime);
		FileTimeToSystemTime(&fileTime, &systemTime);
		do {
			printf("%ls %d/%d/%d", fileData.cFileName, systemTime.wYear, systemTime.wMonth, systemTime.wDay);
			if (fileData.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN) {
				printf("�Ƿ�����:��\n");
			}
			else {
				printf("�Ƿ�����:��\n");
			}

		} while (FindNextFile(hFile, &fileData));
		FindClose(hFile);
	}

	return 0;
}