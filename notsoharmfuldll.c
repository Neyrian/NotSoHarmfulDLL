#include <windows.h>
#include <stdio.h>

// Hardcoded Pikabot Mutex
#define MUTEX_NAME "{A77FC435-31B6-4687-902D-24153579C738}"

// Function to check the system's UI language
BOOL CheckSystemLanguage(FILE *fp)
{
    LANGID langID = GetUserDefaultUILanguage(); // Get system language
    fprintf(fp, "[*] Detected Language ID: 0x%X\n", langID);

    if (langID == 0x0419 || langID == 0x0422) // 0x0419 = Russian, 0x0422 = Ukrainian
    {
        fprintf(fp, "Pikabot detected Russian/Ukrainian system language. Exiting...\n");
        return TRUE; // Exit execution
    }

    return FALSE; // Continue execution
}

// Mutex to ensure only one instance is running
BOOL CheckMutex(FILE *fp)
{
    HANDLE hMutex = CreateMutex(NULL, TRUE, MUTEX_NAME);
    if (GetLastError() == ERROR_ALREADY_EXISTS)
    {
        fprintf(fp, "Another instance is already running. Exiting...\n");
        return TRUE; // Exit execution
    }

    return FALSE; // Continue execution
}

// Entry function for rundll32.exe
__declspec(dllexport) void RunNotSoHarmful()
{
    FILE *fp = fopen("output.txt", "a+"); // Open a file for writing
    if (fp == NULL) {
        return; // Handle file opening error
    }
    fprintf(fp,"[*] Running Pikabot Simulation...\n");

    if (CheckSystemLanguage(fp) || CheckMutex(fp))
    {
        return; // Exit if language check or mutex fails
    }

    fprintf(fp,"Pikabot Simulation Running Successfully!\n");
}
