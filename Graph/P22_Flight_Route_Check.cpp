// CSES Problem Set
// Flight Routes Check

# include <bits/stdc++.h>
using namespace std;




void dfs(int node,vector<int>&vis ,vector<vector<int>>&adj ){
    vis[node] =1;
    
    for(auto child : adj[node]){
       
        if(!vis[child]){
            dfs(child,vis,adj);
        }
        
    } 
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>adj1(n);
    vector<vector<int>>adj2(n);

    

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj1[u-1].push_back(v-1);
        adj2[v-1].push_back(u-1);

   
    }

    
    
    vector<int> vis(n,0);

    dfs(0,vis,adj1);

    for(int i=1;i<n;i++){
        if(!vis[i]){
            cout<<"NO"<<endl;
            cout<<1<<" "<<i+1<<endl;
            return 0;
        }
    }
    
   

    vis.assign(n,0);

    dfs(0,vis,adj2);

    for(int i=1;i<n;i++){
        if(!vis[i]){
            cout<<"NO"<<endl;
            cout<<i+1<<" "<<1<<endl;
            return 0;
        }
    }
   

    cout<<"YES"<<endl;
   

   

    

}