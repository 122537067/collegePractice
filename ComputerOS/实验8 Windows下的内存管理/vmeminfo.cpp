// ����vmeminfo
#include <windows.h> // ʹ����windows API
#include <iostream> // ʹ���˱�׼�����
#include <shlwapi.h>  // ʹ����StrFormatByteSize
#include <iomanip> // ʹ����io����
using namespace std;
#pragma comment(lib, "shlwapi.lib") // ���ӿ�shlwapi.lib

void main()
{
    // ���ȣ������ǻ��ϵͳ��Ϣ
    SYSTEM_INFO si;					// SYSTEM_INFO�ṹ������˼����ϵͳ�����Ϣ
    ZeroMemory(&si, sizeof(si) );	// ���ṹ������
    GetSystemInfo(&si);				// ��ȡ��ǰϵͳ��Ϣ
	cout << si.dwPageSize << endl;

    // ʹ����Ǹ��������һЩ�ߴ���и�ʽ��
    TCHAR szPageSize[MAX_PATH];	// �ַ��������ڱ���ҳ���С���˴��ַ���������ʵ�����·������(MAX_PATH)û�й�ϵ
    StrFormatByteSize(si.dwPageSize, szPageSize, MAX_PATH);	// ��ҳ���ֽ���(si.dwPageSize)ת�����ַ�������szPageSize
   cout << "�����ڴ�ҳ���С: " << szPageSize << endl;
	
	DWORD dwMemSize = (DWORD)si.lpMaximumApplicationAddress -
          (DWORD) si.lpMinimumApplicationAddress;			// ������̿ɷ��ʵ������ַ�ռ��С
    TCHAR szMemSize [MAX_PATH];	// �ַ��������ڱ��������ַ�ռ��С���˴��ַ���������ʵ�����·������(MAX_PATH)û�й�ϵ
    StrFormatByteSize(dwMemSize, szMemSize, MAX_PATH);		// �������ַ�ռ��С(dwMemSize)ת�����ַ�������szMemSize

    // ���ڴ���Ϣ��ʾ����
    
    cout.fill ('0') ;										// ������ַ����ó�'0'
    cout << "��СӦ�ó����ַ: 0x"
            << hex << setw(8)								// ʹ��ʮ������(hex)��������Ϊ8�ַ�
            << (DWORD) si.lpMinimumApplicationAddress
            << endl;
    cout << "���Ӧ�ó����ַ: 0x"
            << hex << setw(8)
            << (DWORD) si.lpMaximumApplicationAddress
            << endl;
    cout << "�ܹ����õ������ڴ�: "
		<< szMemSize << endl ;

	TCHAR szGranunality[MAX_PATH];
	StrFormatByteSize(si.dwAllocationGranularity, szGranunality, MAX_PATH);
	cout << "�ڴ�������ȣ�" << szGranunality << endl;
	cout << "��������" << si.dwNumberOfProcessors << endl;
}

