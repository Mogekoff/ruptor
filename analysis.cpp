#include "analysis.h"

void analysis (const string &text, vector<char>&symbols, vector<int>&times) {
    auto it = text.begin(); //iterator

    for (unsigned int i = 0; i<text.length(); i++, it++) {
        for (unsigned int j = 0; j<=symbols.size(); j++) {
            if (j==symbols.size()){
                symbols.push_back(*it);
                times.push_back(1);
                break;

            }
            else if (symbols.at(j)==*it){
                times[j]++;
                break;
            }
        }
    }

    for (unsigned int i = 0; i!=times.size()-1;) {  //buble sort
        if (times.at(i)<times.at(i+1)){

            times.at(i)+=times.at(i+1);             //swap without temp var
            times.at(i+1)=times.at(i)-times.at(i+1);
            times.at(i)=times.at(i)-times.at(i+1);

            char temp = symbols.at(i);
            symbols.at(i)=symbols.at(i+1);
            symbols.at(i+1)=temp;

            i=0;
            continue;
        }
        i++;
    }

}
void frequency(vector<char>&symbols, vector<int>&times, const string &lang, string &text){
    string freq, FREQ;

    ifstream file ("./"+lang);

    if (file.is_open())
    {
        getline (file, freq);
        getline (file, FREQ);
        getline (file, FREQ);
        getline (file, FREQ);
        file.close();
    }

    freq.erase(freq.begin()+symbols.size(),freq.end());

    for (int i = 0; i<text.size(); i++) {
        for (int j = 0; j<symbols.size(); j++) {
            if (symbols[j]==text[i]) {
                    text[i]=freq[j];
            }
        }

    }

    for (unsigned int i = 0;i<symbols.size(); i++) {
        cout<<"\""<<symbols.at(i)<<"\""<<" = "<<times.at(i)<<" = \""<<freq[i]<<"\""<<endl<<endl;
    }

    cout<<"Try of decrypt of text:"<<endl<<text<<endl;

    return;
}
void printAnalysis(const vector<char>&symbols, const vector<int>&times) {

    for (unsigned int i = 0;i<symbols.size(); i++) {
        cout<<"\""<<symbols.at(i)<<"\""<<"="<<times.at(i)<<endl;
    }
}
void clear(vector<char>&symbols, vector<int>&times, string &lang){
    string abc,ABC;
    int size, SIZE;
    getAlphabet(abc,ABC,size,SIZE, lang);

    for (unsigned int i = 0; i<symbols.size();i++) {
        for (unsigned int j = 0; j<size; j++) {
            if (symbols[i]==abc[j]){
                break;
            }
            else if(j==size-1) {
                for (unsigned int l = 0; l<SIZE; l++) {
                    if (symbols[i]==ABC[j]){
                        break;
                    }
                    else if (l==SIZE-1){
                        symbols.erase(symbols.begin()+i);
                        times.erase(times.begin()+i);
                        i--;
                    }
                }
            }
        }

    }


}


