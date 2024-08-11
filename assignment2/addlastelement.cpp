#include<iostream>
using namespace std;
int main(){
    int array[50];
    int size;
    int element;
    cout<<"element that you want to add in last"<<endl;
    cin>>element;
    cout<<"enter the size of array"<<endl;
    cin>>size;
    cout<<"enter array"<<endl;
    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    array[size]=element;
    cout<<"enter updated array"<<endl;
    for(int i=0;i<=size;i++){
        cout<<array[i]<<" ";

    }

}