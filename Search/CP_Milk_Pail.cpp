// USACO 2016 February Contest, Bronze
// Problem 1. Milk Pails

# include <bits/stdc++.h>
using namespace std;

int main(){

    // freopen("pails.in", "r", stdin);
    int x,y,m;
    cin>>x>>y>>m;

    int maxi = 0;

    for(int cnt = 0;cnt <= m/x ;cnt++){
        int val = x*cnt;
        for(int j = 0;j<=m/y;j++){
            if(val+(j*y) <= m) maxi = max(maxi, val + j*y);
        }
    }

    // freopen("pails.out", "w", stdout);
    cout<<maxi;
}