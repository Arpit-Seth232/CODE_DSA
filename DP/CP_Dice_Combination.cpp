// CSES Problem Set
// Dice Combinations

# include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int main(){

    int target;
    cin>>target;

    vector<int>dp(target+1,0);

    
    dp[0] = 1;

    for(int i=0;i<target;i++){

        for(int j=1;j<=6;j++){

            if(i+j <= target ) dp[i+j] = (dp[i+j]%mod + dp[i]%mod)%mod;
        }
    }

    cout<<dp[target];

}