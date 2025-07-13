#include<iostream>
#include<string>
using namespace std;

int charcode(char a){
    switch(a){
        case 'A':return 1;
        case 'B':return 2;
        case 'C':return 3;
        case 'G':return 4;
        case 'T':return 5;
        case 'X':return 6;
        default:return 0;
    }
}

int preprocess(string p,int d,int q){
    int m = p.length();
    int a = 0,count = 0;
    for(int i = 0;i<m;i++){
        count++;
        a = (a*d + charcode(p[i])) % q;
    }
    cout<<"Preprocess count : "<<count;
    return a;
}

void rk_matcher(string T,string P,int a,int d,int q,int &count){
    int n = T.length();
    int m = P.length();
    int t[n];
    int h = 1;
    cout << "Hash of the pattern (a): " << a << endl;
    for(int i = 0;i<m-1;i++){
        h = (h*d) % q;
    }
    t[0] = 0;
    for(int i = 0;i<m;i++){
        t[0] =  (d*t[0]+charcode(T[i])) % q;
    }
    for(int s = 0;s<n-m+1;s++){
        cout << "Window starting at " << s << ": hash = " << t[s] << endl;
        count++;
        if(a == t[s]){
            int flag = 1;
            for(int j = 0;j<m;j++){
                if(P[j] != T[s+j]){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1) cout<<"The pattern found at "<<s<<endl;
        }
        if(s<n-m){
            t[s+1] = (d*(t[s] - charcode(T[s])*h) + charcode(T[s+m])) % q;
            if(t[s+1] < 0){
                t[s+1] += q;
            }
        }
    }
}

int main(){
    string t = "ABABABCABABCABABCCABABABCABABABB",p = "ABABCABAB";
    int a = preprocess(p,10,499);
    int count = 0;
    rk_matcher(t,p,a,10,499,count);
    cout<<"Count : "<<count<<endl;
}