// CSES Problem Set
// // Longest Common Subsequence

// recursive

# include<bits/stdc++.h>
using namespace std;



int calc(int i, int j, int &n, int &m, vector<int>&a,vector<int>&b,vector<vector<int>>&dp){
    if(i>=n || j>=m){

       
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int len = 0;
    if(a[i] == b[j]){
       
        len = max(len, 1 + calc(i+1,j+1,n,m,a,b,dp));
       
    }
    else{

        len = max(len, calc(i+1,j,n,m,a,b,dp));
        len = max(len, calc(i,j+1,n,m,a,b,dp));
    }

    return dp[i][j] = len;
}

int main(){

    int n,m;
    cin>>n>>m;

    vector<int>a(n),b(m);

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];

    vector<vector<int>>dp(n,vector<int>(m,-1));

    
    int max_len = calc(0,0,n,m,a,b,dp);
    
    cout<<max_len<<endl;
    
    
    int i=0,j=0;
    while(i<n && j<m){

        if(a[i] == b[j]){
            cout<<a[i]<<" ";
            i++;j++;
        }
        else if(i+1<n && j+1<m &&  dp[i+1][j] >= dp[i][j+1]){
            i++;
        }
        else if(i+1<n && j+1<m &&  dp[i+1][j] <= dp[i][j+1]){
            j++;
        }
        else if(i+1 < n){
            i++;
        }
        else{
            j++;
        }
    }


}