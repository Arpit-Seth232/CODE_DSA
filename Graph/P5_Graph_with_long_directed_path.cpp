# include <bits/stdc++.h>
using namespace std;

vector<int>vis;
bool hasOddCycle(int st,  vector<vector<int>>&adj){
    queue<pair<int,int>>q;
    q.push({st,0});

    vis[st] = 0;

    while(!q.empty()){
        int node = q.front().first;
        int color = q.front().second;

        q.pop();

        for(auto child : adj[node]){
            if(vis[child] == color) return true;
            else if(vis[child] == -1){
                q.push({child,!color});
                vis[child] = !color;
            }
        }
    }

    return false;
}

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>>edges;

    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);

        edges.push_back({u-1,v-1});
    }

    vis.resize(n,-1);

    if(hasOddCycle(0,adj)){
        cout<<"NO";
    }
    else{
        cout<<"YES"<<endl;

        for(auto it : edges){
            int u = it[0];

            if(vis[u]==0) cout<<0;
            else cout<<1;
        }
    }

}