// C. Vitamins

# include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>> n;

    vector<vector<long long>>dp(n+1,vector<long long>(8,1e8));

    for(int i=0;i<n;i++){

        long long cost;
        string s;

        cin>>cost>>s;

        int str_mask = 0;

        for(int pos = 0;pos<3;pos++){

            char vita = 'C' - pos;

            bool have = false;
            for(char ch : s){
                if(ch == vita){
                    have = true;
                    break;
                }
            }

            if(have){
                str_mask += (1<<pos);    //  (2^pos)
            }
        }

        dp[0][0] = 0;

        for(int mask = 0; mask<=7;mask++){

            dp[i+1][mask] = min(dp[i+1][mask] , dp[i][mask]);
            dp[i+1][mask | str_mask] = min(dp[i+1][mask | str_mask] , dp[i][mask]+cost);

        }

    }

     long long ans = dp[n][7];

        if(ans == 1e8){
            cout<<-1;
        }
        else{
            cout<<ans;
        }

}