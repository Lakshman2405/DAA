#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

void merge(int (&a)[2500],int p,int q,int r){
  int nl = q-p+1;
  int nr = r-q;
  int L[nl-1];
  int R[nr-1];

  for(int i = 0;i<nl;i++){
    L[i] = a[p+i];
  }
  for(int j = 0;j<nr;j++){
    R[j] = a[q+j+1];
  }

  int i = 0, j = 0;
  int k = p;

  while(i<nl and j<nr){
   if(L[i] < R[j]){
     a[k] = L[i];
     i++;
   }
   else{
     a[k] = R[j];
     j++;
   }
   k++;
  }

  while(i<nl){
    a[k] = L[i];
    i++;
    k++;
  }

  while(j<nr){
    a[k] = R[j];
    j++;
    k++;
  }
}

void mergesort(int (&a)[2500],int p,int r){
  if (p>=r) return;
  int q = (p+r)/2;
  
  mergesort(a,p,q);
  mergesort(a,q+1,r);
  merge(a,p,q,r);
}

int main(){
  int n;
  cout<<"Enter the no. of inputs : ";
  cin>>n;

  int a[2500];
  ifstream fin;
  fin.open("input-asc.txt");
  
  string line;

  for(int i = 0;i<n;i++){
    cin>>a[i];
  }
  fin.close();  
    
  mergesort(a,0,n-1);
  cout<<"Sorted array..."<<endl;
  for (int i = 0;i<n;i++){
    cout<<a[i]<<"\t";
  }
} 
