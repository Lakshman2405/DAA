#include<iostream>
using namespace std;

class graph{
    int n;
    int d[10][10],pi[10][10];
public:
    void initialize(int w[10][10],int n){
        this->n = n;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                d[i][j] = w[i][j];
                if(i == j or w[i][j] == 999) pi[i][j] = -1;
                else pi[i][j] = i;
            }
        }
    }
    void floyd_warshall(){
        for(int k = 1;k<=n;k++){
            for(int i = 1;i<=n;i++){
                for(int j = 1;j<=n;j++){
                    if(pi[i][k] != -1 and pi[k][j] != -1 and d[i][j] > d[i][k]+d[k][j]){
                        d[i][j] = d[i][k] + d[k][j];
                        pi[i][j] = k;
                    }
                }
            }
        }
    }
    void display(){
        cout<<"D[][] values..."<<endl;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(d[i][j] == 999) cout<<00<<"\t";
                else cout<<d[i][j]<<"\t";
            }
            cout<<endl;
        }
        cout<<"Pi[][] values..."<<endl;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                cout<<pi[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
};

int main(){
    graph g;
    int w[10][10],n;
    cout<<"Enter the size of the matrix : ";
    cin>>n;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin>>w[i][j];
        }
    }
    g.initialize(w,n);
    g.floyd_warshall();
    g.display();
}