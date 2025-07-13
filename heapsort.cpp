#include<iostream>
#include<fstream>
using namespace std;

int left(int n){
  return (2*n)+1;
}

int right(int n){
  return (2*n)+2;
}

void maxheapify(int (&a)[10000],int heapsize,int i,int &count){
  int l = left(i);
  int r = right(i);
  int largest;

  count++;

  if (l<=heapsize and a[l]>a[i]) largest = l;
  else largest = i;

  count++;

  if (r<=heapsize and a[r]>a[largest]) largest = r;

  if (largest != i){
    swap(a[i],a[largest]);
    maxheapify(a,heapsize,largest,count);
  }
}

void builtmax(int (&a)[10000],int heapsize,int &count){
  for (int j = heapsize/2;j>=0;j--){
    maxheapify(a,heapsize,j,count);
  }
}

void heapsort(int (&a)[10000],int &heapsize,int &count){
  builtmax(a,heapsize,count);
  for(int i = heapsize;i>=1;i--){
    swap(a[i],a[0]);
    heapsize--;
    maxheapify(a,heapsize,0,count);
  }
}

int main(){
  ifstream fin;
  fin.open("input.txt");
  int a[10000],n,count = 0;
  cout<<"Enter the no. of inputs : ";
  cin>>n;
  
  for(int i = 0;i<n;i++){
    fin>>a[i];
  }
  fin.close();

  int size = n-1;
  heapsort(a,size,count);

  cout<<"Sorted array..."<<endl;
  for (int i = 0;i<n;i++){
    cout<<a[i]<<"\t";
  }
  cout<<"The no. of comparisions for "<<n<<" input is "<<count;
} 