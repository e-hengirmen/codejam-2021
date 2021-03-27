#include <iostream>
#include <cmath>

using namespace std;

#define ll long long

void solve(){
    ll res=0;
    int n,c;
    cin>>n>>c;
    if(c>n*(n+1)/2-1||n-1>c){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    c-=n-1;

    int arr[n];
    //for(int i=0;i<n;i++)arr[i]=-1;      //delete later

    int left_right[2]{0,n-1},point=n-1;
    bool right_big=1;
    for(int i=0;i<n;i++){
        if(c>=point){       //&&flag for yap üstü
            //TODO
            arr[left_right[right_big]]=n-point;
            if(right_big==true)left_right[right_big]--;
            else left_right[right_big]++;
            right_big=!right_big;



            c-=point;
            point--;
        }
        else{
            arr[left_right[!right_big]]=n-point;
            point--;
            if(!right_big==true)left_right[!right_big]--;
            else left_right[!right_big]++;


        }
    }



    for(int i=0;i<n;i++)cout<<arr[i]<<' ';
    cout<<endl;
    
}


int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"case #"<<i<<": ";
        solve();
    }
}