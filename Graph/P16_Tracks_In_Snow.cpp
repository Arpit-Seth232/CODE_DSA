// https://oj.uz/problem/view/BOI13_tracks
// Tracks in the Snow

# include <bits/stdc++.h>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void calc(int &n, int &m,vector<vector<char>>&grid ){
    vector<vector<int>>dist(n,vector<int>(m,INT_MAX));

    dist[0][0]=1;
    deque<vector<int>>q;
    q.push_front({1,0,0});
    

    while(!q.empty()){

        auto v = q.front();
        
       int cnt = v[0], x = v[1], y = v[2];

        q.pop_front();

        for(int k=0;k<4;k++){
            int nx = x+dx[k], ny = y+dy[k];

            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!='.'){
                if(grid[x][y]==grid[nx][ny] && dist[nx][ny] > cnt){
                    dist[nx][ny] = cnt;
                    q.push_front({cnt,nx,ny});
                }
                else if(grid[x][y]!=grid[nx][ny] && dist[nx][ny] > cnt+1){
                    dist[nx][ny] = cnt+1;
                    q.push_back({cnt+1,nx,ny});
                }
            }

        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(dist[i][j]==INT_MAX){
    //             cout<<-1<<" ";
    //         }
    //         else{
    //             cout<<dist[i][j]<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }

    int maxi = 1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]!='.'){
                maxi = max(maxi,dist[i][j]);
            }
        }
    }

    cout<<maxi;



}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    int n,m;
    cin>>n>>m;

    vector<vector<char>>grid(n,vector<char>(m,'.'));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    calc(n,m,grid);

}
