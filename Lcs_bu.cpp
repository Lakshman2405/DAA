#include<iostream>
#include<fstream>
using namespace std;

void print(char x[60],char b[60][60],int i,int j){
   if (i == 0 or j == 0) return;
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

void lcs(char x[60],char y[60],int m,int n,int &count){
  int c[60][60];
  char b[60][60];

  for(int i = 0;i<=n;i++) c[0][i] = 0;
  for(int i = 1;i<=m;i++) c[i][0] = 0;
 
  for(int i = 1;i<=m;i++){
    for(int j = 1;j<=n;j++){
      count++;
      if (x[i] == y[j]){
         c[i][j] = c[i-1][j-1] + 1;
         b[i][j] = 'D';
      }
      else if(c[i-1][j] >= c[i][j-1]){
         c[i][j] = c[i-1][j];
         b[i][j] = 'T';
      }
      else{
         c[i][j] = c[i][j-1];
         b[i][j] = 'L';
      }
    }
  }
  print(x,b,m,n);
}

int main(){
  char x[60],y[60];
  int m,n,count = 0;
  cout<<"Size of x : ";
  cin>>m;
  cout<<"Size of y : ";
  cin>>n;
  cout<<"Input For X : ";
  for(int i = 1;i<=m;i++) cin>>x[i];
  cout<<"Input For Y :";
  for(int j = 1;j<=n;j++) cin>>y[j];
  lcs(x,y,m,n,count);
}
