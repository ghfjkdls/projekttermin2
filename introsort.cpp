#include <iostream>
#include <fstream>
#include <time.h>
#include <cmath>
#include <algorithm>

using namespace std;

void check(int *tab,int size){
  for(int i=0;i<size-1;i++) {
    if(tab[i]>tab[i+1])cout<<"blad zle posortowana tablica"<<endl;
  }
}
void swapvalue(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = temp;
    return;
}

void InsertionSort(int tab[], int *begin, int *end){
    int left = begin - tab;
    int right = end - tab;

    for (int i = left+1; i <= right; i++){
        int key = tab[i];
        int j = i-1;
        while (j >= left && tab[j] > key) {
            tab[j+1] = tab[j];
            j = j-1;
        }
        tab[j+1] = key;
   }
   return;
}

int* partition(int tab[], int low, int high)
{
    int pivot = tab[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++) {

        if (tab[j] <= pivot){
            i++;
            swap(tab[i], tab[j]);
        }
    }
    swap(tab[i + 1], tab[high]);
    return (tab + i + 1);
}

int *median(int * a, int * b, int * c)
{
    if (*a < *b && *b < *c)    return (b);
    if (*a < *c && *c <= *b)   return (c);
    if (*b <= *a && *a < *c)   return (a);
    if (*b < *c && *c <= *a)   return (c);
    if (*c <= *a && *a < *b)   return (a);
    if (*c <= *b && *b <= *a)  return (b);
return 0;
}


void intro(int tab[], int * begin, int * end, int depthLimit){

    int size = end - begin;
    if (size < 9)  {
        InsertionSort(tab, begin, end);
        return;
    }

    if (depthLimit == 0){
        make_heap(begin, end+1);
        sort_heap(begin, end+1);
        return;
    }

    int * pivot = median(begin, begin+size/2, end);

    swapvalue(pivot, end);
    int * partitionPoint = partition(tab, begin-tab, end-tab);
    intro(tab, begin, partitionPoint-1, depthLimit - 1);
    intro(tab, partitionPoint + 1, end, depthLimit - 1);
    return;
}

void introsort(int tab[], int *begin, int *end){
    int depthLimit = 2 * log(end-begin);

    intro(tab, begin, end, depthLimit);
    return;
}

int main(){
  int size,c;
  ifstream file;
  clock_t start,end;
  double timeme;

  for(int i=0;i<100;i++){
    file.open(to_string(i));
    size=0;
    while(file>>c) size++;
    file.close();
    int *tab = new int [size];
    file.open(to_string(i));
    for(int i=0;i<size;i++) file>>tab[i];
    start=clock();
    introsort(tab,tab,tab+size-1);
    end=clock();
    timeme= double(end-start)/double(CLOCKS_PER_SEC);
    cout<<timeme<<endl;
    //for(int i=0;i<size;i++) cout<<tab[i]<<endl;
    file.close();
    check(tab,size);
    delete tab;
    cout<<endl;

  }
return 0;
}
