# include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    string hr,vr;
    cin>>hr>>vr;

    // vector<vector<int>>adj(n*m);
    vector<vector<int>>dist(n*m,vector<int>(n*m,-1));

    for(int i=0;i<hr.size();i++){
        char c = hr[i];

        int low = i*m, high = (i*m) + (m-1);

        if(c == '<'){
            for(int j=high;j>low;j--){
                // adj[j].push_back(j-1);
                dist[j][j-1] = 1;
            }
        }
        else{
            for(int j=low;j<high;j++){
                // adj[j].push_back(j+1);
                dist[j][j+1] = 1;
            }
        }


    }

    for(int i=0;i<vr.size();i++){
        char c = vr[i];

        int low = i, high = i+((n-1)*m);
        if(c=='^'){
            for(int j=high;j>low;j-=m){
                // adj[j].push_back(j-m);
                dist[j][j-m]=1;
            }
        }
        else{
            for(int j=low;j<high;j+=m){
                // adj[j].push_back(j+m);
                dist[j][j+m]=1;
            }
        }
    }


    for(int i=0;i<n*m;i++){
        dist[i][i]=0;
    }

    for(int k=0;k<n*m;k++){

        for(int i=0;i<n*m;i++){
            for(int j=0;j<n*m;j++){

                if(dist[i][k]==-1 || dist[k][j]==-1) continue;

                if(dist[i][j]==-1){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
                else{
                    dist[i][j] = min(dist[i][j], (dist[i][k] + dist[k][j]));
                }
            }
        }
    }

    string poss = "YES";

    for(int i=0;i<n*m;i++){
        for(int j=0;j<n*m;j++){
            if(dist[i][j]==-1){
                poss = "NO";
                break;
            }
        }
    }

    cout<<poss;



}