#include<iostream>
#include<fstream>
using namespace std;

struct subarray{
  int l,h,maxsum;
  subarray(){
    l = h = maxsum = 0;
  }
  subarray(int a,int b,int c){
    l = a;
    h = b;
    maxsum = c;
  }
};

subarray maxsubarray(int (&a)[1000],int n,int &count){
  int maxsum = -1000000;
  int l,h;
  for(int i = 0;i<n;i++){
    int sum = 0;
    for(int j = i;j<n;j++){
      count++;
      sum += a[j];
      if (sum > maxsum){
        maxsum = sum;
        l = i;
        h = j;
      }
    }
  }
  return subarray(l,h,maxsum);
}

int main(){
  int a[1000];
  int n,count = 0;
  cout<<"Enter the no. of inputs : ";
  cin>>n;
  ifstream fin;
  fin.open("sunarrinput.txt");
  for(int i = 0;i<n;i++){
    fin>>a[i];
  }
  subarray s = maxsubarray(a,n,count);
  for(int i = s.l;i<=s.h;i++) cout<<a[i]<<"\t";
  cout<<endl;
  cout<<"The count is "<<count;
  fin.close();
}