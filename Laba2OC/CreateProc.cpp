#include <windows.h>
#include <stdio.h>
#include <locale.h>
void main(VOID)
{
    STARTUPINFO StartupInfo;
    PROCESS_INFORMATION ProcInfo;
    TCHAR CommandLine[] = TEXT("Laba2OC");

    setlocale(LC_ALL, "rus_rus.1251");

    ZeroMemory(&StartupInfo, sizeof(StartupInfo));
    StartupInfo.cb = sizeof(StartupInfo);
    ZeroMemory(&ProcInfo, sizeof(ProcInfo));

    printf("�������� ������ �������� ������� � ������� 1000 ��\n");
    Sleep(1000);

    if (!CreateProcess(NULL, // �� ������������ ��� ������ 
        CommandLine,          // ��������� ������
        NULL,                 // ���������� �������� �� �����������. 
        NULL,                 // ���������� ������ �� �����������. 
        FALSE,                // ��������� ���������� ������������
        0,                    // ��� ������ �������� ��������
        NULL,                 // ���� ���������� ��������� ������������� ��������
        NULL,                 // ������������ ������� ������� ������������� ��������
        &StartupInfo,         // ��������� �� ���������  STARTUPINFO.
        &ProcInfo)           // ��������� �� ��������� ���������� � ��������.
        )

        printf("CreateProcess failed.\n");

    // ����� ��������� ��������� ��������
    WaitForSingleObject(ProcInfo.hProcess, INFINITE);

    printf("\n��������� ��������� ��������.\n");

    Sleep(1000);

    // ������� ��������� �������� � ������ 
    CloseHandle(ProcInfo.hProcess);
    CloseHandle(ProcInfo.hThread);
}