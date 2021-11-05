#include <iostream>
#include "oppgave_1.h"
#include "oppgave_2.h"
#include "oppgave_3.h"
#include "oppgave_4.h"

using namespace std;

int main()
{
    Oppgave_1 oppg1;
    oppg1.Aktiver();

    std::cout << " " << std::endl;

    Oppgave_3 oppg3;
    oppg3.Aktiver();

    return 0;
}
