#include "io.h"

IO::IO()
{

}
bool IO::WriteTextToFile(wstring dir) {         //ADD SUPPORT FOR UNICODE!!!

    wofstream file (converter.to_bytes(dir));
    file.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

    if (file.is_open())
    {
        file<<output;
    }


    return true;
}
bool IO::GetTextFromFile(wstring dir) {         //ADD SUPPORT FOR UNICODE!!!

    wstring line;

    wifstream file (converter.to_bytes(dir));

    if (file.is_open())
    {

        file.close();
    }
    return true;
}
bool IO::SetAlphabet(string lang) {
    wstring line;

    wifstream file ("../ruptor/langs/"+lang);               //"lang" == en, ru, etc. Same as file.

    file.imbue(locale(locale(), new codecvt_utf8<wchar_t>));//Change encoding of stream to Utf-8

    if (file.is_open())
    {
        while(line != L"ALPHABET:")
            getline (file, line);
        getline(file, line);
        alphabet = line;

        while(line != L"FREQUENCY:")
            getline (file, line);
        getline (file, line);
        frequency = line;

        alphabetLength = signed(line.size())/2;     //Division by 2 because alphabet contains uppercase and lowercase same letters.

        file.close();
    }
    return true;
}
int     * IO::GetInputLenght() {
    return &inputLenght;
}
int     * IO::GetAlphabetLenght(){
    return &alphabetLength;
}
wstring * IO::GetAlphabet(){
    return &alphabet;
}
wstring * IO::GetFrequency(){
    return &frequency;
}
wstring * IO::GetInputText(){
    return &input;
}
wstring * IO::GetOutputText() {
    return &output;
}
bool IO::SetInputOutputMode(string inout){
    this->inout=inout;
    return true;
}
bool IO::Input(wstring textOrDir){
    if (inout == "-tt" || inout == "-tf" || inout == "--textfile" || inout == "--texttext") {
        input = textOrDir;
        inputLenght=signed(input.length());
        return true;
    }
    else if(inout == "-ft" || inout == "-ff" || inout == "--filetext" || inout == "--filefile") {
        GetTextFromFile(textOrDir);
        inputLenght=signed(input.length());
        return true;
    }
    else return false;
}

bool IO::Output() {
    if(inout == "-tt" || inout == "-ft" || inout == "--texttext" || inout == "--filetext") {
        wcout<<output<<endl;
        return true;
    }
    else if (inout == "-tf" || inout =="-ff" || inout == "--textfile" || inout == "--filefile"){
        WriteTextToFile(L"~/ruptor_out");           //FIX CONST DIR!!!!
        return true;
    }
    else return false;
}
