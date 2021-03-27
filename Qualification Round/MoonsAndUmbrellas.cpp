#include <iostream>
#include <cmath>

using namespace std;

#define ll long long

void SOLVE(int x,int y,string s){
    int res=0;
    n=s.size();


    cout<<res<<endl;
    
}

void solve(){
    int x,y;
    string s;
    cin>>x>>y>>s;

        //for part 3
    // if(x<0||y<0){
    //     SOLVE(x,y,S);
    //     return;
    // }

    int n=s.size();
    int minY=min(x,y);
    
    int first(0),i;
    for(;first<n&&s[first]=='?';first++);
    for(i=n-1;i>=0&&s[i]=='?';i--);
    s[i+1]=0;

    int backIndex,res=0;
    char current;
    for(int i=first;s[i];i++){
        if(!i)continue;
        if(s[i-1]=='C'&&s[i]=='J')res+=x;
        if(s[i-1]=='J'&&s[i]=='C')res+=y;
        if(s[i]=='?'){
            current=s[i-1];
            backIndex=i-1;
            for(;s[i]=='?';i++);
            if(s[i]!=current){
                if(current=='C')res+=x;
                else res+=y;
            }

        }
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