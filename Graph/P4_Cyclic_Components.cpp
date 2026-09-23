# include <bits/stdc++.h>

using namespace std;

class DSU{
    public : 
        vector<int>parent;
        vector<int>size;
        
        DSU(int n){
            parent.resize(n);
            size.resize(n,1);

            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }

        int findParent(int node){
            if(parent[node] == node) return node;
            return parent[node] = findParent(parent[node]);
        }

        void unionSize(int u, int v){
            int bpu = findParent(u);
            int bpv = findParent(v);

            if(bpu == bpv) return;

            if(size[bpu]>size[bpv]){
                parent[bpv] = bpu;
                size[bpu] += size[bpv];
            }
            else{
                parent[bpu] = bpv;
                size[bpv] += size[bpu];
            }
        }
};

bool findCycle(int st,int &n, int p, vector<vector<int>>&adj){
    vector<bool>vis(n,false);
    queue<vector<int>>q;
    q.push({st,p});
    vis[st] = true;

    while(!q.empty()){
        int node = q.front()[0];
        int par = q.front()[1];
       

        q.pop();

        if(adj[node].size()!=2) return false;
        

        for(auto child : adj[node]){
            if(child == par || vis[child]) continue;
            else{
                vis[child] = true;
                q.push({child,node});
            }
        }

    }

    return true;

}

int main(){

    int n,m;
    cin>>n>>m;

    DSU dsu = DSU(n);

    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        dsu.unionSize(u-1,v-1);

        // cout<<"Done dsu"<<endl;

        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);

        // cout<<"Set in adj"<<endl;
    }

    int cnt =0;

    for(int i=0;i<n;i++){
        if(dsu.parent[i] == i && findCycle(i,n,-1,adj)){
            cnt++;
        }
    }

    cout<<cnt;

}