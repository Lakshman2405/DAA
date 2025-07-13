#include<iostream>
#include<fstream>
using namespace std;

void setup(int (&a)[1000],int (&x)[1000],int n,int &s,int &r,int &count){
    s = r = count = 0;
    for(int i = 0;i<n;i++){
        x[i] = 0;
        r += a[i];
    }
}

void subsetsum(int (&a)[1000],int (&x)[1000],int n,int m,int k,int s,int r,int &count){
    x[k] = 1;
    if (s + a[k] == m){
        for(int i = 0;i<=k;i++) {
            if (x[i] == 1) cout<<a[i]<<"\t";
        }
        cout<<endl;
        return;
    }
    else if((s + a[k] +a[k+1]) <= m){
        count++;
        subsetsum(a,x,n,m,k+1,s+a[k],r-a[k],count);
    }
    if((s+r-a[k])>=m and (s+a[k+1])<=m){
        x[k] = 0;
        count++;
        subsetsum(a,x,n,m,k+1,s,r-a[k],count);
    }
    return;
}

int main(){
    int a[1000],x[1000];
    int s,r,n,count,m;
    cout<<"Enter the no. of inputs : ";
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter the sum value : ";
    cin>>m;
    setup(a,x,n,s,r,count);
    subsetsum(a,x,n,m,0,s,r,count);
    cout<<"The no. of comparisions is "<<count;
}