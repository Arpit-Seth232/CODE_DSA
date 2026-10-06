// CSES Problem Set
// Minimizing Coins

# include <bits/stdc++.h>

using namespace std;

int main(){

    int n,target;
    cin>>n>>target;

    vector<int>v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    vector<int>dp(target+1,1e8);

    dp[0] = 0;

    for(int i=0;i<target;i++){

        for(int j=0;j<n;j++){

            if(i+v[j]<=target) dp[i+v[j]] = min(dp[i+v[j]] , 1 + dp[i]);
        }
    }

    cout<<(dp[target] == 1e8 ? -1 : dp[target]);
}