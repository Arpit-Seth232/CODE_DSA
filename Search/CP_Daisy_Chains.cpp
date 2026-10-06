// USACO 2016 US Open Contest, Bronze
// Problem 1. Diamond Collector

# include <bits/stdc++.h>
using namespace std;

int main(){

    // freopen("diamond.in", "r", stdin);
    int n;
    cin>>n;

    int cnt = n;

    vector<int>v(n),pre(n);
    int maxi = 0;

    for(int i=0;i<n;i++){
        cin>>v[i];
        maxi = max(maxi,v[i]);
    }

    if(n>1){
    vector<vector<int>>freq(n,vector<int>(maxi+1,0));

    pre[0] = v[0];
    for(int k=0;k<n;k++){
    freq[k][v[0]]++;
    }

    for(int i=1;i<n;i++){
        pre[i] = pre[i-1] + v[i];
         for(int k=i;k<n;k++){
            freq[k][v[i]]++;
        }
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int avg = pre[j];
            if(i>0) avg-=pre[i-1];
            if(avg % (j-i+1)!=0) continue;
            avg = avg/(j-i+1);
            
            int flw = freq[j][avg];
            if(i>0) flw -= freq[i-1][avg];

            if(flw > 0){
                cnt++;
                // cout<<i<<" "<<j<<endl;
            }    
            
        }
    }

}


    // freopen("diamond.out", "w", stdout);
    cout<<cnt;
}