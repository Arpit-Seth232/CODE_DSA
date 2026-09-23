// CSES Problem Set
// Counting Rooms

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

            if(bpu == bpv ) return;

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

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    DSU dsu = DSU(n*m);
    vector<vector<char>>grid(n,vector<char>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        cin>>grid[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(grid[i][j] == '.'){

                int u = i*m+j;

                for(int k=0;k<4;k++){

                    int nx = i+dx[k],ny = j+dy[k];
                    int v = nx*m + ny;
                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny] == '.'){
                        dsu.unionSize(u,v);
                    }
                }

            }

        }
    }

    int cnt = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(grid[i][j] == '#') continue;

            int node = i*m+j;

            if(dsu.parent[node] == node) cnt++;
        }
    }

    cout<<cnt;


}