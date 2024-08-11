#include<iostream>
using namespace std;
int main(){
    int b[30];
    int size;
    cout<<"size of array is"<<endl;
    cin>>size;
    cout<<"enter array"<<endl;
    for(int i=0;i<size;i++){
        cin>>b[i];

    }
    cout<<"updated array"<<endl;
    for(int i=0;i<size-1;i++){
        cout<<b[i]<<" ";
    }
}