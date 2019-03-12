#include <headers.h>


class IO
{
private:

    wstring alphabet;
    wstring frequency;
    wstring input;
    wstring output;

public:
    IO();

    bool WriteTextToFile(string dir);
    bool GetTextFromFile(string dir);
    bool SetAlphabet(string lang);
    wstring const& GetAlphabet();
    wstring const& GetFrequency();
    wstring const& GetInputText();
    wstring & GetOutputText();
    bool Output();
};
