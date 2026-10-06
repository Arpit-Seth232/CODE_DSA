// Atcoder : A - Frog 1 

# include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int>v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    vector<long long>dp(n,1e10);

    dp[0] = 0;

    for(int i=0;i<n;i++){
        dp[i+1] = min(dp[i+1], dp[i]+abs(v[i]-v[i+1]));
        if(i+2 < n) dp[i+2]= min(dp[i+2], dp[i]+abs(v[i]-v[i+2]));
    }

    cout<<dp[n-1];


}