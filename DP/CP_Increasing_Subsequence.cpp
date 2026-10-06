// CSES Problem Set
// Increasing Subsequence

# include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int>v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    vector<int>dp(n,0);

    dp[n-1] = 1;

    for(int i=n-2;i>=0;i--){
        int maxi = 0;

        for(int j=i+1;j<n;j++){
            if(v[j]>v[i]){
                maxi = max(maxi,dp[j]);
            }
        }

        dp[i] = 1+maxi;
    }

    int ans = 0;

    for(int i=0;i<n;i++){
        ans = max(ans,dp[i]);
    }

    cout<<ans;

}