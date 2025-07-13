#include<iostream>
#include<string>
using namespace std;

void compute_prefix(string p,int (&pi)[15],int &count){
    int m = p.length();
    int k = 0;
    pi[0] = 0;
    count = 0;
    for(int q = 1;q<m;q++){
        count++;
        while(k>0 and p[k] != p[q]){
            k = pi[k-1];
            count++;
        }
        if(p[k] == p[q]) k++;
        pi[q] = k;
    }
}

int kmp_matcher(string t,string p,int (&pi)[15],int &count){
    compute_prefix(p,pi,count);
    cout<<"Preprocessing count : "<<count<<endl;
    int n = t.length();
    int m = p.length();
    int q = 0;
    count = 0;
    for(int i = 0;i<n;i++){
        count++;
        while(q>0 and p[q] != t[i]){
            q = pi[q-1];
            count++;
        }
        if (p[q] == t[i]){
            q++;
            if(q == m){
                cout<<"Pattern occurs with valid shift "<<i-m+1<<endl;
                q = pi[q-1];
            }
        }
    }
    return count;
}

int main(){
    string pat1 = "ABABCABAB";
    int pi[15];
    int count = 0;
    string t1 = "ABABCABABACABABCCABABCABAB",t2 = "ABABABCABABCABABCCABABABCABABABB",t3 = "AABABCABCABABCABACABABCABABCABAC";
    cout<<"count of text1 :"<<kmp_matcher(t1,pat1,pi,count)<<endl;
    cout<<"count of text2 :"<<kmp_matcher(t2,pat1,pi,count)<<endl;
    cout<<"count of text3 :"<<kmp_matcher(t3,pat1,pi,count)<<endl;
    string pat2 = "GTXCGGGTXCGTXC";
    int pi2[15];
    int count1 = 0;
    string t21 = "GTGTXCGGGTXCGTXCGGGTXCGTXCGTCG",t22 = "GTXCGGGTXCGTXCGGGGTXCGGGTXCGTXC",t23 = "GGGTXCGGGTXCGTXCGGGTXCGGTXCGGGTXCGTXC";
    cout<<"count of text1 :"<<kmp_matcher(t21,pat2,pi2,count1)<<endl;
    cout<<"count of text2 :"<<kmp_matcher(t22,pat2,pi2,count1)<<endl;
    cout<<"count of text3 :"<<kmp_matcher(t23,pat2,pi2,count1)<<endl;
}