#include<iostream>
#include<fstream>
using namespace std;

int Lcs(char x[30],char y[30],int (&c)[30][30],char (&b)[30][30],int i,int j,int &count){
  if (c[i][j] >= 0) return c[i][j];
  count++;
  if (i == 0 or j == 0){
    c[i][j] = 0;
    return c[i][j];
  }
  if(x[i] == y[j]){
    c[i][j] = Lcs(x,y,c,b,i-1,j-1,count) + 1;
    b[i][j] = 'D';
  }
  else{
    int t1 = Lcs(x,y,c,b,i-1,j,count);
    int t2 = Lcs(x,y,c,b,i,j-1,count);
    if (t1>=t2){
      c[i][j] = t1;
      b[i][j] = 'T';
    }
    else{
      c[i][j] = t2;
      b[i][j] = 'L';
    }
  return c[i][j];
  }
}

void print(char x[30],char b[30][30],int i,int j){
  if(i == 0 or j == 0) return;
  if (b[i][j] == 'D'){
    print(x,b,i-1,j-1);
    cout<<x[i];
  }
  else if(b[i][j] == 'T'){
    print(x,b,i-1,j);
  }
  else{
    print(x,b,i,j-1);
  }
}

int main(){
  char x[30],y[30];
  int c[30][30];
  char b[30][30];
  int m,n,count = 0;
  cout<<"Size of x : ";
  cin>>m;
  cout<<"Size of y : ";
  cin>>n;
  cout<<"Input For X : ";
  for(int i = 1;i<=m;i++) cin>>x[i];
  cout<<"Input For Y :";
  for(int j = 1;j<=n;j++) cin>>y[j];
  for(int i = 1;i<=m;i++){
    for(int j = 1;j<=n;j++){
      c[i][j] = -10;
    }
  }
  Lcs(x,y,c,b,m,n,count);
  print(x,b,m,n);
}
    
