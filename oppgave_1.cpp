#include "oppgave_1.h"
#include <conio.h>

Oppgave_1::Oppgave_1() { }

void Oppgave_1::Aktiver()
{
    const int size {20};
    int array2[size];
    FillArray(array2,size);
    PrintArray(array2,size);
    MergeSort(array2,0, size-1, false);
    PrintArray(array2,size);
}
void Oppgave_1::FillArray(int *a, int size)
{
    for(int i = 0; i < size; i++)
        a[i] = rand() % (size*2)+1;
}
void Oppgave_1::PrintArray(int *a, int size)
{
    std::cout << "\n| ";
    for(int i = 0; i < size; i++)
    {
        std::cout << a[i] << " | ";
    }
    std::cout << "\n";
}
void Oppgave_1::Merge(int *a, const int venstre, const int midt, const int right)
{
    const int LeftSubRange{midt-venstre};
    const int RightSubRange{right-midt};

    auto *vArr = new int[LeftSubRange];
    auto *hArr = new int[RightSubRange];

    for(int i= 0; i <LeftSubRange; i++)
        vArr[i] = a[venstre+i];
    for(int j=0; j<RightSubRange;j++)
        hArr[j]=a[midt+1+j];

    int vIndex{0},hIndex{0};
    int fletteIndex = venstre;

    while (vIndex < LeftSubRange && hIndex < RightSubRange) {
        if(vArr[vIndex] <= hArr[hIndex])
        {
            a[fletteIndex] = vArr[vIndex];
            hIndex++;
        }
        else
        {
            a[fletteIndex] = hArr[hIndex];
            hIndex++;
        }
        fletteIndex++;
        PrintArray(a, right);
        getch();
    }

    while(vIndex < LeftSubRange)
    {
        a[fletteIndex] = vArr[vIndex];
        vIndex++;
        fletteIndex++;
    }
    while(hIndex < RightSubRange)
    {
        a[fletteIndex] = hArr[hIndex];
        hIndex++;
        fletteIndex++;
    }
    delete[] hArr;
    delete[] vArr;
}
void Oppgave_1::MergeSort(int *a, int start, int slutt, bool PrintSteps)
{
    if(start >= slutt)
        return;

    auto midt = start + (slutt-start)/2;
    MergeSort(a, start, midt, false);
    MergeSort(a, midt + 1, slutt, false);
    Merge(a, start, midt, slutt);

    if(PrintSteps)
        PrintArray(a, slutt+1);
}
void Oppgave_1::InsertionSort(int *a, int size, bool printSteps)
{
    for(int i = 1; i<size; i++)
    {
        int temp = a[i];
        for(int j=i; j>=0 && a[j] > temp; j--)
        {
            a[j+1] = a[j];
            a[j+1] = temp;
        }
        if(printSteps)
            PrintArray(a, size);
    }
}
