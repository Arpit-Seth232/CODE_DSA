// https://open.kattis.com/problems/birthday

# include <bits/stdc++.h>
using namespace std;

bool bfs(int &n, vector<vector<int>>&adj, int &ru, int &rv){
    vector<int>vis(n,0);

    queue<int>q;
    q.push(0);
    vis[0] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto child : adj[node]){
            if((ru==node && rv == child) || (ru==child && rv == node)) continue;
            else if(!vis[child]){
                vis[child]=1;
                q.push(child);
            }
        }
    }

    for(int i=0;i<n;i++){
        if(!vis[i]) return false;
    }

    return true;

}

int main(){
    int n,m;

    while(cin>>n){
        cin>>m;
        
        if(n==0 && m==0) break;
        

        vector<vector<int>>adj(n);
        vector<pair<int,int>>edges(m);

        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;

            edges[i] = {u,v};
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool connect = true;

        for(int i=0;i<m;i++){
            connect = bfs(n,adj,edges[i].first,edges[i].second);
            if(!connect) break;
        }

        if(connect) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;


    }
}