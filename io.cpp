#include "io.h"

IO::IO()
{

}
bool IO::WriteTextToFile(wstring dir) {         //ADD SUPPORT FOR UNICODE!!!

    ofstream file (converter.to_bytes(dir));

    if (file.is_open())
    {
        file<<converter.to_bytes(output);
    }


    return true;
}
bool IO::GetTextFromFile(wstring dir) {         //ADD SUPPORT FOR UNICODE!!!

    string line;

    ifstream file (converter.to_bytes(dir));

    if (file.is_open())
    {
        while(line != "ALPHABET:")
            getline (file, line);
        getline(file, line);
        alphabet = converter.from_bytes(line);

        while(line != "FREQUENCY:")
            getline (file, line);
        getline (file, line);
        frequency = alphabet = converter.from_bytes(line);

        alphabetLength = signed(line.length())/2;

        file.close();
    }
    return true;
}
bool IO::SetAlphabet(string lang) {     //ADD SUPPORT FOR UNICODE!!!
    string line;

    ifstream file ("../langs/"+lang);   //WHY TWO DOTS "../" ??? (but it works)

    if (file.is_open())
    {
        while(line != "ALPHABET:")
            getline (file, line);
        getline(file, line);
        alphabet = converter.from_bytes(line);

        while(line != "FREQUENCY:")
            getline (file, line);
        getline (file, line);
        frequency = converter.from_bytes(line);

        alphabetLength = signed(line.length())/2;

        file.close();
    }
    return true;
}
int *IO::GetAlphabetLenght(){
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
wstring *IO::GetOutputText() {
    return &output;
}
bool IO::SetInputOutputMode(string inout){
    this->inout=inout;
    return true;
}
bool IO::Input(wstring textOrDir){
    if (inout == "-tt" || inout == "-tf" || inout == "--textfile" || inout == "--texttext") {
        input = textOrDir;
        return true;
    }
    else if(inout == "-ft" || inout == "-ff" || inout == "--filetext" || inout == "--filefile") {
        GetTextFromFile(textOrDir);
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
