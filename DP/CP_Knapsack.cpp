// Task 2: Knapsack

# include<bits/stdc++.h>

using namespace std;

int main(){

    int S,N;
    cin>>S>>N;

    vector<long long>dp(S+1,0);
    vector<long long> cnt;

    for(int i=0;i<N;i++){

        long long v,w,k;
        cin>>v>>w>>k;

        cnt.assign(S+1,0);

        for(long long j=0;j<S-w+1;j++){
            if(dp[j]+v > dp[j+w]){
                dp[j] = dp[j-w]+v;
                cnt[j] = cnt[j-w]+1; 
            }
        }
    }

    cout<<dp[S];
}