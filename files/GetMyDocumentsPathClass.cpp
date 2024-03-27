#include <string>
#include <Windows.h>
#include <shlobj.h>

#include "Utf16ToUtf8_Class.h"
#include "GetMyDocumentsPathClass.h"


wchar_t myDocumentsPathUtf16[MAX_PATH] = { };

std::string myDocumentsPathUtf8{};


void GetMyDocumentsPathClass::GetMyDocumentsPathVoid() {
	HRESULT result = SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, myDocumentsPathUtf16);
	std::string temp = (Utf16ToUtf8_Class::Utf16ToUtf8_Void(myDocumentsPathUtf16));
	myDocumentsPathUtf8 = temp + "\\ansiSlovar.txt";
};

