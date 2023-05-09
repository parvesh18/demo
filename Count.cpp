#include<iostream>
using namespace std;
void count_sort(int arr[],int n){
    int freq[10]={0};
    
    int out[n];
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    for(int i=1;i<10;i++){
        freq[i]+=freq[i-1];
    }
    for(int i=0;i<10;i++){
        cout<<freq[i]<<" ";
    }cout<<endl;
    for(int i=n-1;i>=0;i--){
        int j=arr[i];
        freq[j]--;
        out[freq[j]]=j;
    }
    for(int i=0;i<n;i++){
        arr[i]=out[i];
    }
}
int main(){
    int arr[8]={2,5,3,4,6,4,2,8};
    count_sort(arr,8);
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}