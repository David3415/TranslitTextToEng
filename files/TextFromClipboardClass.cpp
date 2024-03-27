#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS

#include <locale.h>
#include <strstream>

#include "TextFromClipboardClass.h"

extern std::string _text_from_Buffer;

void TextFromClipboardClass::TextFromClipboardVoid() {
	setlocale(LC_ALL, "rus");
	std::string StrFromClipboard;
	if (OpenClipboard(NULL))
	{
		HANDLE hData = GetClipboardData(CF_TEXT);
		char* chBuffer = (char*)GlobalLock(hData);
		int str_counter = 49;

		if (chBuffer != NULL) {
			std::istrstream cboard(chBuffer);
			while (!cboard.eof()) {
				getline(cboard, StrFromClipboard);
				if (StrFromClipboard.empty()) { continue; }
				_text_from_Buffer += StrFromClipboard;
				str_counter++;
			}
		}
		GlobalUnlock(hData);//разблокируем память
		CloseClipboard();//закрываем буфер обмена
	};
};