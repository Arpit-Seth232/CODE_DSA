// USACO 2016 US Open Contest, Bronze
// Problem 1. Diamond Collector

# include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("diamond.in", "r", stdin);
    int n,k;
    cin>>n>>k;

    int maxi = 0;

    vector<int>v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end());

    int s=0,e=0;

    while(e<n && v[e]-v[s]<=k){
        e++;
    }

    maxi = e-s;

    while(e<n){

        if(v[e]-v[s]>k){
            s++;
        }

        if(v[e]-v[s]<=k){
            e++;
            maxi = max(maxi, e-s);
        }
    }


    freopen("diamond.out", "w", stdout);
    cout<<maxi;
}