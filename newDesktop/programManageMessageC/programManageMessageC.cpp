// programManageMessageC.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <tchar.h>
LRESULT Hookproc(
	int code,
	WPARAM wParam,
	LPARAM lParam
)
{
	std::cout << wParam<<""<< lParam<<std::endl;
	return CallNextHookEx(nullptr, code, wParam, lParam);
}
int main()
{
	HWND windowHandle = FindWindow(_T("SysListView32"), _T("FolderView"));
	std::cout << "窗口句柄" << windowHandle << std::endl;
	DWORD ProcessID;
	DWORD ThreadID= GetWindowThreadProcessId(windowHandle, &ProcessID);
	//HINSTANCE
	std::cout << "进程ID" << ProcessID << std::endl;
	std::cout << "线程ID" << ProcessID << std::endl;
	HHOOK hookid=SetWindowsHookEx(WH_CALLWNDPROC, Hookproc, nullptr, ThreadID);
	if (hookid)
	{

	}
	std::cout << "线程ID" << hookid << std::endl;
}