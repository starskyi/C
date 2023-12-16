#include <Windows.h>

void _declspec(naked) shellcode1()
{
	//LoadLibraryA 4C 6F 61 64 4C 69 62 72 61 72 79 41 00  长度:0XD
	//GetProcAddress 47 65 74 50 72 6F 63 41 64 64 72 65 73 73 00 长度:0XF
	//user32.dll 75 73 65 72 33 32 2E 64 6C 6C 00 长度:0XB
	//MessageBoxA 4D 65 73 73 61 67 65 42 6F 78 41 00 长度:0XC
	//Hello World 48 65 6C 6C 6F 20 57 6F 72 6C 64 00 长度:0XC
	_asm
	{
		pushad
		sub esp,0x30
		push 0x646C72
		push 0x6F57206F
		push 0x6C6C6548		//Hello World
		push 0x41786F
		push 0x42656761
		push 0x7373654D		//MessageBoxA
		push 0x6C6C
		push 0x642E3233
		push 0x72657375		//user32.dll
		push 0x7373
		push 0x65726464
		push 0x41636F72
		push 0x50746547		//GetProcAddress
		push 0x0
		push 0x41797261
		push 0x7262694C
		push 0x64616F4C		//LoadLibraryA
		call fun_payload
		add esp,0x44
		add esp,0x30
		popad
		ret

		//获取模块基址
	fun_GetModule:
		push ebp
		mov ebp,esp
		sub esp,0xc
		push esi
		mov esi,dword ptr fs:[0x30]		//PEB指针
		mov esi,[esi+0xc]	//LDR指针
		mov esi,[esi+0x1c]	//List
		mov esi,[esi]	//list第二项 kernel32
		mov esi,[esi+0x8]	//dllbase
		mov eax,esi
		mov esp,ebp
		pop ebp
		ret
	fun_GetProcAddress:
		push ebp
		mov ebp,esp
		sub esp,0x10
		push esi
		push edi
		push edx
		push ebx
		push ecx
		mov edx,[ebp+0x8] //dllbase
		mov esi,[edx+0x3c] //lf_anew
		lea esi,[edx+esi] //NT头
		mov esi,[esi+0x78] //导出表RVA
		lea esi,[edx+esi] //导出表VA
		mov edi,[esi+0x1C] //EAT RVA
		lea edi,[edx+edi] //EAT VA
		mov [ebp-0x4],edi
		mov edi,[esi+0x20] //ENT RVA
		lea edi,[edx+edi] //ENT VA
		mov [ebp-0x8],edi
		mov edi,[esi+0x24] //EOT RVA
		lea edi,[edx+edi] //EOT VA
		mov [ebp-0xC],edi
		mov eax, 0x0
		cld //将DF标志位清零(0 执行一次esi,edi加4；1 减4)
		jmp flag1
	cmpstr:
		//比较字符窜，找到相应函数地址
		inc eax
	flag1:
		mov esi,[ebp-0x8]
		mov esi,[esi+eax*4]
		lea esi,[edx+esi] //字符串1首地址
		mov edi,[ebp+0xC] //字符串2首地址 参数2
		mov ecx,[ebp+0x10] //循环次数(字符串长度) 参数3
		repe cmpsb
		jne cmpstr
		mov esi,[ebp-0xC]
		xor edi,edi
		mov di,[esi+2*eax] //对应函数地址的索引(两个字节)
		mov esi,[ebp-0x4]
		mov esi,[esi+edi*4]
		lea eax,[edx+esi]
		pop ecx
		pop ebx
		pop edx
		pop edi
		pop esi
		mov esp,ebp
		pop ebp
		ret 0xC
	fun_payload:
		push ebp
		mov ebp,esp
		sub esp,0x30
		push ecx
		push ebx
		push edx
		push esi
		push edi
		call fun_GetModule
		mov[ebp - 0x4], eax //dllbase
		//获取LoadLibraryA函数地址
		push 0xD
		lea edx,[ebp+0x8]
		push edx
		push eax
		call fun_GetProcAddress
		mov [ebp-0x8],eax //LoadLibraryA函数地址
		//获取GetProcAddress函数地址
		push 0xF
		lea edx,[ebp+0x18]
		push edx
		mov eax,[ebp-0x4]
		push eax
		call fun_GetProcAddress
		mov [ebp-0xC],eax //GetProcAddress函数地址
		//调用LoadLibraryA获取 user32.dll
		lea edx,[ebp+0x28]
		push edx
		call [ebp-0x8]
		mov [ebp-0x10],eax //user32.dll 基址
		//调用GetProcAddress获取MessageBoxA函数地址
		lea edx,[ebp+0x34]
		push edx
		push [ebp-0x10]
		call [ebp-0xC]
		mov [ebp-0x14],eax //MessageBoxA函数地址
		//调用MessageBoxA显示 Hello World
		push 0
		push 0
		lea edx,[ebp+0x40]
		push edx
		push 0
		call [ebp-0x14]
		pop edi
		pop esi
		pop edx
		pop ebx
		pop ecx
		mov esp,ebp
		pop ebp
		ret
	}
}

int main65(void)
{
	shellcode1();
	return 0;
}