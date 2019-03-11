#include "ruptor.h"

Ruptor::Ruptor(int &ArgumentsCount, char **Arguments)
{
    ArgumentsCount--;       //because first argument is always name of program that useless



    switch(ArgumentsCount) {

    case 0:                     //ruptor
        Help();
        break;

    case 1:                     //ruptor -h
        arg1 = Arguments[1];

        if (arg1=="-v" || arg1=="--version")
            Version();
        else
            Help();

        break;

    case 2:                     //nothing
        Help();
        break;

    case 3:                     //ruptor analysis --text [text]
        arg1 = Arguments[1];
        arg2 = Arguments[2];
        arg3 = Arguments[3];

        if(arg1 == "-a" || arg1 =="analysis") {
            //Analysis analysis(arg3)
        }
        else
            Help();
        break;

    case 4:
        arg1 = Arguments[1];
        arg2 = Arguments[2];
        arg3 = Arguments[3];
        arg4 = Arguments[4];

        if(arg1 == "-a" || arg1 =="analysis" ) {
            //Analysis analysis(arg3,arg4)
        }
        else
            Help();


        break;
    case 5:
        arg1 = Arguments[1];
        arg2 = Arguments[2];
        arg3 = Arguments[3];
        arg4 = Arguments[4];
        arg5 = Arguments[5];

        if(arg1 == "-e" || arg1 == "encrypt" ) {
            if (arg5 == "xor") {
                //Xor xor (arg3,arg5)
            }
            else if (arg5 == "caesar") {
                //Caesar caesar(arg3,arg5)
            }
        }
        else if (arg1 == "-d" || arg1 == "decrypt") {
            if (arg5 == "xor") {
                //Xor xor (arg3,arg5)
            }
        }
        else
            Help();
        break;

    case 6:
        arg1 = Arguments[1];
        arg2 = Arguments[2];
        arg3 = Arguments[3];
        arg4 = Arguments[4];
        arg5 = Arguments[5];
        arg6 = Arguments[6];

        if(arg1 == "-e" || arg1 == "encrypt") {
            if (arg5=="caesar") {
                //Caesar caesar(arg3,arg4,arg6)
            }


        }
        else if(arg1 == "-d" || arg1 == "decrypt") {
            if (arg5=="caesar") {
                //Caesar caesar(arg3,arg4,arg6)
            }
        }
        else
            Help();
        break;

    default:
        Help();
        break;
    }
}
void Ruptor::Help(){
    wcout<<L"\nUsage:"<<endl
         <<L"\truptor {-h --help}"<<endl
         <<L"\truptor {-v --version}"<<endl
         <<L"\truptor {-a --analysis}\n\t\t[-t --text] <text>\n\t\t[-f --file] <file dir>"<<endl
         <<L"\truptor {-e --encrypt}"<<endl
         <<L"\truptor {-d --decrypt}\n\t\t[-c --caesar] <lang>\n\t\t\t\t[-k --key]\n\t\t\t\t[-f --frequency]\n\t\t\t\t[-b --brute]"<<endl<<endl;

}
void Ruptor::Version(){
   wcout<<L"\t#####  #    # #####  #####  ####  #####"   <<endl
        <<L"\t#    # #    # #    #   #   #    # #    #"  <<endl
        <<L"\t#    # #    # #    #   #   #    # #    #"  <<endl
        <<L"\t#####  #    # #####    #   #    # #####"   <<endl
        <<L"\t#   #  #    # #        #   #    # #   #"   <<endl
        <<L"\t#    #  ####  #        #    ####  #    #"  <<endl
        <<L"\n* ruptor 0.6.0  \n* analysis/encryption/decryption\n* GNU General Public License v2\n\n* Created and Supported by Mogekoff and NickBorovikov"<<endl<<endl;
}
