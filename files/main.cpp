#include <string>

#include "TranslitClass.h"
#include "WriteClipboardClass.h"
#include "TextFromClipboardClass.h"


std::string _text_from_Buffer{};// строка из буфера обмена со всем скопированным текстом


int main()
{
	std::locale::global(std::locale("RU"));
	system("chcp 65001");

	TextFromClipboardClass::TextFromClipboardVoid();//ФУНКЦИЯ КОПИРОВАНИЯ ИЗ БУФЕР ОБМЕНА В ГЛОБАЛЬНУЮ ПЕРЕМЕННУЮ text_from_Buffer

	WriteClipboardClass::WriteClipboardVoid(); // text_from_Buffer - глобальная переменная
};

