#include "oppgave_3.h"
#include <iostream>

Oppgave_3::Oppgave_3()
{


}

void Oppgave_3::Aktiver()
{
    obg3_unordered_set();

}

void obg3_unordered_set ()
{
    hash<Test> ht;
    unordered_set<Test> us;
    unordered_set<Test>::iterator usit;
    pair<unordered_set<Test>::iterator, bool> par;

    Test t;


    std::cout << "Tester Hash Funksjonen" << std::endl;
    for (auto i= 0; i<15; i++)
    {
        t.key = i;
        std::cout << "Hash ht (" << i << ") = " << ht(t) << std::endl;
    }

    t.key = 12; t.s = "Tolv";
    us.insert(t);
    t.key = 14; t.s = "fjorten";
    us.insert(t);

    t.key = 14; t.s = "Fjorten b";
    int m = us.size();

    par = us.insert(t);
    int n = us.size();

    std::cout << t.s << " satt inn? " << boolalpha << ( n=m==1) << std::endl;

    std::cout << t.s << " satt inn? " << boolalpha << par.second << std::endl;

    t.key = 14;
    usit = us.find(t);
    t = *usit;
    std::cout << " " << std::endl;
    std::cout << "post funnet: " << t.key << " " << t.s << std::endl;


}

