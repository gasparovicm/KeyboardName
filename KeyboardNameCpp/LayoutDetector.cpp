#include "LayoutDetector.h"
#include <Windows.h>
#include <string>

std::string LayoutDetector::GetActiveLayoutName()
{
    HWND hWnd = GetForegroundWindow();
    DWORD threadId = GetWindowThreadProcessId(hWnd, NULL);
    HKL hkl = GetKeyboardLayout(threadId);

    // Extract the language ID from the handle
    UINT langId = LOWORD((UINT_PTR)hkl);
    std::string keyboardName;
    if (langId == 1051)
    {
        keyboardName = "Slovak";
        if ((UINT_PTR)hkl == 0xfffffffff013041bULL)
        {
            keyboardName += " (QWERTY)";
        }
        else
        {
            if ((UINT_PTR)hkl == 0x00000000041b041bULL)
            {
                keyboardName += " (QWERTZ)";
            }
            else
            {
                keyboardName += " (Slovak)";
            }
        }
    }
    else
    {
        // Use Windows API to get the localized display name
        WCHAR buffer[LOCALE_NAME_MAX_LENGTH];
        if (GetLocaleInfo(MAKELCID(langId, SORT_DEFAULT), LOCALE_SLOCALIZEDDISPLAYNAME, buffer, LOCALE_NAME_MAX_LENGTH))
        {
            // Convert wide string to UTF-8 string
            int len = WideCharToMultiByte(CP_UTF8, 0, buffer, -1, NULL, 0, NULL, NULL);
            std::string str(len - 1, 0); // -1 to exclude null terminator
            WideCharToMultiByte(CP_UTF8, 0, buffer, -1, &str[0], len, NULL, NULL);
            keyboardName = str;
        }
        else
        {
            keyboardName = "Unknown";
        }
    }

    return keyboardName;
}