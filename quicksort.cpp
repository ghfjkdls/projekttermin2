#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

void check(int *tab,int size){
  for(int i=0;i<size-1;i++) {
    if(tab[i]>tab[i+1])cout<<"blad zle posortowana tablica"<<endl;
  }
}

void quicksort(int *tab, int low, int high){
    int i = low;
    int j = high;
    int pivot = tab[(i + j) / 2];
    int temp;

    while (i <= j){
        while (tab[i] < pivot) i++;
        while (tab[j] > pivot) j--;
        if (i <= j) {
            temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low) quicksort(tab, low, j);
    if (i < high)quicksort(tab, i, high);
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
    quicksort(tab,0,size-1);
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
