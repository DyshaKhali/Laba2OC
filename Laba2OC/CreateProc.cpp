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

    printf("Работает только основной процесс в течение 1000 мс\n");
    Sleep(1000);

    if (!CreateProcess(NULL, // Не используется имя модуля 
        CommandLine,          // Командная строка
        NULL,                 // Дескриптор процесса не наследуется. 
        NULL,                 // Дескриптор потока не наследуется. 
        FALSE,                // Установка описателей наследования
        0,                    // Нет флагов создания процесса
        NULL,                 // Блок переменных окружения родительского процесса
        NULL,                 // Использовать текущий каталог родительского процесса
        &StartupInfo,         // Указатель на структуру  STARTUPINFO.
        &ProcInfo)           // Указатель на структуру информации о процессе.
        )

        printf("CreateProcess failed.\n");

    // Ждать окончания дочернего процесса
    WaitForSingleObject(ProcInfo.hProcess, INFINITE);

    printf("\nОкончание дочернего процесса.\n");

    Sleep(1000);

    // Закрыть описатели процесса и потока 
    CloseHandle(ProcInfo.hProcess);
    CloseHandle(ProcInfo.hThread);
}