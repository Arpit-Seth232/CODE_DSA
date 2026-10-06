// https://codeforces.com/problemset/problem/1658/B

# include <bits/stdc++.h>
using namespace std;

int mod = 998244353;

vector<int> fact(501,1);

void create(){
    for(int i=2;i<501;i++){
        fact[i] = (1LL * i * fact[i-1])%mod;
    }
}

int main(){

    int t;
    cin>>t;

    create();

    while(t--){
        int n;
        cin>>n;

        if(n%2==0){
            int val = fact[n/2];
            int ans = (1LL * val * val)%mod;
            cout<<ans<<endl;
        }
        else{
            cout<<0<<endl;  
        }

    }
}