#include<iostream>
using namespace std;
void bubblesort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        
        for(int j=0;j<size-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                
            }
            
            
        }
        
            }
            cout<<"sorted array is"<<endl;
            
  for(int i=0;i<size;i++){
                cout<<arr[i]<<" ";

    }          
}

int main(){
    int arr[30];
    int size;
    cout<<"size of array is"<<endl;
    cin>>size;
    cout<<"enter array"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    bubblesort(arr,size);
    
}