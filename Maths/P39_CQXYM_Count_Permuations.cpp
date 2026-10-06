// https://codeforces.com/problemset/problem/1581/A

# include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
int N = 1e5;

vector<int>fact(2*N+1, 1);

void calc(){

    for(int i=2;i<2*N+1;i++){
        fact[i] = (1LL * i* fact[i-1])%mod;
    }
}

int power(int a, int b){
    if(b==0) return 1;

    int val = power(a,b/2);
    int ans = (1LL * val * val)%mod;
    if(b%2 == 1) ans = (1LL * a * ans)%mod;
    
    return ans;
}

int main(){
    int t;
    cin>>t;

    calc();

    while(t--){
        int n;
        cin>>n;

        int ans = (1LL * fact[2*n] * power(2,mod-2))%mod;

        cout<<ans<<endl;
    }

    
}