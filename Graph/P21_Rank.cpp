// https://dmoj.ca/problem/acsl1p4

#include <bits/stdc++.h>
using namespace std;

int calc(int node, int &st_node,vector<int>&vis,  vector<vector<int>>&adj){
    vis[node] = 1;

    for(auto child : adj[node]){
        if(child == st_node){
            return 1;
        }
        else if (!vis[child]){
            if(calc(child,st_node,vis,adj)) return 1;
        }
    }

    vis[node]=0;
    return 0;
}




int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>adj(n);

    for(int i=0;i<m;i++){
        int u,v,a,b;
        cin>>u>>v>>a>>b;

        if(a>b) adj[u-1].push_back(v-1);
        else adj[v-1].push_back(u-1);
    }

    vector<int>vis(n,0);
   

    int cnt = 0;

    for(int i=0;i<n;i++){
        vis.clear();
        vis.resize(n,0);
        cnt += calc(i,i,vis,adj);
    }


    cout<<cnt;



    
    
   

}