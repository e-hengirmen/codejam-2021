#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int n,q,current,middle;
vector<int> vec;
int Size,Left,Right,temp;

void print(int a,int b,int c){
    cout<<a<<' '<<b<<' '<<c<<endl;
}

void SOLVE(int maxLeft,int maxRight,int Left,int Right){
    print(vec[Left],vec[Right],current);
    cin>>middle;
    int interval;
    if(middle==vec[Left]){      //soldaysa
        if(Left-1==maxLeft){    //bulduk
            vec.insert(vec.begin()+Left,current);
            return;
        }
        else{
            interval=(Left-maxLeft+1)/3;
            if(!interval)SOLVE(maxLeft,Left,maxLeft,maxLeft+1);
            else SOLVE(maxLeft,Left,maxLeft+interval,maxLeft+2*interval);
        }
    }
    else if(middle==vec[Right]){      //sağdaysa
        if(maxRight-1==Right){    //bulduk
            vec.insert(vec.begin()+maxRight,current);
            return;
        }
        else{
            interval=(maxRight-Right+1)/3;
            if(!interval)SOLVE(Right,maxRight,Right,Right+1);
            else SOLVE(Right,maxRight,Right+interval,Right+2*interval);
        }
    }
    else{       //içindeyse
        if(Right-1==Left){    //bulduk
            vec.insert(vec.begin()+Right,current);
            return;
        }
        else{
            interval=(Right-Left+1)/3;
            if(!interval)SOLVE(Left,Right,Left,Left+1);
            else SOLVE(Left,Right,Left+interval,Left+2*interval);
        }
    }

}

void solve(){
    vec.clear();
    cout<<"1 2 3"<<endl;
    cin>>middle;
    vec.push_back(-999999);
    switch(middle){
        case 1:vec.push_back(2);vec.push_back(1);vec.push_back(3);break;
        case 2:vec.push_back(1);vec.push_back(2);vec.push_back(3);break;
        case 3:vec.push_back(1);vec.push_back(3);vec.push_back(2);break;
    }
    vec.push_back(999999);
    //q--;

    Size=3;
    Left=1;
    Right=3;
    for(current=4;current<=n;current++){
        print(vec[Left],vec[Right],current);
        cin>>middle;
        int interval=Size/3;
        if(middle==vec[Left])vec.insert(vec.begin()+Left,current);
        else if(middle==vec[Right])vec.insert(vec.begin()+Right+1,current);
        else SOLVE(Left,Right,Left+interval,Left+2*interval);
        Size++;
        Right++;
    }
    for(int i=1;i<=n;i++)cout<<vec[i]<<" ";
    cout<<endl;
    cin>>temp;
}

int main(){
    int t;
    cin>>t>>n>>q;
    while(t--)solve();


}