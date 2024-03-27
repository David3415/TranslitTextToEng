#include "Utf8ToUtf16_Class.h"
#include <windows.h>

wchar_t* Utf8ToUtf16_Class::Utf8ToUtf16(const char* utf8Text) {
    int len = MultiByteToWideChar(CP_UTF8, 0, utf8Text, -1, nullptr, 0);
    /*if (len == 0) {
        return nullptr;
    }*/

    wchar_t* utf16Text = new wchar_t[len];
    MultiByteToWideChar(CP_UTF8, 0, utf8Text, -1, utf16Text, len);

    return utf16Text;
}
