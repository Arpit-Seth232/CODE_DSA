// C. The Values You Can Make

# include <bits/stdc++.h>

using namespace std;



int main(){

    int n,k;
    cin>>n>>k;

    vector<int>v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }

    vector<vector<int>>dp(k+1,vector<int>(k+1,0));

    dp[0][0]=1;

    for(int coin : v){

    for(int i=k;i>=0;i--){

        for(int j=k;j>=0;j--){

           if(coin+j<=k) dp[i][j+coin] |= dp[i][j];

            if(coin+i<=k && coin+j<=k) dp[i+coin][j+coin] |= dp[i][j];
        }
    }

}

    

    vector<int>ans;

    for(int i=0;i<=k;i++){
        
        if(dp[i][k]){
            ans.push_back(i);
        }
    
}

    cout<<ans.size()<<endl;
    for(int c : ans) cout<<c<<" ";


    
}