// C. Mortal Kombat Tower

// recursive

# include <bits/stdc++.h>

using namespace std;

// int calc(int i, int k, int &n,vector<int>&v, vector<vector<int>>&dp ){
//     if(i>=n){
//         return 0;
//     }

//     if(dp[i][k]!=1e8){
//         return dp[i][k];
//     }

//     int val = 1e8;
//     if(k==0){

//         val = min(val, v[i]+calc(i+1,1,n,v,dp));
//         if(i+2<=n) val = min(val, v[i]+v[i+1]+calc(i+2,1,n,v,dp));
//     }
//     else{
//         val = min(val, calc(i+1,0,n,v,dp));
//         if(i+2<=n) val = min(val, calc(i+2,0,n,v,dp));
//     }

//     return dp[i][k] = val;

// }

// int main(){

//     int t;
//     cin>>t;

//     int n;
//     for(int i=0;i<t;i++){
//         cin>>n;
//         vector<int>v(n);

//         for(int i=0;i<n;i++) cin>>v[i];

//         vector<vector<int>>dp(n,vector<int>(2,1e8));

//         cout<<calc(0,0,n,v,dp)<<endl;
//     }

// }


// iterative

int main(){

    
    int t;
    cin>>t;

    int n;
    for(int i=0;i<t;i++){
        cin>>n;
        vector<int>v(n);

        for(int i=0;i<n;i++) cin>>v[i];

        vector<vector<int>>dp(n+1,vector<int>(2,1e8));

        dp[0][0]=0;

        for(int i=0;i<n;i++){

            for(int k=0;k<2;k++){

                if(dp[i][k]==1e8) continue;

                if(k==0){

                    dp[i+1][1] = min(dp[i+1][1], v[i]+dp[i][k]);
                    if(i+2<=n) dp[i+2][1] = min(dp[i+2][1], v[i]+v[i+1]+dp[i][k]);
                }
                else{

                    dp[i+1][0] = min(dp[i+1][0],dp[i][k]);
                    if(i+2<=n)dp[i+2][0] = min(dp[i+2][0],dp[i][k]);
                }
            }
        }

        cout<<min(dp[n][0],dp[n][1])<<endl;
    }

}