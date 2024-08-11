#include<iostream>
using namespace std;
int main(){
    int arr[100];
    int size;
    cout<<"enter the size of array"<<endl;
    cin>>size;
    int no;
    cout<<"enter no that u want to add initially"<<endl;
    cin>>no;
    cout<<"enter array"<<endl;
    for(int i=0;i<size;++i){
        cin>>arr[i];
    }
    for(int i=size;i>0;--i){
        arr[i]=arr[i-1];
    }
    arr[0]=no;
    cout<<"updated array is"<<endl;
    for(int i=0;i<=size;++i){
        cout<<arr[i]<<" ";
    }

}
