#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

void check(int *tab,int size){
  for(int i=0;i<size-1;i++) {
    if(tab[i]>tab[i+1])cout<<"blad zle posortowana tablica"<<endl;
  }
}

void merge(int tab[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) L[i] = tab[l + i];
    for (j = 0; j < n2; j++) R[j] = tab[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            tab[k] = L[i];
            i++;
        } else{
            tab[k] = R[j];
            j++;
        } k++;
    }  while (i < n1) {
        tab[k] = L[i];
        i++;
        k++;
    }  while (j < n2) {
        tab[k] = R[j];
        j++;
        k++;
    }
}

void margesort(int tab[], int l, int r)
{
    if (l < r)  {
        int m = l+(r-l)/2;

        margesort(tab, l, m);
        margesort(tab, m+1, r);
        merge(tab, l, m, r);
    }
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
    margesort(tab,0,size-1);
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
