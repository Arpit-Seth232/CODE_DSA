// CSES Problem Set
// Edit Distance

# include <bits/stdc++.h>

using namespace std;

int calc(int i, int j, int &n, int &m, string &s1, string &s2,  vector<vector<int>>&dp){

    if(i>=n && j>=m){
        return 0;
    }

    if(i>=n && j<m){
        return m-j;
    }

    if(i<n && j>=m){
        return n-i;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int val = INT_MAX;

    if(s1[i] == s2[j]) val = min(val,calc(i+1,j+1,n,m,s1,s2,dp));

    else{

        int add = 1 + calc(i,j+1,n,m,s1,s2,dp);
        int replace = 1 + calc(i+1,j+1,n,m,s1,s2,dp);
        int rem = 1 + calc(i+1,j,n,m,s1,s2,dp);

        val = min({val,add,replace,rem});
    }

    return dp[i][j] = val;
    
}

int main(){

    string s1,s2;

    cin>>s1>>s2;

    int n = s1.size();
    int m = s2.size();


    vector<vector<int>>dp(n,vector<int>(m,-1));

    cout<<calc(0,0,n,m,s1,s2,dp);

}

