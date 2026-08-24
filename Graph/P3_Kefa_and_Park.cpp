# include <bits/stdc++.h>

using namespace std;

int calc(int st,int &ok,vector<int>&hadCat, vector<vector<int>>&adj){
    int paths = 0;

    queue<vector<int>>q;
    q.push({st,hadCat[st],-1});

    while(!q.empty()){
        int node = q.front()[0];
        int cnt = q.front()[1];
        int p = q.front()[2];
        q.pop();
        if(cnt>ok){
            continue;
        }
        if(adj[node].size()==1 && adj[node][0] == p){
            paths++;
            continue;
        }

        for(auto child : adj[node]){
            if(child == p) continue;

            if(hadCat[child]==1){
                q.push({child,cnt+1,node});
            }
            else{
                q.push({child,0,node});
            }
        }

    }

    return paths;
}

int main(){

    int n,ok;
    cin>>n>>ok;

    vector<int>hadCat(n);
    for(int i=0;i<n;i++) cin>>hadCat[i];

    vector<vector<int>>adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    cout<<calc(0,ok,hadCat,adj);
}