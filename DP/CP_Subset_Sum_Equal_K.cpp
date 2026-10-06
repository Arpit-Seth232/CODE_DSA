// Atcoder : F - #(subset sum = K) with Add and Erase 

# include <bits/stdc++.h>

using namespace std;

int mod = 998244353;

int main(){

    int n,k;
    cin>>n>>k;

    vector<int>dp(k+1,0);
    dp[0]=1;

    char ch;
    int val;

    for(int i=0;i<n;i++){

        cin>>ch>>val;

        if(ch == '+'){

            for(int j=k;j>=0;j--){

                if(j+val <= k) dp[j+val] = (dp[j+val]%mod + dp[j]%mod)%mod;
            }

        }
        else{

            for(int j=0;j<=k;j++){

                if(j+val<=k) dp[j+val] = (dp[j+val]%mod - dp[j]%mod)%mod;
            }
        }

        cout<<dp[k]<<endl;


    }
}