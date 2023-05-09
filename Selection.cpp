#include<iostream>
using namespace std;

void selectionsort(int arr[],int n){
    int max;
    for(int i=0;i<n;i++){
        max=n-i-1;
        for(int j=0;j<n-i-1;j++ ){
            if(arr[max] < arr[j]){
                max=j;
            }
            
        }swap(arr[n-i-1],arr[max]);
    }
}
int main(){
    int arr[8]={3,8,4,7,5,6,9,2};
    selectionsort(arr,8);
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}