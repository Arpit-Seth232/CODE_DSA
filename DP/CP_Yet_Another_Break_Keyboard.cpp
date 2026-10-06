// C. Yet Another Broken Keyboard

# include <bits/stdc++.h>
using namespace std;

int main(){

    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    vector<int>isAvailable(26,0);

    for(int i=0;i<k;i++){
        char ch;
        cin>>ch;

        isAvailable[ch-'a'] = 1;
    }

    vector<int>dp(n+1,-1);

    dp[0]=0;
    long long ans = 0;
    for(int i=0;i<n;i++){
        if(isAvailable[s[i]-'a']==0) dp[i+1] = 0;
        else dp[i+1] = dp[i]+1;

        ans += dp[i+1];

    }

    cout<<ans;
}