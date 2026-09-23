    // CSES Problem Set
    // Round Trip

    # include <bits/stdc++.h>

    using namespace std;
    vector<int>vis;
    vector<int>parent;

    bool cycle(int node,int pr,int &cycleS, int &cycleE,vector<vector<int>>&adj){
        
        vis[node] = 1;
        parent[node] = pr;

        for(auto child : adj[node]){
            if(child == pr){
                continue;
            }
            else if(vis[child]==-1){
                bool found = cycle(child,node,cycleS,cycleE,adj);
                if(found) return true;
            }
            else if(vis[child]==1){
                cycleS = child;
                cycleE = node;
                return true;
            }
        }
        
        return false;


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

        vis.resize(n,-1);
        parent.resize(n,-1);

        int cycleS = -1, cycleE = -1;
        bool detect = false;
        
        for(int i=0;i<n;i++){
        if(vis[i]==-1){    
        detect  = cycle(i,-1,cycleS,cycleE,adj);
        }
        if(detect) break;
        }

        if(!detect){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }

        vector<int>path;

        path.push_back(cycleS);

        int curr = cycleE;

        while(curr != cycleS){
            path.push_back(curr);
            curr = parent[curr];
        }

        path.push_back(cycleS);

        cout<<path.size()<<endl;

        for(int i=path.size()-1;i>=0;i--){
            cout<<path[i]+1<<" ";
        }


    }