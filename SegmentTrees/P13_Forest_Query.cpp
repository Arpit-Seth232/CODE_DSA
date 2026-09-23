// CSES Problem Set
// Forest Queries

# include <bits/stdc++.h>
using namespace std;

class SGT2D{
    public :
        vector<vector<int>>seg;
        int m;

        SGT2D(int n){
            this->seg.resize(4*n,vector<int>(4*n));
            this->m = n;
        }

        void build_x(int low, int high, int idx_x, vector<vector<int>>&v){
            if(low != high){
                int mid = (low+high)/2;
                build_x(low,mid,2*idx_x+1,v);
                build_x(mid+1,high,2*idx_x+2,v);
            }
            
            build_y(0,m-1,0,v,low,high,idx_x);
            return;


        }

        void build_y(int low, int high, int idx_y, vector<vector<int>>&v, int low_x,int high_x,int idx_x){
            if(low == high){

                if(low_x == high_x) seg[idx_x][idx_y] = v[low_x][low];
                else{
                    seg[idx_x][idx_y] = seg[2*idx_x+1][idx_y] + seg[2*idx_x+2][idx_y];
                }
                return ;
            }

            int mid = (low+high)/2;
            build_y(low,mid,2*idx_y+1,v,low_x,high_x,idx_x);
            build_y(mid+1,high,2*idx_y+2,v,low_x,high_x,idx_x);

            seg[idx_x][idx_y] = seg[idx_x][2*idx_y+1] + seg[idx_x][2*idx_y+2];
        }

        int query_y(int low, int high, int idx_y, int ly, int ry, int idx_x){
            if(ly>high || ry<low){
                return 0;
            }
            if(ly<=low && high<=ry){
                return seg[idx_x][idx_y];
            }
            int mid = (low+high)/2;
            int left=0,right =0;

            if(ly<=mid){
                left = query_y(low,mid,2*idx_y+1,ly,ry,idx_x);
            }
            if(ry>mid){
                right = query_y(mid+1, high,2*idx_y+2,ly,ry,idx_x);
            }

            return left+right;
        }

        int query_x(int low, int high, int idx_x, int lx, int rx, int ly, int ry){
            if(lx>high || rx<low){
                return 0;
            }
            if(lx<=low && high<=rx){
               return query_y(0,m-1,0,ly,ry,idx_x);
            }

            int mid = (low+high)/2;
            int left = 0 ,right =0;
            if(lx<=mid){
                left = query_x(low,mid,2*idx_x+1,lx,rx,ly,ry);
            }
            if(rx>mid){
                right = query_x(mid+1,high,2*idx_x+2,lx,rx,ly,ry);
            }

            return left + right;
        }

};

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>v(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char ch;
            cin>>ch;

            if(ch == '*') v[i][j]=1;
        }
    }

    SGT2D st = SGT2D(n);

    st.build_x(0,n-1,0,v);

    for(int i=0;i<m;i++){
        int lx,ly,rx,ry;
        cin>>lx>>ly>>rx>>ry;

        cout<<st.query_x(0,n-1,0,lx-1,rx-1,ly-1,ry-1)<<endl;
    }
    


}