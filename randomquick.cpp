#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

int randompivot(int (&a)[10000],int p,int r){
    int q = p + rand() %(r - p + 1);
    swap(a[q],a[r]);
    return a[r];
}

int partition(int (&a)[10000],int p,int r,int &count){
    int x = randompivot(a,p,r);
    int i = p - 1;
    for(int j = p;j<r;j++){
        count++;
        if (a[j]<=x){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}

void randomquicksort(int (&a)[10000],int p,int r,int &count){
    if (p<r){
        int q = partition(a,p,r,count);
        randomquicksort(a,p,q-1,count);
        randomquicksort(a,q+1,r,count);
    }
}

void call(int n){
  int count = 0;
  int a[10000];
  ifstream fin;
  fin.open("input-desc.txt");
  for(int i = 0;i<n;i++){
      fin>>a[i];
  }
  randomquicksort(a,0,n-1,count);
  cout<<"The no. of comparisions for "<<n<<" input is "<<count<<endl;
  fin.close();
}

int main(){
    int ar[] = {10,50,100,500,1000,5000,10000};
    srand(time(0));
    for(int i = 0;i<7;i++){
      call(ar[i]);
    }
}