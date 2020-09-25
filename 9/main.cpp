#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>

typedef ULONGLONG (__fastcall *hashFunc)(PVOID data, PVOID seed, ULONG size);

int wmain(int argc, wchar_t* argv[])
{
	if (argc != 2)
	{
		wprintf(L"[+] p.exe name.dll\n");
		return 1;
	}
	ULONG_PTR pBase = (ULONG_PTR)LoadLibraryW(argv[1]);
	if (pBase = NULL)
	{
		wprintf(L"[+] LoadLibrary failed\n");
		return 1;
	}
	hashFunc pHashFunc = (hashFunc)(pBase + 0x5A2CuLL);
	char password[2];
	password[1] = '\x00';
	char hash[260];
	for (int i = 0; i < 256; ++i)
	{
		password[i] = (char)(i);
		ULONG v4 = pHashFunc(hash, password, 260ull);
	}
	return 0;
}