#include<iostream>
#include<fstream>
using namespace std;
bool x[25];
void knapsack(int v[25],int w[25],int m,int n,int ci,int cw,int cv,int &mp,bool (&sobjs)[25],int &count){
  if(ci == n or cw == m){
    if(cv > mp){
      mp = cv;
      for(int i = 0;i<n;i++) sobjs[i] = x[i];
    }
    return;
  }

  int ub = cv + (m-cw)*v[ci]/w[ci];
  if (ub <= mp) return;
  if(cw + w[ci] <= m){
    x[ci] = true; 
    count++;
    knapsack(v,w,m,n,ci+1,cw+w[ci],cv+v[ci],mp,sobjs,count);
  }
  x[ci] = false; 
  count++;
  knapsack(v,w,m,n,ci+1,cw,cv,mp,sobjs,count);
}

int main(){
  int v[25],w[25],m,n,mp = 0,count = 0;
  bool sobjs[25];
  cout<<"Enter the no. of items : ";
  cin>>n;
  cout<<"Enter the weight of the sack : ";
  cin>>m;
  for(int i = 0;i<n;i++) x[i] = false;
  for(int i = 0;i<n;i++){
    cout<<"Enter the value and weight for "<<i+1<<" : ";
    cin>>v[i];
    cin>>w[i];
  }
  knapsack(v,w,m,n,0,0,0,mp,sobjs,count);
  for(int i = 0;i<n;i++) {
    if(sobjs[i] == true) cout<<"I"<<i+1<<"\t";
  }
  cout<<"\nMax value : "<<mp<<endl;
}
