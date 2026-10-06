// CSES Problem Set
// Coin Combinations II

# include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int main(){

    ios_base::sync_with_stdio(0);
	cin.tie(0); 

    int n, target;
    cin>>n>>target;

    vector<int>v(n);
    
    for(int i=0;i<n;i++) cin>>v[i];
//    sort(v.begin(),v.end());

    vector<int>dp(target + 1,0);

    dp[0] = 1;

    for(int i=0;i<n;i++){

        for(int j=0;j<=target;j++){
        // if(dp[j]== 0) continue;

        
            if(j+v[i]<=target){
                dp[j+v[i]] = (dp[j+v[i]]%mod + dp[j]%mod)%mod;
            }
            // else{
            //     break;
            // }
            
        }
    }

    cout<<dp[target];
    }

    
