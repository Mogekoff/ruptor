#include "caesar.h"


Caesar::Caesar(bool isEncryptOrElse, string inout, wstring textOrDir, string lang, string p1)
{
    Cypher::Init(inout, textOrDir,lang);





    if (isEncryptOrElse) {      //Проверка: шифровать или расшифровывать
        key = stoi(p1);         //Перевод ключа из строки в число
        Encrypt();
    }
    else {
        if (p1=="--brute") {                                    //Для параметра --brute
            for (key = 1; key<*alphabetLenght; key++) {         //Цикл, перебирающий все возможные ключи в алфавите

                output->append(L"[").append(to_wstring(key)).append(L"]*********************************************").append(L"[").append(to_wstring(key)).append(L"]\n");
                Encrypt();
                if (key!=*alphabetLenght-1) {

                    output->push_back('\n');    //После каждого цикла добавляет в output переход на нов. строку

                }
            }
        }
        else if(p1=="--frequency") {

        }
        else {
            key = stoi(p1);
            Decrypt();
        }
    }


}
bool Caesar::Encrypt(){

    if (key >= *alphabetLenght || key <= -*alphabetLenght)      //Случай, если ключ выходит за рамки алфавита
        key%=*alphabetLenght;                                   //Делим с остатком на кол-во символов в алфавите


    for (int i = 0; i<*inputLenght; i++) {                      //Цикл, проходящий по исх. тексту
        for (int j = 0; j<*alphabetLenght*2; j++) {             //Цикл, прох. по алфавиту и ищущий символ исх. текста
            if (input->at(unsigned(i))==alphabet->at(unsigned(j))) {                        //Если нашел

                if ( j + key*2 >= *alphabetLenght*2 || j + key*2 <=-*alphabetLenght*2) {    //Проверка выхода за рамки массива
                    if (j+key*2<0)
                        output->push_back(alphabet->at(unsigned((*alphabetLenght*2+j+key*2)%(*alphabetLenght*2))));
                    else
                        output->push_back(alphabet->at(unsigned((j+key*2)%(*alphabetLenght*2))));       //Добавляет расшиф. символ в строку результата
                    }
                else {
                    if (j+key*2<0)                                                                      //Случай, если сдвиг отрицательный (невозможно для wstring)
                        output->push_back(alphabet->at(unsigned(*alphabetLenght*2+j+key*2)));
                    else {
                        output->push_back(alphabet->at(unsigned(j+key*2)));
                    }
                }
                break;                                      //Запуск цикла по новой.
            }
            if(j==*alphabetLenght*2-1)                      //Случай для символов не входящих в алфавит
                output->push_back(input->at(unsigned(i)));
        }
    }


    return true;

}
bool Caesar::Decrypt(){

    key=-key;       //Т.к. шифр симметричный, то ф-ции расширофки и шифровки одинаковые.

    Encrypt();      //Только ключ противоположный по знаку.

    return true;
}
