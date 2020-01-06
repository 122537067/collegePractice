// 工程vmeminfo
#include <windows.h> // 使用了windows API
#include <iostream> // 使用了标准输出流
#include <shlwapi.h>  // 使用了StrFormatByteSize
#include <iomanip> // 使用了io控制
using namespace std;
#pragma comment(lib, "shlwapi.lib") // 链接库shlwapi.lib

void main()
{
    // 首先，让我们获得系统信息
    SYSTEM_INFO si;					// SYSTEM_INFO结构体包含了计算机系统相关信息
    ZeroMemory(&si, sizeof(si) );	// 将结构体清零
    GetSystemInfo(&si);				// 获取当前系统信息
	cout << si.dwPageSize << endl;

    // 使用外壳辅助程序对一些尺寸进行格式化
    TCHAR szPageSize[MAX_PATH];	// 字符串，用于保存页面大小，此处字符串长度其实和最大路径长度(MAX_PATH)没有关系
    StrFormatByteSize(si.dwPageSize, szPageSize, MAX_PATH);	// 将页面字节数(si.dwPageSize)转换成字符串存于szPageSize
   cout << "虚拟内存页面大小: " << szPageSize << endl;
	
	DWORD dwMemSize = (DWORD)si.lpMaximumApplicationAddress -
          (DWORD) si.lpMinimumApplicationAddress;			// 计算进程可访问的虚拟地址空间大小
    TCHAR szMemSize [MAX_PATH];	// 字符串，用于保存虚拟地址空间大小，此处字符串长度其实和最大路径长度(MAX_PATH)没有关系
    StrFormatByteSize(dwMemSize, szMemSize, MAX_PATH);		// 将虚拟地址空间大小(dwMemSize)转换成字符串存于szMemSize

    // 将内存信息显示出来
    
    cout.fill ('0') ;										// 将填充字符设置成'0'
    cout << "最小应用程序地址: 0x"
            << hex << setw(8)								// 使用十六进制(hex)，输出宽度为8字符
            << (DWORD) si.lpMinimumApplicationAddress
            << endl;
    cout << "最大应用程序地址: 0x"
            << hex << setw(8)
            << (DWORD) si.lpMaximumApplicationAddress
            << endl;
    cout << "总共可用的虚拟内存: "
		<< szMemSize << endl ;

	TCHAR szGranunality[MAX_PATH];
	StrFormatByteSize(si.dwAllocationGranularity, szGranunality, MAX_PATH);
	cout << "内存分配粒度：" << szGranunality << endl;
	cout << "核心数：" << si.dwNumberOfProcessors << endl;
}

