// A. Office Keys

# include <bits/stdc++.h>

using namespace std;

int main(){

    int n,k,p;
    cin>>n>>k>>p;

    vector<long long>a(n);
    vector<long long>b(k);

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<k;i++) cin>>b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    vector<vector<long long>>dp(k+1,vector<long long>(n+1,1e17));

    dp[0][0]=0;

    for(int i=0;i<k;i++){
        for(int j=0;j<=n;j++){

            dp[i+1][j]= min(dp[i+1][j] , dp[i][j]);

            if(j<n) dp[i+1][j+1] = min(dp[i+1][j+1] , max(dp[i][j], abs(b[i]-a[j]) + abs(b[i]-p)));
        }

    }

    cout<<dp[k][n];

}