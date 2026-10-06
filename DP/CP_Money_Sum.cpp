// CSES Problem Set
// Money Sums

# include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int>v(n);
    int total_sum = 0;

    for(int i=0;i<n;i++) {
        cin>>v[i];
        total_sum += v[i];
    }

    vector<int>dp(total_sum+1,0);
    dp[0] = 1;

    for(int coin : v){

        for(int i = total_sum-coin;i>=0;i--){
            if(dp[i]){
                dp[i+coin] = 1;
            }
        }
    }

    vector<int>ans;

    for(int i=1;i<=total_sum;i++){
        if(dp[i]){
            ans.push_back(i);
        }
    }

    cout<<ans.size()<<endl;
    for(int c : ans) cout<<c<<" ";

    

}