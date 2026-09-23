// CSES Problem Set
// // Building Roads

#include <bits/stdc++.h>

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

            if(size[bpu] < size[bpv]){
                parent[bpu] = bpv;
                size[bpv] += bpu;
            }
            else{
                parent[bpv] = bpu;
                size[bpu] += size[bpv];
            }
        }
    
};

int main(){
    int n,m;
    cin>>n>>m;

    DSU dsu = DSU(n);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        dsu.unionSize(u-1,v-1);
    }

    vector<int>com;
    for(int i=0;i<n;i++){
        if(dsu.parent[i] == i){
            com.push_back(i);
        }
    }

    cout<<com.size()-1<<endl;
    if(com.size()>1){
        
        for(int i=1;i<com.size();i++){
            cout<<com[0]+1<<" "<<com[i]+1<<endl;
        }

    }


}