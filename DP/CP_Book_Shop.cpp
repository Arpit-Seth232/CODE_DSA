// CSES : Book Shop



# include <bits/stdc++.h>

using namespace std;

// Recursive
// int calc(int i,int x, int &n, vector<pair<int,int>>&v, vector<vector<int>>&dp){

//     if(x==0 || i>=n || x<v[i].first) return 0;


//     if(dp[i][x]!= -1){
//         return dp[i][x];
//     }

//     int take = v[i].second + calc(i+1,x-v[i].first,n,v,dp);
//     int not_take = calc(i+1,x,n,v,dp);

//     return dp[i][x] = max(take,not_take);

// }

// int main(){

//     int n,x;
//     cin>>n>>x;

//     vector<int>price(n);
//     vector<int>pages(n);

//     for(int i=0;i<n;i++){
//         cin>>price[i];
//     }

//     for(int i=0;i<n;i++){
//         cin>>pages[i];
//     }

//     vector<pair<int,int>>v(n);
//     for(int i=0;i<n;i++){
//         v[i] = {price[i],pages[i]};
//     }

//     sort(v.begin(),v.end());

//     vector<vector<int>>dp(n,vector<int>(x+1,-1));

//     cout<<calc(0,x,n,v,dp);

// }


int main(){

    int n,x;
    cin>>n>>x;

    vector<int>price(n);
    vector<int>pages(n);

    for(int i=0;i<n;i++){
        cin>>price[i];
    }

    for(int i=0;i<n;i++){
        cin>>pages[i];
    }

    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++){
        v[i] = {price[i],pages[i]};
    }

    vector<vector<int>>dp(n+1,vector<int>(x+1,0));


    for(int i=0;i<n;i++){
        
        for(int j=0;j<=x;j++){

            dp[i+1][j] = max(dp[i+1][j],dp[i][j]);

            if(j + v[i].first <= x) dp[i+1][j+v[i].first] = max(dp[i+1][j+v[i].first], dp[i][j]+v[i].second);
        }   
    }

    cout<<dp[n][x];


    

}

