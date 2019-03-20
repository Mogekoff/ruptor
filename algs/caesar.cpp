#include "caesar.h"


Caesar::Caesar(bool isEncryptOrElse, string inout, wstring textOrDir, string lang, string p1)
{
    Cypher::Init(inout, textOrDir,lang);

    this->key = stoi(p1);

    if (isEncryptOrElse)
        Encrypt();
    else
        Decrypt();



}
bool Caesar::Encrypt(){

    if (key >= *alphabetLenght || key <= -*alphabetLenght)      //Случай, если ключ выходит за рамки алфавита
        key%=*alphabetLenght;                                   //Делим с остатком на кол-во символов в алфавите


    for (int i = 0; i<input->length(); i++) {                   //Цикл, проходящий по исх. тексту
        for (int j = 0; j<alphabet->length(); j++) {            //Цикл, прох. по алфавиту и ищущий символ исх. текста
            if (input->at(i)==alphabet->at(j)) {                //Если нашел

                if ( j + key*2 >= alphabet->length() || j + key*2 <= -signed(alphabet->length()))   //Проверка выхода за рамки массива
                    output->push_back(alphabet->at( (j+key*2)%alphabet->length() ) );               //Добавляет расшиф. символ в строку результата
                else
                    output->push_back(alphabet->at(j+key*2));

                break;                                                                              //Запуск цикла по новой.
            }
        }
    }


    return true;

}
bool Caesar::Decrypt(){

    key=-key;       //Т.к. шифр симметричный, то ф-ции расширофки и шифровки одинаковые.

    Encrypt();      //Только ключ противоположный по знаку.

    return true;
}
