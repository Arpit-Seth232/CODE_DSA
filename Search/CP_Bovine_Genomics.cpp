// USACO 2017 US Open Contest, Bronze
// Problem 2. Bovine Genomics

# include <bits/stdc++.h>
using namespace std;
int main(){

    freopen("cownomics.in","r",stdin);

    int n,m;
    cin>>n>>m;

    vector<vector<char>>v(2*n,vector<char>(m));

    for(int i=0;i<2*n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }

    int cnt = 0;
    for(int i=0;i<m;i++){

        int PA = 0, PC = 0, PG =0 , PT = 0;

        for(int j=0;j<n;j++){
            if(v[j][i]=='A') PA=1;
            if(v[j][i]=='C') PC=1;
            if(v[j][i]=='G') PG=1;
            if(v[j][i]=='T') PT=1;
        }

        bool inc = true;
        for(int j=n;j<2*n;j++){
            if(v[j][i]=='A' && PA==1){
                inc = false;
                break;
            }
            if(v[j][i]=='C' && PC==1){
                inc = false;
                break;
            }
            if(v[j][i]=='G' && PG==1){
                inc = false;
                break;
            }
            if(v[j][i]=='T' && PT==1){
                inc = false;
                break;
            }
        }

        if(inc) cnt++;
    }

    freopen("cownomics.out","w",stdout);

    cout<<cnt;
}