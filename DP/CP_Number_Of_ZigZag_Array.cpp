// Leetcode 3699. Number of ZigZag Arrays I



// DP Memoisation Solution TLE - O(N*R^2) #######################################################################


// class Solution {
// public:
//     int mod = 1e9+7;

//     int calc(int i,int x, int dir, int &n, int &l, int &r, vector<vector<vector<int>>>&dp){
//         if(i>=n){
//             return 1;
//         }
//         if(dp[i][x][dir]!=-1){
//             return dp[i][x][dir];
//         }
        
//         int ways = 0;
//         if(x==0){
            
//             for(int k=l;k<=r;k++){
//                 ways = (ways%mod +calc(i+1,k,1,n,l,r,dp)%mod)%mod;
//                 ways = (ways%mod + calc(i+1,k,0,n,l,r,dp)%mod)%mod;
//             }
//         }

//         else if(dir == 0){
//             for(int k=x+1;k<=r;k++){
//                 ways = (ways%mod  + calc(i+1,k,1,n,l,r,dp)%mod)%mod;
//             }
//         }
//         else{
//             for(int k=x-1;k>=l;k--){
//                 ways = (ways%mod  + calc(i+1,k,0,n,l,r,dp)%mod)%mod;
//             }
//         }

//         return dp[i][x][dir] = ways;



//     }
//     int zigZagArrays(int n, int l, int r) {
//         vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2001,vector<int>(2,-1)));

//         return calc(0,0,0,n,l,r,dp);
//     }
// };




// Tagda Optimisation : O(n*r) ##########################################################################



// class Solution {
// public:
//     int mod = 1e9+7;

//     int zigZagArrays(int n, int l, int r) {
//         vector<vector<int>>nex(r+1,vector<int>(2,-1));
//         vector<vector<int>>curr(r+1,vector<int>(2,-1));

//         for(int i=l;i<=r;i++){
//             nex[i][0] = 1;
//             nex[i][1] = 1;
//         }

//         for(int i=n-1;i>=1;i--){

//             vector<long long>prefix0(r+2,0);
//             vector<long long>suffix1(r+2,0);

//             for(int x=l;x<=r;x++){
//                 prefix0[x] = (prefix0[x-1]%mod + nex[x][0]%mod);
//             }

//             for(int x=r;x>=l;x--){
//                 suffix1[x] = (suffix1[x+1]%mod + nex[x][1]%mod)%mod;
//             }

//             for(int x=l;x<=r;x++){
//                 curr[x][0] = suffix1[x+1];
//                 curr[x][1] = prefix0[x-1];
//             }

//             swap(curr,nex);
//         }

//         int ans =0;

//         for(int x=l;x<=r;x++){
//             ans = (ans%mod + nex[x][0]%mod)%mod;
//             ans = (ans%mod + nex[x][1]%mod)%mod;
//         }

//         return ans;
       
//     }
// };