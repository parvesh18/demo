#include<iostream>
using namespace std;

void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        int key=arr[i];
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){
    int arr[8]={5,3,2,7,8,5,1,9};
    insertionsort(arr,8);
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}