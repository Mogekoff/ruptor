#include "headers.h"
#include "caesar.h"
#include "analysis.h"
#include "text.h"
//вынести все в отдельные функции и добавить попытка расшифровки по частотности
//поиск повторения фраз


void printHelp(){
    cout<<"\nUsage:"<<endl
        <<"\truptor {-h --help}"<<endl
        <<"\truptor {-v --version}"<<endl
        <<"\truptor {-a --analysis}\n\t\t[-t --text] <text>\n\t\t[-f --file] <file dir>"<<endl
        <<"\truptor {-e --encrypt}"<<endl
        <<"\truptor {-d --decrypt}\n\t\t[-c --caesar] <lang>\n\t\t\t\t[-k --key]\n\t\t\t\t[-f --frequency]\n\t\t\t\t[-b --brute]"<<endl<<endl;
}
void printVersion(){
    cout<<"\t#####  #    # #####  #####  ####  #####"   <<endl
        <<"\t#    # #    # #    #   #   #    # #    #"  <<endl
        <<"\t#    # #    # #    #   #   #    # #    #"  <<endl
        <<"\t#####  #    # #####    #   #    # #####"   <<endl
        <<"\t#   #  #    # #        #   #    # #   #"   <<endl
        <<"\t#    #  ####  #        #    ####  #    #"  <<endl
        <<"\n* ruptor 0.3.0  \n* analysis/encryption/decryption\n* GNU General Public License v2\n\n* Created and Supported by Mogekoff"<<endl<<endl;
}



int main(int argc, char *argv[])            //ruptor -cmd -crypt -lang -filetext [dir/text] -type [arg]
{                                           //ruptor -a -r -? -t "sdq" -f
    string cmd = argv[1];

    if (cmd=="--version" || cmd=="-v") {
        printVersion();
        return 0;
    }
    else if (cmd=="--help" || cmd=="-h" || argc<4){
        printHelp();
        return 0;
    }

    string crypt = argv[2];
    string lang = argv[3];
    string fileOrText = argv[4];
    string type;
    string text;

    if (fileOrText=="--file" || fileOrText=="-f"){
        string dir = argv[5];
        getTextFromFile(dir,text);
    }
    else if (fileOrText=="--text" || fileOrText=="-t")
        text = argv[5];



    if (cmd=="--analysis" || cmd=="-a"){ //-a -r -? -f ./loremipsum
        vector<char>symbols;
        vector<int>times;
        analysis(text,symbols,times);
        if (crypt=="--random" || crypt=="-r") {
            if (lang=="-Q") {


            }
            else {
                frequency(symbols,times,lang,text);

            }
        }
        else if (crypt=="--alphabet" || crypt=="-a") {
            if (lang=="-Q") {
            }
            else{
                clear(symbols,times, lang);
                frequency(symbols,times,lang,text);
                return 0;
            }
        }
        printAnalysis(symbols,times);
        return 0;
    }



    else {
            type = argv[6];
            if(cmd=="--encrypt" || cmd=="-e"){   //ruptor -e -c en -t BLA -k 6

            if(crypt=="--caesar" || crypt=="-c"){

                if(type=="--key" || type=="-k") {
                    int key = stoi(argv[7]);
                    cout<<CaesarKey(key, lang, text);
                }
            }
        }

        else if(cmd=="--decrypt" || cmd=="-d"){   //ruptor -d -c en -t BLA -k 6

            if(crypt=="--caesar" || crypt=="-c"){
                if(type=="--key" || type=="-k") {
                    int key = stoi(argv[7]);
                    cout<<CaesarKey(-key, lang, text);

                }

                else if(type=="--brute" || type=="-b"){
                    int size;
                    getAlphabet(size, lang);
                    cout<<"source text:"<<endl<<text<<endl<<endl;

                    for (int key = 1; key<size; key++){
                        cout<<"key = "<<key<<endl<<CaesarKey(key, lang, text)<<endl<<endl;
                    }
                }
            }
        }
    }


    return 0;
}
