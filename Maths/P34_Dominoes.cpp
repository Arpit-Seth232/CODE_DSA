// https://codeforces.com/problemset/problem/1499/A

# include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k1,k2,w,b;
        cin>>n>>k1>>k2>>w>>b;

        int tw = k1+k2;
        int tb = (2*n - tw);

        if((tw/2) >= w && (tb/2)>=b){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }

    }
}