// USACO 2019 US Open Contest, Silver
// Problem 3. Fence Planning

# include <bits/stdc++.h>
using namespace std;

int bfs(int st, int &n, vector<vector<int>>&loc,vector<vector<int>>&adj, vector<int>&vis){

    vis[st]=1;
    queue<int>q;
    q.push(st);

    int minix = INT_MAX, miniy= INT_MAX;
    int maxix = INT_MIN, maxiy= INT_MIN;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        minix = min(minix,loc[node][0]),miniy = min(miniy,loc[node][1]);
        maxix = max(maxix,loc[node][0]),maxiy = max(maxiy,loc[node][1]);

        for(auto child : adj[node]){
            if(!vis[child]){
                vis[child]=1;
                q.push(child);
            }
        }
    }

    return (2*((maxix-minix) + (maxiy-miniy)));

    
    
}

int main(){

    freopen("fenceplan.in","r",stdin);
    freopen("fenceplan.out","w",stdout);

    int n,m;
    cin>>n>>m;

    vector<vector<int>>loc(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        loc[i] = {x,y};
    }

    vector<vector<int>>adj(n);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vector<int>vis(n,0);

    int mini = INT_MAX;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            int peri = bfs(i,n,loc,adj,vis);
            mini = min(mini,peri);
        }
    }

    cout<<mini;

}


