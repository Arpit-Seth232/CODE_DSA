# include <bits/stdc++.h>

using namespace std;

class SGT{
    public :
        vector<int>seg;
        SGT(int n){
            seg.resize(4*n);
        }

        void build(int low, int high, int idx, vector<int>&arr, int orr){
            if(low == high){
                seg[idx] = arr[low];
                return;
            }

            int mid = (low+high)/2;
            build(low, mid, 2*idx+1, arr,!orr);
            build(mid+1, high, 2*idx+2, arr, !orr);

            if(orr) seg[idx] = seg[2*idx+1] | seg[2*idx+2];
            else seg[idx] = seg[2*idx+1] ^ seg[2*idx+2];

        }

        void update(int low, int high, int idx, int i, int val, int orr){
            if(low == high){
                seg[idx] = val;
                return;
            }
            
            int mid = (low+high)/2;
            if(i<=mid){
                update(low,mid,2*idx+1,i,val,!orr);
            }
            else{
                update(mid+1,high,2*idx+2,i,val,!orr);
            }
            if(orr) seg[idx] = seg[2*idx+1] | seg[2*idx+2];
            else seg[idx] = seg[2*idx+1] ^ seg[2*idx+2];

        }

        int query(int low,int high, int idx, int l, int r, int orr){
            if(high<l || r<low){
                return 0;
            }
            if(l<=low && high<=r){
                return seg[idx];
            }

            int mid = (low+high)/2;
            int left = query(low,mid,2*idx+1,l,r,!orr);
            int right = query(mid+1,high,2*idx+2,l,r,!orr);

            if(orr) return left | right;
            return left ^ right;
        }



};

int main(){
    int n,q;
    cin>>n>>q;

    int ele = pow(2,n);

    vector<int>v(ele);
    for(int i=0;i<ele;i++){
        cin>>v[i];
    }

    int orr = 1;

    if(n%2==0) orr = 0;

    SGT st = SGT(ele);

    st.build(0,ele-1,0,v,orr);

    for(int i=0;i<q;i++){
        int idx, val;
        cin>>idx>>val;

        st.update(0,ele-1,0,idx-1,val,orr);
        v[idx-1] = val;
        cout<<st.query(0,ele-1,0,0,ele-1,orr)<<endl;

    }
    


}