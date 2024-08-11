#include<iostream>
using namespace std;
void selectionsort(int array[],int n,int min){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[i]>array[j]){
                min=array[i];
            swap(array[i],array[j]);
        }
    }
    }
    cout<<"sorted array is"<<endl;
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
}
}
int main(){
    int size;
    int min=0;
    cout<<"enter the size of array"<<endl;
    cin>>size;
    int array[30];
    cout<<"enter array"<<endl;
    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    selectionsort(array,size,min);
}