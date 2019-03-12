#include "io.h"

IO::IO()
{

}
bool IO::WriteTextToFile(string dir) {

}
bool IO::GetTextFromFile(string dir) {

}
bool IO::SetAlphabet(string lang){

}
wstring const&IO::GetAlphabet(){
    return alphabet;
}
wstring const&IO::GetFrequency(){
    return frequency;
}
wstring const&IO::GetInputText(){
    return input;
}
wstring &IO::GetOutputText() {
    return output;
}
bool IO::Output() {
    wcout<<output;
}
