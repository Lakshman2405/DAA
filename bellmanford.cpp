#include<iostream>
#include<fstream>
#define nil -1
#define inf 9999999
using namespace std;

struct node{
    int from;
    int to;
    int weight;
    node* next;
};

struct vnode{
    string name;
    int d;
    int pi;
};

class graph{
    int m,n;
    vnode vertex[10];
    node* elist;
public:
    void creategraph();
    void initialize_single_source(int s);
    void relax(int u,int v,int w);
    bool bellman_ford(int s);
    void display();
};

void graph::creategraph(){
    cout<<"Enter the no. of vertices : ";
    cin>>n;
    for(int i = 0;i<n;i++){
        cout<<"Enter the name of vertex "<<i+1<<" : ";
        cin>>vertex[i].name;
    }
    cout<<"Enter the no. of edges : ";
    cin>>m;
    elist = NULL;
    node* last = NULL;
    for(int i = 0;i<m;i++){
        node* t = new node;
        cout<<"Enter the value for from,to and weight : ";
        cin>>t->from;
        cin>>t->to;
        cin>>t->weight;
        t->next = NULL;
        if (last == NULL){
            elist = t;
        }
        else{
            last->next = t;
        }
        last = t;
    }
}

void graph::initialize_single_source(int s){
    for(int i = 0;i<n;i++){
        vertex[i].d = inf;
        vertex[i].pi = nil;
    }
    vertex[s].d = 0;
}

void graph::relax(int u,int v,int w){
    if(vertex[v].d > vertex[u].d + w){
        vertex[v].d = vertex[u].d + w;
        vertex[v].pi = u;
    }
}

bool graph::bellman_ford(int s){
    initialize_single_source(s);
    node* t;
    for(int i = 0;i<n-1;i++){
        t = elist;
        while(t != NULL){
            relax(t->from,t->to,t->weight);
            t = t->next;
        }
    }
    t = elist;
    while(t != NULL){
        if(vertex[t->to].d > vertex[t->from].d + t->weight) return false;
        t = t->next;
    }
    return true;
}

void graph::display(){
    for(int i = 0;i<n;i++){
        cout<<vertex[i].name<<"\t";
    }
    for(int i = 0;i<n;i++){
        cout<<vertex[i].d<<"\t";
    }
    for(int i = 0;i<n;i++){
        cout<<vertex[i].pi<<"\t";
    }
}

int main(){
    graph g;
    g.creategraph();
    g.initialize_single_source(0);
    g.bellman_ford(0);
    g.display();
}