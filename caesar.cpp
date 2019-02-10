#include "caesar.h"

string CaesarKey(const int key, const string &lang, const string &text){
    string abc, ABC, resultText;
    int size, SIZE;

    getAlphabet(abc, ABC, size, SIZE, lang);

    bool flag;
    int newKey = 0;

    for (unsigned int i = 0; i<text.size(); i++) {
        flag = false;
        for (int j = 0; j<size; j++) {
            if(text[i]==abc[unsigned(j)]){
                flag = true;

                if(j+key>0){
                    newKey= (j+key) % size;
                }
                if(j+key<0){
                    newKey= size+((j+key) % size);
                }
                if(j+key==0){
                    newKey=0;
                }
                if(newKey==signed(abc.size()))
                    newKey=0;
                resultText.push_back(abc[unsigned(newKey)]);
                break;
            }
        }
        if(!flag){
            for (int k = 0; k<SIZE; k++) {
                if(text[i]==ABC[unsigned(k)]){

                    if(k+key>0){
                        newKey= (k+key) % SIZE;
                    }
                    if(k+key<0){
                        newKey= size+((k+key) % SIZE);
                    }
                    if(k+key==0){
                        newKey=0;
                    }
                    if(newKey==signed(ABC.size()))
                        newKey=0;
                    resultText.push_back(ABC[unsigned(newKey)]);
                    break;
                }
                else if (k==SIZE-1)
                    resultText.push_back(text[i]);
            }

        }
    }
    return resultText;
}
