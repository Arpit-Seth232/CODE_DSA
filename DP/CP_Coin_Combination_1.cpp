// CSES Problem Set
// Coin Combinations I

# include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int main(){

    int n, target;
    cin>>n>>target;

    vector<int>v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    vector<int>dp(target + 1, 0);

    dp[0] = 1;

    for(int i=0;i<target;i++){

        if(dp[i] == 0) continue;

        for(int j=0;j<n;j++){

            if(i+v[j]<=target){
                dp[i+v[j]] = (dp[i+v[j]]%mod + dp[i]%mod)%mod;
            }
        }
    }

    cout<<dp[target];
}