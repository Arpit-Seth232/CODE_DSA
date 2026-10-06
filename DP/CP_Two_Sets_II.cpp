// CSES Problem Set
// Two Sets II

# include<bits/stdc++.h>

using namespace std;

int mod = 1e9+7;

// int calc(int i, int &n, int sum, int &t_sum, vector<vector<int>>&dp){
//     if(sum == t_sum){
//         return 1;
//     }

//     if(i>n || sum > t_sum){
//         return 0;
//     }


//     if(dp[i][sum]!=-1){
//         return dp[i][sum];
//     }

//     int not_take = calc(i+1,n,sum,t_sum,dp);
//     int take = calc(i+1,n,sum+i,t_sum,dp);

//     return dp[i][sum] = (take%mod + not_take%mod)%mod;
    
// }

int main(){

    int n;
    cin>>n;

    int t_sum = 0;

    for(int i=1;i<=n;i++){
        t_sum += i;
    }

    if(t_sum%2==1){
        cout<<0;
    }

    else{

        int val = t_sum/2;
        vector<vector<int>>dp(n+1,vector<int>(val+1,0));

        // int ans =calc(1,n,0,val,dp);

        dp[0][0]=1;

        for(int i=0;i<n;i++){

            for(int j=0;j<=val;j++){

                dp[i+1][j] = (dp[i+1][j]%mod + dp[i][j]%mod)%mod;

                if(j+i+1 <=val) dp[i+1][j+i+1] = (dp[i+1][j+i+1]%mod + dp[i][j]%mod)%mod;
            }

        }

        int ans = dp[n][val];

        long long inv2 = 5e8+4; // precomputed inverse of 2 under mod
        cout << (ans * inv2) % mod;

    }
}