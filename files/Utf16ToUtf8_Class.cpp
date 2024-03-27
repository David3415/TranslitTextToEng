#include "Utf16ToUtf8_Class.h"

std::string Utf16ToUtf8_Class::Utf16ToUtf8_Void(const std::wstring utf16String) {

	std::string utf8String{};

	const wchar_t* utf16Char = &utf16String[0];
	size_t _size = (wcslen(utf16Char) + 1) * sizeof(wchar_t);

	char* pUtf8String = new char[_size];
	size_t convertedSize = 0;
	size_t _count{};

	wcstombs_s(&convertedSize, pUtf8String, _size, utf16Char, _size);

	return pUtf8String;
};


