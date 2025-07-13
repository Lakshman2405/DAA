#include<iostream>
#include<fstream>
using namespace std;
# define max 1000

struct node{
    float data;
    node* next;
    node(){
        data = 0;
        next = NULL;
    }
};

void insert_order(node*& first,float x,int& count){
    node* n = new node();
    n->data = x;
    node* temp = first;
    if (first == NULL || first->data >= x){
        n->next = first;
        first = n;
        return;
    }
    while (temp->next != NULL && temp->next->data <x){
        count++;
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
    return;
}

void bucketsort(float (&a)[10000],int n){
    float b[10000];
    int count = 0;
    node* bucket[max];
    for(int i = 0;i<max;i++){
        bucket[i] = NULL;
    }
    for(int i = 0;i<n;i++){
        b[i] = 0;
    }
    for(int i = 0;i<n;i++){
        count++;
        int bind = a[i] * max;
        insert_order(bucket[bind],a[i],count);
    }
    int index = 0;
    for(int i = 0;i<max;i++){
        node* temp = bucket[i];
        while(temp != NULL){
            count++;
            b[index++] = temp->data;
            temp = temp->next;
        }
    }
    cout<<"The no. of counts for "<<n<<" input is "<<count<<endl;
}

int main(){
    int n;
    float a[10000];
    cout<<"Enter the no. of input : ";
    cin>>n;
    ifstream fin("input_bsort.txt");
    for(int i = 0;i<n;i++){
        fin>>a[i];
    }
    bucketsort(a,n);
    fin.close();
}