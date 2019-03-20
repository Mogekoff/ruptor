#pragma once
#include <headers.h>
#include <fstream>
#include <locale>
#include <codecvt>


class IO
{
private:

    wstring alphabet;
    wstring frequency;
    wstring input;
    wstring output;
    string inout;
    int alphabetLength;
    wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
public:
    IO();
    int *GetAlphabetLenght();
    bool Input(wstring textOrDir);
    bool WriteTextToFile(wstring dir);
    bool GetTextFromFile(wstring dir);
    bool SetAlphabet(string lang);
    bool SetInputOutputMode(string inout);
    wstring* GetAlphabet();
    wstring* GetFrequency();
    wstring* GetInputText();
    wstring* GetOutputText();
    bool Output();
};
