#ifndef OPPGAVE_1_H
#define OPPGAVE_1_H
#include <iostream>
#include <chrono>

class Oppgave_1
{
private :
    void Merge(int *a, const int venstre, const int midt, const int right);

    void SortTimeInsertion(int* a, int size, int loops);
    void SortTimeMerge(int* a, int size, int loops);


public:
    Oppgave_1();
    void Aktiver();
    void FillArray(int *a, int size);
    void PrintArray(int *a, int size);
    void InsertionSort(int *a, int size, bool printSteps);
    void MergeSort(int *a, int start, int slutt, bool PrintSteps);
};

#endif // OPPGAVE_1_H
