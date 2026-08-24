# include <bits/stdc++.h>
using namespace std;

void calc(int &end, vector<vector<pair<int,int>>>&adj){
    vector<long long>dist(end,LLONG_MAX);
    vector<int>parent(end,-1);

    set<pair<long long,int>>s;
    s.insert({0,0});
    parent[0] = 0;
    dist[0] = 0;

    while(!s.empty()){
        auto v = *s.begin();
        long long dis = v.first;
        int node = v.second;
        s.erase(v);

        for(auto it : adj[node]){
            int child = it.first, w = it.second;

            if(dist[child]> (1LL * dis+w)){
                dist[child] = (1LL*dis+w);
                s.insert({(1LL*dis+w),child});
                parent[child] = node;
            }
        }
    }

    if(parent[end-1]==-1) cout<<-1;
    else{
        vector<int>ans;
        int find = end-1;
        while(parent[find] != find){
            ans.push_back(find+1);
            find = parent[find];
        }
        ans.push_back(1);

        for(int i=ans.size()-1;i>=0;i--){
            cout<<ans[i]<<" ";
        }
    }

}


int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<pair<int,int>>>adj(n);

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;

        adj[u-1].push_back({v-1,w});
        adj[v-1].push_back({u-1,w});
    }

    calc(n,adj);
}