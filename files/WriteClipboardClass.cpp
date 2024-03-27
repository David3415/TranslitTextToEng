#include <iostream>
#include <windows.h>
#include <memory> // для std::unique_ptr

#include "WriteClipboardClass.h"
#include "Utf8ToUtf16_Class.h"
#include "TranslitClass.h"
#include "GetMyDocumentsPathClass.h" // для std::unique_ptr
#include "Utf16ToUtf8_Class.h" // для std::unique_ptr

extern std::string myDocumentsPathUtf8;
extern std::string _text_from_Buffer;

void WriteClipboardClass::WriteClipboardVoid() {
	GetMyDocumentsPathClass::GetMyDocumentsPathVoid();
	TranslitClass translitClass;

	std::string translitedText = translitClass.TranslitVoid(_text_from_Buffer, myDocumentsPathUtf8);

	if (translitedText.empty()) {
		std::cerr << "Ошибка: транслитерация не удалась." << std::endl;
	}

	// Использование умного указателя для обеспечения безопасности исключений
	std::unique_ptr<wchar_t[]> p_translitedText(Utf8ToUtf16_Class::Utf8ToUtf16(translitedText.c_str()));

	if (OpenClipboard(NULL)) {
		EmptyClipboard();

		int bufferSize = lstrlenW(p_translitedText.get()) + 1;
		bufferSize = (bufferSize < 1000) ? bufferSize : 2000;

		HGLOBAL hMemory = GlobalAlloc(GMEM_MOVEABLE, static_cast<SIZE_T>(bufferSize * sizeof(wchar_t) + 2));
		LPWSTR pData = static_cast<LPWSTR>(GlobalLock(hMemory));

		if (pData != NULL) {
			wcsncpy_s(pData, bufferSize, p_translitedText.get(), _TRUNCATE);
			pData[bufferSize - 1] = L'\0';

			GlobalUnlock(hMemory);
			SetClipboardData(CF_UNICODETEXT, hMemory);
		}

		CloseClipboard();
	}

};


