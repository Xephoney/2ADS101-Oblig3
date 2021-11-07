#include "oppgave_3.h"
#include <iostream>

Oppgave_3::Oppgave_3()
{


}

void Oppgave_3::Aktiver()
{

    //we set up unordered set
    std::unordered_set<Test> us;
    std::cout << "Unordered_set in specified order" << std::endl;

        //We make a small array with the numbers within
        int a[10] {12, 13, 20, 21, 1, 2, 3, 4, 5, 6};
        for (int i= 0; i<10; i++)
        {
            Test t;
            t.key = a[i];
            // dette setter a[i] = 0 til 'a' i stringen.
            t.s = 97+a[i];
            us.insert(t);
            //We print out the array numbers in the same order
            std::cout << " " << t.key << " ";
        }
        std::cout << std::endl;
}


