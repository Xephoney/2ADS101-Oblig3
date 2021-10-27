#include "oppgave_2.h"
#include <iostream>

Oppgave_2::Oppgave_2()
{

}
void Oppgave_2::FillArray(int *a, int size)
{
    for(int i = 0; i < size; i++)
        a[i] = rand() % (size*2)+1;
}
void Oppgave_2::PrintArray(int *a, int size)
{
    std::cout << "\n| ";
    for(int i = 0; i < size; i++)
    {
        std::cout << a[i] << " | ";
    }
    std::cout << " |\n";
}
void Oppgave_2::Merge(int *a, const int venstre, const int midt, const int right)
{
    const int sub1{midt-venstre+1};
    const int sub2{right-midt};

    auto *vArr = new int[sub1];
    auto *hArr = new int[sub2];

    for(int i= 0; i <sub1; i++)
        vArr[i] = a[venstre+i];
    for(int j=0; j<sub2;j++)
        hArr[j]=a[midt+1+j];

    int vIndex{0},hIndex{0};
    int MergedIndex = venstre;

    while (vIndex < sub1 && hIndex < sub2) {
        if(vArr[vIndex] <= hArr[hIndex])
        {
            a[MergedIndex] = vArr[vIndex];
            hIndex++;
        }
        else
        {
            a[MergedIndex] = hArr[hIndex];
            hIndex++;
        }
        MergedIndex++;
    }

    while(vIndex < sub1)
    {
        a[MergedIndex] = vArr[vIndex];
        vIndex++;
        MergedIndex++;
    }
    while(hIndex < sub2)
    {
        a[MergedIndex] = hArr[hIndex];
        hIndex++;
        MergedIndex++;
    }
}
void Oppgave_2::MergeSort(int *a, int start, int slutt, bool PrintSteps)
{
    if(start >= slutt)
        return;

    int const midt = start + (slutt-start)/2;
    MergeSort(a, start, midt, false);
    MergeSort(a, midt + 1, slutt, false);
    Merge(a, start, midt, slutt);
    if(PrintSteps)
        PrintArray(a, slutt+1);
}
