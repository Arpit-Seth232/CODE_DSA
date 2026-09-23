
// USACO 2016 US Open Contest, Silver
// Problem 3. Closing the Farm

# include <bits/stdc++.h>
using namespace std;

string check_connected(int &n, vector<int>&open,vector<vector<int>>&adj){

    vector<int>vis(n,0);
    int st = -1;
    for(int i=0;i<n;i++){
        if(open[i]==1) st=i;
    }

    queue<int>q;
    q.push(st);
    vis[st]=1;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto child : adj[node]){
            if(open[child]==1 && !vis[child]){
                q.push(child);
                vis[child]=1;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(open[i]==1 && vis[i]==0){
            return "NO";
        }
    }

    return "YES";

}

int main(){

    freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);

    int n,m;
    cin>>n>>m;

    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vector<int>open(n,1);
    for(int i=0;i<n;i++){
        cout<<check_connected(n,open,adj)<<endl;
        int val;
        cin>>val;
        open[val-1]=0;
    }


}