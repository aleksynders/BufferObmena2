#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
LPWSTR ClipboardOutputText();

LPWSTR a = "";

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR pCmdLine, int nCmdShow)
{
	system("chcp 1251>null");
	while (TRUE)
	{
		LPWSTR Data = ClipboardOutputText();
		DWORD len;
		len = wcslen(Data);
		int kol = 0;
		for (int i = 0; i < 2 * len; i++)
		{
			if (Data[i] == 48)
			{
				kol += 4;
			}
			if (Data[i] == 49)
			{
				kol += 4;
			}
			else if (Data[i] == 50)
			{
				kol += 3;
			}
			else if (Data[i] == 51)
			{
				kol += 3;
			}
			else if (Data[i] == 52)
			{
				kol += 6;
			}
			else if (Data[i] == 53)
			{
				kol += 4;
			}
			else if (Data[i] == 54)
			{
				kol += 5;
			}
			else if (Data[i] == 55)
			{
				kol += 4;
			}
			else if (Data[i] == 56)
			{
				kol += 6;
			}
			else if (Data[i] == 57)
			{
				kol += 6;
			}
			else
			{
				kol++;
			}
		}
		LPWSTR str = calloc(kol, sizeof(LPSTR));
		int j = 0;
		for (int i = 0; i < 2 * len; i++)
		{
			if (Data[i] == 48)
			{
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
			}
			if (Data[i] == 49)
			{
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
			}
			else if (Data[i] == 50)
			{
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
			}
			else if (Data[i] == 51)
			{
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
			}
			else if (Data[i] == 52)
			{
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
			}
			else if (Data[i] == 53)
			{
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
			}
			else if (Data[i] == 54)
			{
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
			}
			else if (Data[i] == 55)
			{
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
			}
			else if (Data[i] == 56)
			{
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
			}
			else if (Data[i] == 57)
			{
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
				str[j] = L'�';
				j++;
			}
			else
			{
				str[j] = Data[i];
				j++;
			}
		}
		if (strcmp(Data, a) != 0)
		{
			a = str;
			int k = wcslen(str);
			ClicboardInputText(str);
		}
		Sleep(1000);
	}
	return 0;
}

int ClicboardInputText(LPWSTR buffer)
{
	DWORD len;
	HANDLE hMem;
	len = wcslen(buffer) + 1;

	hMem = GlobalAlloc(GMEM_MOVEABLE, len * sizeof(LPWSTR));
	memcpy(GlobalLock(hMem), buffer, len * sizeof(LPWSTR));
	GlobalUnlock(hMem);
	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(CF_UNICODETEXT, hMem);
	CloseClipboard();
	return 0;
}

TCHAR* ClipboardOutputText()
{
	LPWSTR Mess = NULL;
	OpenClipboard(NULL);
	HANDLE hClipboardData = GetClipboardData(CF_UNICODETEXT);
	Mess = (LPWSTR)GlobalLock(hClipboardData);
	GlobalUnlock(hClipboardData);
	CloseClipboard();
	EmptyClipboard();
	return Mess;
}