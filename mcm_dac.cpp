#include<iostream>
using namespace std;

int matrix_chain_mul(int p[30],int i,int j,int &count,int (&m)[30][30],int (&s)[30][30]){
    if(i==j) return 0;
    m[i][j] = 1000000;
    for(int k = i;k<j;k++){
        count++;
        int q = matrix_chain_mul(p,i,k,count,m,s)+matrix_chain_mul(p,k+1,j,count,m,s)+p[i-1]*p[k]*p[j];
        if(q<m[i][j]){
            m[i][j] = q;
            s[i][j] = k;
        }
    }
    return m[i][j];
}

void print(int s[30][30],int i,int j){
    if(i==j) cout<<"A"<<i;
    else{
        cout<<"(";
        print(s,i,s[i][j]);
        print(s,s[i][j]+1,j);
        cout<<")";
    }
}

int main(){
    int n,p[30],count = 0;
    cout<<"Enter the no. of array : ";
    cin>>n;
    cout<<"Enter the dim : ";
    for(int i = 0;i<n+1;i++){
        cin>>p[i];
    }
    int m[30][30],s[30][30];
    matrix_chain_mul(p,1,n,count,m,s);
    print(s,1,n);
    cout<<endl;
    cout<<"Count :"<<count;
}