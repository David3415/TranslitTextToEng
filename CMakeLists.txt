cmake_minimum_required(VERSION 3.26.3 FATAL_ERROR)

project(TranslitTextToEng)

add_executable(TranslitTextToEng files/main.cpp
files/Utf16ToUtf8_Class.cpp
files/Utf8ToUtf16_Class.cpp
files/TranslitClass.cpp
files/GetMyDocumentsPathClass.cpp
files/TextFromClipboardClass.cpp
files/WriteClipboardClass.cpp
files/GetMyDocumentsPathClass.h
files/TextFromClipboardClass.h
files/TranslitClass.h
files/Utf8ToUtf16_Class.h
files/Utf16ToUtf8_Class.h
files/WriteClipboardClass.h
)
