// A. Party

# include <bits/stdc++.h>
using namespace std;

int calc(queue<pair<int,int>>q, vector<vector<int>>&adj){
    int maxi = 1;

    while(!q.empty()){
        int node = q.front().first;
        int dis = q.front().second;

        q.pop();

        maxi = max(maxi,dis);

        for(auto child : adj[node]){
            q.push({child,dis+1});
        }
    }

    return maxi;

}

int main(){

    int n;
    cin>>n;

    queue<pair<int,int>>q;

    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
        int p;
        cin>>p;

        if(p!=-1){
            adj[p-1].push_back(i);
        }
        else{
            q.push({i,1});
        }
    }

    cout<<calc(q,adj);

}