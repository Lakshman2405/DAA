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

subarray crosssubarray(int (&a)[1000],int l,int m,int h,int &count){
  int leftsum = -100000;
  int sum = 0;
  int ml,mr;
  for(int i = m;i>=l;i--){
    count++;
    sum += a[i];
    if (sum > leftsum){
      leftsum = sum;
      ml = i;
    }
  }
  int rightsum = -100000;
  sum = 0;
  for(int i = m+1;i<=h;i++){
    count++;
    sum += a[i];
    if (sum > rightsum){
       rightsum = sum;
       mr = i;
    }
  }
  return subarray(ml,mr,leftsum+rightsum);
}

subarray findmaxsubarray(int (&a)[1000],int low,int high,int &count){
  if (low == high) return subarray(low,high,a[low]);
  else{
    int mid = (low + high)/2;
    subarray left = findmaxsubarray(a,low,mid,count);
    subarray right = findmaxsubarray(a,mid+1,high,count);
    subarray middle = crosssubarray(a,low,mid,high,count);

    if (left.maxsum >= right.maxsum and left.maxsum >= middle.maxsum) return left;
    else if (right.maxsum >= left.maxsum and right.maxsum >= middle.maxsum) return right;
    else return middle;
  }
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
  subarray s = findmaxsubarray(a,0,n-1,count);
  for(int i = s.l;i<=s.h;i++) cout<<a[i]<<'\t';
  cout<<endl;
  cout<<"The count is "<<count;
  fin.close();
}