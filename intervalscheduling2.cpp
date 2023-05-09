#include<bits/stdc++.h>
using namespace std;

struct activity{
    int start;
    int finish;
};
void count_sort(activity arr[],int n){
    int man=INT32_MIN;
    for(int i=0;i<n;i++){
        if(man<arr[i].finish){
            man=arr[i].finish;
        }
    }
    //man denotes the range for finish time
    
    int freq[man+1]={0};
    
    activity out[n];
    for(int i=0;i<n;i++){
        freq[arr[i].finish]++;
    }
    for(int i=1;i<man+1;i++){
        freq[i]+=freq[i-1];
    }
    // for(int i=0;i<10;i++){
    //     cout<<freq[i]<<" ";
    // }cout<<endl;
    for(int i=n-1;i>=0;i--){
        int j=arr[i].finish;
        freq[j]--;
        //out[freq[j]]=j;
        out[freq[j]]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=out[i];
    }
}
class Schedule{
    activity* request;
    activity* originalrequest;
    set<int> s;
    int n;
    public:
    void input(){
        cout<<"enter the number of requests: ";
        cin>>n;
        request=new activity[n];
        originalrequest=new activity[n];
        for(int i=0;i<n;i++){
            cout<<"For "<<i<<" request";
            cout<<"Enter start time: ";
            cin>>request[i].start;
            cout<<"Enter the finish time: ";
            cin>>request[i].finish;
        }
        for(int i=0;i<n;i++){
            originalrequest[i]=request[i];
        }
        for(int i=0;i<n;i++){
            s.insert(i);
        }
        
    }

    void schedule(){
        //sort(request,request+n);
        set<int> a;
        set<int> temp;
        count_sort(request,n);
        // cout<<"Here are your requests in sorted order\n";
        // display();
        while(!s.empty()){
            set<int>::iterator it=s.begin();
            int ans=*it;
            temp=s;
            a.insert(ans);
            for(auto i:s){
                if(request[i].start < request[ans].finish){
                    temp.erase(i);
                }
            }
            s.clear();
            s=temp;
            temp.clear();
        }
        //
        set<int> answer;
        for(auto m:a){
            for(int i=0;i<n;i++){
                if(request[m].finish == originalrequest[i].finish && request[m].start==originalrequest[i].start){

                    answer.insert(i);
                }
            }
        }
        cout<<"Requests will be in processed in following order:\n";
        for(auto i: answer){
            cout<<i<<" ";
        }cout<<endl;
    }
    void display(){
       
        for(int i=0;i<n;i++){
            cout<<i<<endl;
            cout<<originalrequest[i].start<<" "<<originalrequest[i].finish<<endl;
        }
    }
};
int main(){
    int n=9;
    Schedule s1;
    s1.input();
   
    s1.schedule();
    
}