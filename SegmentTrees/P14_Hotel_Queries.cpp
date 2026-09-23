# include <bits/stdc++.h>

using namespace std;

class SGT{

    public :
        vector<int>seg;
        SGT(int n){
            seg.resize(4*n);
        }

        void build(int low, int high, int idx, vector<int>&v){
            if(low == high){
                seg[idx] = v[low];
                return;

            }
            int mid = (low+high)/2;

            build(low,mid,2*idx+1,v);
            build(mid+1,high,2*idx+2,v);

            seg[idx] = max(seg[2*idx+1] , seg[2*idx+2]);
        }

        void update(int low, int high, int idx, int i, int val){
            if(low == high){
                seg[idx] -= val;
                return;
            }
            int mid = (low+high)/2;
            if(i<=mid){
                update(low,mid,2*idx+1,i,val);
            }
            else{
                update(mid+1,high,2*idx+2,i,val);
            }

            seg[idx] = max(seg[2*idx+1] , seg[2*idx+2]);
        }

        int query(int low, int high, int idx, int val){
            if(seg[idx]<val){
                return -1;
            }
            
            if(low == high){
                return low;
            }

            int mid = (low+high)/2;

            int left = query(low,mid,2*idx+1,val);

            if(left != -1) return left;

            int right = query(mid+1,high,2*idx+2,val);

            return right;
        }

};

int main(){

    int n,m;
    cin>>n>>m;

    vector<int>v(n);
   

    SGT st = SGT(n);
    
    for(int i=0;i<n;i++) cin>>v[i];
    st.build(0,n-1,0,v);
    

    for(int i=0;i<m;i++){
        int val;
        cin>>val;

        int ans = st.query(0,n-1,0,val);

        if(ans > -1){
            st.update(0,n-1,0,ans,val);
        }

        cout<<ans+1<<" ";

    }
}