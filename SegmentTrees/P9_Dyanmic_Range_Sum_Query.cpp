// CSES Problem Set
// Dynamic Range Sum Queries

# include <bits/stdc++.h>
using namespace std;

class SGT{
    public :
        vector<long long> seg;
        SGT(int n){
            seg.resize(4*n);
        }

        void build(int low, int high, int idx, vector<long long>&v){
            if(low == high){
                seg[idx] = v[low];
                return;
            }

            int mid = (low + high)/2;

            build(low,mid,2*idx+1,v);
            build(mid+1,high,2*idx+2,v);

            seg[idx] = seg[2*idx+1] + seg[2*idx+2];

        }

        void update(int low, int high, int idx, int i, int val){
            if(low == high){
                seg[idx] = val;
                return;
            }

            int mid = (low+high)/2;

            if(i<=mid){
                update(low, mid, 2*idx+1,i,val);
            }
            else{
                update(mid+1,high,2*idx+2,i,val);
            }

            seg[idx] = seg[2*idx+1] + seg[2*idx+2];
        }

        long long query(int low, int high, int idx, int l, int r){
            if(low > r || high < l){
                return 0;
            }

            if(l<=low && high<=r){
                return seg[idx];
            }

            int mid = (low+high)/2;

            long long left  = 0, right =0;

            if(l<=mid){
                left = query(low,mid,2*idx+1,l,r);
            }
            if(r>mid){
                right = query(mid+1,high,2*idx+2,l,r);
            }

            return left+right;
        }


};


 int main(){

    int n,q;
    cin>>n>>q;

    vector<long long>v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    SGT st = SGT(n);

    st.build(0,n-1,0,v);

    for(int i=0;i<q;i++){
        int t;
        cin>>t;

        if(t == 1){
            int i;
            long long val;
            cin>>i>>val;

            st.update(0,n-1,0,i-1,val);
            v[i-1] = val;
        }
        else{
            int l,r;
            cin>>l>>r;

            cout<<st.query(0,n-1,0,l-1,r-1)<<endl;
        }
    }



 }