#include<iostream>
using namespace std;
int main(){
    int array[20];
    int size;
    cout<<"size of array is"<<endl;
    cin>>size;
    int pos;
    cout<<"enter position of which element you want to delete"<<endl;
    cin>>pos;
    cout<<"enter array"<<endl;
    for(int i=0;i<size;i++){
        cin>>array[i];
}

for(int i=pos;i<size-1;i++){
    array[i]=array[i+1];
}
for(int i=0;i<size-1;i++){
    cout<<array[i]<<" ";
}

}



