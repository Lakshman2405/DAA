#include<iostream>
using namespace std;

void matrix_chain_mul(int p[30],int n,int &count,int (&m)[30][30],int (&s)[30][30]){
    for(int i = 0;i<=n;i++) m[i][i] = 0;
    for(int l = 2;l<=n;l++){
        for(int i = 1;i<=n-l+1;i++){
            int j = i+l-1;
            m[i][j] = 1000000;
            for(int k = i;k<j;k++){
                count++;
                int q = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
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
    matrix_chain_mul(p,n,count,m,s);
    print(s,1,n);
    cout<<endl;
    cout<<"Count :"<<count;
}