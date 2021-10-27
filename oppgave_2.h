#ifndef OPPGAVE_2_H
#define OPPGAVE_2_H


class Oppgave_2
{
public:
    Oppgave_2();
    void Aktiver();
    void FillArray(int *a, int size);
    void PrintArray(int *a, int size);
    void MergeSort(int *a, int start, int slutt, bool PrintSteps);
    void Merge(int *a, const int venstre, const int midt, const int right);
};

#endif // OPPGAVE_2_H
