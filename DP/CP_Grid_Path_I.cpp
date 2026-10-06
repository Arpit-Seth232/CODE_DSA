// CSES Problem Set
// Grid Paths I

# include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

// recursive

// int calc (int i, int j, int &n, vector<vector<char>>&grid, vector<vector<int>>&dp){
//     if(i==n-1 && j==n-1){
//         return 1;
//     }

//     if(i>=n || j>=n || grid[i][j]=='*'){
//         return 0;
//     }

//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }

//     int ways = (calc(i,j+1,n,grid,dp)%mod + calc(i+1,j,n,grid,dp)%mod)%mod;

//     return dp[i][j] = ways;

// }

// int main(){

//     int n;
//     cin>>n;

//     vector<vector<char>>grid(n,vector<char>(n));

//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cin>>grid[i][j];
//         }
//     }

//     if(grid[0][0] == '*' || grid[n-1][n-1] == '*'){
//         cout<<0;
//     }

//     else{
//     vector<vector<int>>dp(n,vector<int>(n,-1));

//     cout<<calc(0,0,n,grid,dp);
//     }
// }

// iterative

int main(){

    int n;
    cin>>n;

    vector<vector<char>>grid(n,vector<char>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }

    if(grid[0][0] == '*' || grid[n-1][n-1] == '*'){
        cout<<0;
    }

    else{
    vector<vector<int>>dp(n,vector<int>(n,0));
    
    for(int j=0;j<n;j++){
        if(grid[0][j]=='.') dp[0][j] = 1;
        else break;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){

            if(grid[i][j]=='*') continue;
            else{

                int val = 0;

                if(i-1>=0) val = (val%mod + dp[i-1][j]%mod)%mod;
                if(j-1>=0) val = (val%mod + dp[i][j-1]%mod)%mod;

                dp[i][j] = (dp[i][j]%mod + val%mod)%mod;
            }
        }
    }

    cout<<dp[n-1][n-1];


    
    }

}
