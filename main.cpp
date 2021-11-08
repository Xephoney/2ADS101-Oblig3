#include <iostream>
#include "oppgave_1.h"
#include "oppgave_2.h"
#include "oppgave_3.h"
#include "oppgave_4.h"

using namespace std;

int main()
{
    std::cout << " oppgave 1: " << std::endl;
    Oppgave_1 oppg1;
    oppg1.Aktiver();

    std::cout << " oppgave 2: " << std::endl;
    Oppgave_2 oppg2;
    oppg2.Aktiver();

    std::cout << " oppgave 3: " << std::endl;
    Oppgave_3 oppg3;
    oppg3.Aktiver();

    std::cout << " oppgave 4: " << std::endl;
    Oppgave_4 oppg4;
    oppg4.Aktiver();
    return 0;
}
