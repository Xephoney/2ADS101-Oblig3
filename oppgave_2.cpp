#include "oppgave_2.h"
#include <iostream>
#include <conio.h>

Oppgave_2::Oppgave_2()
{

}

void Oppgave_2::Aktiver()
{
    int arr[14] {17, 14, 5, 7, 12, 1, 16, 29, 13, 4, 8, 18, 22, 2};
    std::cout << std::endl;
    MergeSort(arr, 0, 14-1);
    std::cout << "\nFerdig flettet array :\n";
    PrintArray(arr,14);
    std::cout << std::endl;
}
void Oppgave_2::FillArray(int *a, int size)
{
    for(int i = 0; i < size; i++)
        a[i] = rand() % (size*2)+1;
}
void Oppgave_2::PrintArray(int *a, int size)
{
    std::cout << "[";
    for(int i = 0; i < size; i++)
    {
        std::cout << a[i];
        if(!(i == size-1))
        {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}
void Oppgave_2::Merge(int *a, const int venstre, const int midt, const int right)
{
    const int LeftSubRange = midt-venstre+ 1;
    const int RightSubRange = right-midt;

    auto *LeftArray = new int[LeftSubRange];
    auto *RightArray = new int[RightSubRange];

    for(int i= 0; i < LeftSubRange; i++)
        LeftArray[i] = a[venstre+i];
    for(int j=0; j< RightSubRange;j++)
        RightArray[j]=a[midt+1+j];

    int LeftIndex{0},RightIndex{0};
    int fletteIndex = venstre;

    while (LeftIndex < LeftSubRange && RightIndex < RightSubRange) {
        if(LeftArray[LeftIndex] <= RightArray[RightIndex])
        {
            a[fletteIndex] = LeftArray[LeftIndex];
            LeftIndex++;
        }
        else
        {
            a[fletteIndex] = RightArray[RightIndex];
            RightIndex++;
        }
        fletteIndex++;
    }

    while(LeftIndex < LeftSubRange)
    {
        a[fletteIndex] = LeftArray[LeftIndex];
        LeftIndex++;
        fletteIndex++;
    }
    while(RightIndex < RightSubRange)
    {
        a[fletteIndex] = RightArray[RightIndex];
        RightIndex++;
        fletteIndex++;
    }
    std::cout << " Fletter ";
    PrintArray(LeftArray, LeftSubRange);
    std::cout << " med ";
    PrintArray(RightArray, RightSubRange);
    std::cout << "\n Resultat \t";
    PrintArray(&a[venstre], right-venstre+1);
    _getch();

    delete[] RightArray;
    delete[] LeftArray;
}
void Oppgave_2::MergeSort(int *a, int start, int slutt)
{
    if(start >= slutt)
        return;

    int const midt = start + (slutt-start)/2;
    std::cout << "----------------------------------------------\n";
    std::cout << "Deler opp array til 2 sub array \n";
    PrintArray(a, slutt+1);
    std::cout << std::endl;
    PrintArray(&a[start], midt-start+1);
    std::cout << " og ";
    PrintArray(&a[midt+1], slutt-midt);
    std::cout << "\n";
    MergeSort(a, start, midt);
    MergeSort(a, midt + 1, slutt);
    Merge(a, start, midt, slutt);

    std::cout << std::endl;
}
