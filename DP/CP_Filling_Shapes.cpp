// A. Filling Shapes

# include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int>dp(n+1,-1);
    dp[0] = 1;
    dp[1] = 0;

    for(int i=2;i<=n;i++){
        if(i%2==1) dp[i] = 0;
        else dp[i] = 2*dp[i-2];
    }

    cout<<dp[n]<<endl;
}

