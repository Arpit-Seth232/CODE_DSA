// CSES Problem Set
// Labyrinth

# include <bits/stdc++.h>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};



void calc(int n, int m, int sti, int stj, int endi, int endj, vector<vector<char>>&v){
    vector<vector<int>>vis(n,vector<int>(m,false));

    vector<vector<pair<int,int>>>parent(n,vector<pair<int,int>>(m,{-1,-1}));

    queue<vector<int>>q;

    string ans = "";
    q.push({sti,stj});

    vis[sti][stj] = true;
    parent[sti][stj] = {sti,stj};

    while(!q.empty()){

        auto it = q.front();
        int x = it[0], y= it[1];
       

        q.pop();

        if(x==endi && y==endj){
            break;
        }

        for(int k=0;k<4;k++){
            int nx = x+dx[k], ny = y+dy[k];

            if(nx>=0 && nx<n && ny>=0 && ny<m && v[nx][ny]!='#' && !vis[nx][ny]){
                vis[nx][ny] = true;
                parent[nx][ny] = {x,y};
                q.push({nx,ny});
            }
        }
    }

    if(parent[endi][endj].first != -1 ){
        cout<<"YES"<<endl;
        while(parent[endi][endj].first != endi || parent[endi][endj].second != endj){
           int px =parent[endi][endj].first , py = parent[endi][endj].second;
            


           if(px-1 == endi){
            ans += 'U';
           }
           else if(px+1 == endi){
            ans += 'D';
           }
           else if(py-1 == endj){
            ans += 'L';
           }
           else{
            ans += 'R';
           }

           endi = px;
           endj = py;

        }
        cout<<ans.size()<<endl;
        reverse(ans.begin(),ans.end());
        cout<<ans;
    }
    else{
        cout<<"NO";
    }

}

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<char>>v(n,vector<char>(m));

    int sti = -1, stj = -1, endi= -1, endj=-1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];

            if(v[i][j] == 'A') {
                sti = i;
                stj = j;
            }
            else if(v[i][j] == 'B'){
                endi = i;
                endj = j;
            }
        }
    }

    calc(n,m,sti,stj,endi,endj,v);


}