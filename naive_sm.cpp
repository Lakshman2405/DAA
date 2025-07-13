#include<iostream>
#include<string>
using namespace std;

int naive(string t,string p){
    int n = t.length();
    int m = p.length();
    int count = 0;
    for(int s = 0;s<n-m+1;s++){
        bool flag = true;
        for (int j = 0;j<m;j++){
            count++;
            if(p[j] != t[s+j]){
                flag = false;
                break;
            }
        }
        if(flag) cout<<"Pattern occurs with valid shift "<<s<<endl;
    }
    return count;
}

int main(){
    string pat1 = "ABABCABAB";
    string t1 = "ABABCABABACABABCCABABCABAB",t2 = "ABABABCABABCABABCCABABABCABABABB",t3 = "AABABCABCABABCABACABABCABABCABAC";
    cout<<"count of text1 :"<<naive(t1,pat1)<<endl;
    cout<<"count of text2 :"<<naive(t2,pat1)<<endl;
    cout<<"count of text3 :"<<naive(t3,pat1)<<endl;
    string pat2 = "GTXCGGGTXCGTXC";
    string t21 = "GTGTXCGGGTXCGTXCGGGTXCGTXCGTCG",t22 = "GTXCGGGTXCGTXCGGGGTXCGGGTXCGTXC",t23 = "GGGTXCGGGTXCGTXCGGGTXCGGTXCGGGTXCGTXC";
    cout<<"count of text1 :"<<naive(t21,pat2)<<endl;
    cout<<"count of text2 :"<<naive(t22,pat2)<<endl;
    cout<<"count of text3 :"<<naive(t23,pat2)<<endl;
}