#include <iostream>
using namespace std;
int binarysearch(int arr[],int size,int searching){
  int start=0;
  int end=size-1;
  int mid=(start+end)/2;
  while(start<=end){
    if(arr[mid]==searching){
    
      return mid;
    }
    if(searching>arr[mid]){
      start=mid+1;
    }
    else{
      end=mid-1;
    }
    mid=start+(end-start)/2;
  }
  return -1;
}
    
  

int main() {
  int search;
  
  cout<<"element that u want to search"<<endl;
  cin>>search;
  int arr[50];
  int size;
  cout<<"enter the size of array"<<endl;
  cin>>size;
  cout<<"enter array"<<endl;
  for(int i=0;i<size;i++){
    cin>>arr[i];
  }
  cout<<binarysearch(arr,size,search)<<endl;
  
}