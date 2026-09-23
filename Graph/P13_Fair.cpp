// A. Fair

# include <bits/stdc++.h>

using namespace std;

void solve(int &n, int &k, int &d,vector<int>&arr,vector<vector<int>>&adj){
    vector<vector<int>>dist(k+1,vector<int>(n,INT_MAX));

    
    for(int type = 1;type<=k;type++){

        queue<int>q;
        
    for(int i=0;i<n;i++){
        if(arr[i]==type){
        q.push(i);
        dist[type][i] = 0;
        }
    }

    while(!q.empty()){
        int node = q.front();
        
        q.pop();

        for(auto child : adj[node]){
            if(dist[type][child] > dist[type][node]+1){
                dist[type][child] = dist[type][node]+1;
                q.push(child);
            }
        }

        
    }
}

    for(int i=0;i<n;i++){
        
        vector<int>temp;
        for(int j=1;j<=k;j++){
            temp.push_back(dist[j][i]);
        }

        sort(temp.begin(),temp.end());

        int ans = 0;
        for(int j=0;j<d;j++){
            ans +=temp[j];
        }

        cout<<ans<<" ";
    }



}

int main(){
    int n,m,k,s;
    cin>>n>>m>>k>>s;

    vector<int>arr(n);

    for(int i=0;i<n;i++) cin>>arr[i];

    vector<vector<int>>adj(n);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    solve(n,k,s,arr,adj);
}