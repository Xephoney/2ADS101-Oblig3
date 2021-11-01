#include "oppgave_1.h"
#include <conio.h>
#include <ctime>

Oppgave_1::Oppgave_1() { }

void Oppgave_1::Aktiver()
{
    const int size1 {10};
    const int size2 {100};
    const int size3 {1000};
    const int size4 {10000};

    int array1[size1];
    int array2[size2];
    int array3[size3];
    int array4[size4];


    std::cout << "----Insertion----\n";
    SortTimeInsertion(array1, size1, 10000);
    SortTimeInsertion(array2, size2, 1000);
    SortTimeInsertion(array3, size3, 100);
    SortTimeInsertion(array4, size4, 10);

    std::cout << "----Merge----\n";
    SortTimeMerge(array1, size1, 10000);
    SortTimeMerge(array2, size2, 1000);
    SortTimeMerge(array3, size3, 100);
    SortTimeMerge(array4, size4, 10);
}
void Oppgave_1::FillArray(int *a, int size)
{
    srand((unsigned)time(0));
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
    delete[] RightArray;
    delete[] LeftArray;
}
void Oppgave_1::SortTimeInsertion(int* a, int size, int loops)
{
    //Starte klokka
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i<loops; i++)
    {
        //fylle array
        FillArray(a,size);
        //kalle sorterings funksjonen
        InsertionSort(a,size,false);
    }
    //Stoppe klokka
    auto slutt = std::chrono::high_resolution_clock::now();

    //regne ut totaltid gjennom en cast og hente ut .Count()
    double time = std::chrono::duration_cast<std::chrono::milliseconds>(slutt - start).count();

    //printe ut tiden gjennomsnittstiden per sortering ved å dele på loops
    std::cout << "[" << size <<"] = " << time/(double)loops << " milliseconds\n";
}
void Oppgave_1::SortTimeMerge(int* a, int size, int loops)
{
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i<loops; i++)
    {
        FillArray(a,size);
        MergeSort(a,0,size,false);
    }
    auto slutt = std::chrono::high_resolution_clock::now();
    double time = std::chrono::duration_cast<std::chrono::milliseconds>(slutt - start).count();

    std::cout << "[" << size <<"] = " << time/(double)loops << " milliseconds\n";
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
    int i, j, temp;
    for(i = 1; i<size; i++)
    {
        temp = a[i];
        for(j=i-1; j>=0 && a[j] > temp; j--)
        {
            a[j+1] = a[j];
        }
        a[j+1] = temp;
        if(printSteps)
            PrintArray(a, size);
    }
}
