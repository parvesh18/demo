#include<iostream>
#include<climits>
using namespace std;
int merge(int a[],int p,int q,int r){//p is pointing to elem 1 and r in pointing to last elem and q is pointing to last elem of subarray and q+1 is pointing to elem 1 of another subarray
    int n1=q-p+1;
    int n2 =r-q;
    int L[n1+2];
    int R[n2+2];
    for(int i=1;i<=n1;i++){
        L[i]=a[p+i-1];
    }
    for(int j=1;j<=n2;j++){
        R[j]=a[q+j];
    }
    L[n1+1]=R[n2+1]=INT_MAX;
    int i=1;
    int j=1;
    for(int k=p;k<=r;k++){
        if(L[i]<=R[j]){
            a[k]=L[i];
            i++;
        }
        else{
        a[k]=R[j];
        j++;}
    }
}
void MergeSort(int a[],int p,int r){
    if(p<r){
        int q=(p+r)/2;
        MergeSort(a,p,q);
        MergeSort(a,q+1,r);
        merge(a,p,q,r);
    }
}
int main(){
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<"Sorted array is: ";
    MergeSort(a,1,n);
    for(int j=1;j<=n;j++){
        cout<<a[j]<<" ";
    }

}