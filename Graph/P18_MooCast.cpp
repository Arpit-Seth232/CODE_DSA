// USACO 2016 December Contest, Silver
// Problem 3. Moocast

# include <bits/stdc++.h>

using namespace std;

int bfs(int st,int &n, vector<vector<int>>&adj){
    vector<int>vis(n,0);
    queue<int>q;
    q.push(st);
    vis[st]=1;

    int cnt = 1;
    while(!q.empty()){

        int node = q.front();
        q.pop();

        for(auto child : adj[node]){
            if(!vis[child]){
                cnt++;
                q.push(child);
                vis[child]=1;
            }
        }

    }

    return cnt;
}

int main(){

    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);

    int n;
    cin>>n;

    vector<vector<int>>v(n);
    for(int i=0;i<n;i++){
        int x,y,p;
        cin>>x>>y>>p;

        v[i]={x,y,p};
    }

    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
        int p = v[i][2] * v[i][2];
        for(int j=0;j<n;j++){
            if(i==j) continue;
            int diffx = abs(v[j][0]-v[i][0]);
            int diffy = abs(v[i][1]-v[j][1]);

            int sum = (diffx*diffx) + (diffy*diffy);

            if(sum>p){
                continue;
            }

            adj[i].push_back(j);
        }
    }
    
    int ans = 0;

    for(int i=0;i<n;i++){
        int reach = bfs(i,n,adj);
       
        ans = max(ans,reach);
    }

    cout<<ans;

}