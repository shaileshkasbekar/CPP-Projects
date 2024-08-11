#include<iostream>
using namespace std;
int main(){
    int size;
cout<<"enter size of array"<<endl;
cin>>size;
int arr[size];
 cout<<"enter the elements of array"<<endl;
for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int choice;
 cout<<"enter users choice  to update index element"<<endl;
cin>>choice;
    int new_element;
    cout<<"enter element which u want to add"<<endl;
    cin>>new_element;
    swap(arr[choice],new_element);
    cout<<"new array is"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    

}