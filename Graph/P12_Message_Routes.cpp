// CSES Problem Set
// Message Route

# include<bits/stdc++.h>
using namespace std;

void calc(int st, int n,vector<vector<int>>&adj ){
    vector<int>vis(n,false);
    vector<int>parent(n,-1);

    queue<pair<int,int>>q;
    q.push({1,st});
    vis[st]=true;
    parent[st] = st;

    while(!q.empty()){
        auto v = q.front();
        int cnt = v.first, node = v.second;

        q.pop();
        if(node == n-1){
            cout<<cnt<<endl;
            break;
        }

        for(auto child : adj[node]){
            if(!vis[child]){
                vis[child] = true;
                parent[child] = node;
                q.push({cnt+1,child});
            }
        }
    }
    if(vis[n-1]){
        
        vector<int>ans;
        int node = n-1;
        while(parent[node] != node){
            ans.push_back(node+1);
            node = parent[node];
        }
        
        cout<<1<<" ";
        for(int i=ans.size()-1;i>=0;i--){
            cout<<ans[i]<<" ";
        }
    }
    else{
        cout<<"IMPOSSIBLE";
    }

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

    calc(0,n,adj);

}
