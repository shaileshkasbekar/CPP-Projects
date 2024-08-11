#include<iostream>
using namespace std;
int main(){
    int arr[30];
    int size;
    cout<<"size of array is"<<endl;
    cin>>size;
    cout<<"enter array"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"updated array"<<endl;
    for(int i=1;i<size;i++){
        cout<<arr[i]<<" ";
    }

}