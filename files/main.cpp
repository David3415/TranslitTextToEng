#include <string>

#include "TranslitClass.h"
#include "WriteClipboardClass.h"
#include "TextFromClipboardClass.h"


std::string _text_from_Buffer{};// ������ �� ������ ������ �� ���� ������������� �������


int main()
{
	std::locale::global(std::locale("RU"));
	system("chcp 65001");

	TextFromClipboardClass::TextFromClipboardVoid();//������� ����������� �� ����� ������ � ���������� ���������� text_from_Buffer

	WriteClipboardClass::WriteClipboardVoid(); // text_from_Buffer - ���������� ����������
};

