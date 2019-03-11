#include <headers.h>
#include <ruptor.h>

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    wcin.imbue(locale("en_US.UTF-8"));
    wcout.imbue(locale("en_US.UTF-8"));


    Ruptor ruptor(argc, argv);

    return 0;
}
