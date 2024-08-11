#include<iostream>
using namespace std;
int main(){
    int array[50];
    int size;
    cout<<"enter the size of array"<<endl;
    cin>>size;
    int element;
    cout<<"enter the element u want to add"<<endl;
    cin>>element;
    int position;
    cout<<"enter the position of element in which u want to add element"<<endl;
    cin>>position;
    cout<<"enter array"<<endl;
    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    
    for(int i=size;i>position;i--){
        
            array[i]=array[i-1];
        }
    
    array[position]=element;
    cout<<"enter updated array"<<endl;
    for(int i=0;i<=size;i++){
        cout<<array[i]<<" ";
    }
    }
