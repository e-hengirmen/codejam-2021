#include <iostream>

using namespace std;

#define ll long long

int findMinIndex(int first,int n,int *arr){
    ll MIN=999999999;
    int index;
    for(int i=first;i<n;i++){
        if(arr[i]<MIN)MIN=arr[i],index=i;
    }
    return index;
}

void reverse(int *arr,int emptyIndex,int minIndex){
    int temp;
    for(;emptyIndex<minIndex;emptyIndex++,minIndex--){
        temp=arr[minIndex];
        arr[minIndex]=arr[emptyIndex];
        arr[emptyIndex]=temp;
    }
}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int *i=arr;i<arr+n;i++)cin>>*i;
    int res=0;
    
    for(int i=0;i<n-1;i++){
        int minIndex=findMinIndex(i,n,arr);
        reverse(arr,i,minIndex);
        res+=minIndex+1-i;
    }
    cout<<res<<endl;
    
}


int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"case #"<<i<<": ";
        solve();
    }
}