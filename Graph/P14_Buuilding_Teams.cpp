// CSES Problem Set
// Building Teams

# include <bits/stdc++.h>

using namespace std;

bool calc (int st, vector<int>&vis,vector<vector<int>>&adj){
    queue<pair<int,int>>q;

    q.push({st,0});
    vis[st]=0;

    while(!q.empty()){
        auto p = q.front();
        int node = p.first , color = p.second;
        q.pop();

        for(auto child : adj[node]){
            if(vis[child]==-1){
                vis[child] = !color;
                q.push({child,!color});
            }
            else if(vis[child] == color){
                return false;
            }
        }


    }

    return true;
}

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>>adj(n);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vector<int>vis(n,-1);
    for(int i=0;i<n;i++){
        if(vis[i] == -1){
            if(!calc(i,vis,adj)){
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<vis[i]+1<<" ";
    }
}