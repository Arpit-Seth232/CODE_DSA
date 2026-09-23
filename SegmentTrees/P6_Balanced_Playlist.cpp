// D. Balanced Playlist

# include <bits/stdc++.h>

using namespace std;

class SGT{
    public : 
        vector<int>seg;
        vector<int>v;

        SGT(int n, vector<int>arr){
            seg.resize(4*n);
            v = arr;
        }

        void build(int low, int high, int idx, vector<int>&v){
            if(low == high){
                seg[idx] = v[low];
                return;
            }

            int mid = (low+high)/2;

            build(low,mid,2*idx+1,v);
            build(mid+1,high,2*idx+2,v);

           

            seg[idx] = max(seg[2*idx+1],seg[2*idx+2]);

        }

        int query(int low, int high, int idx,int l, int r){
            if(low>r || high<l){
                return 0;
            }

            if(l<=low && high<=r){
                
                return seg[idx];

            }

            int mid = (low+high)/2;

            int left = 0, right = 0;
            if(l<=mid){
                left = query(low,mid,2*idx+1,l,r);
            }
            if(r>mid){
                right = query(mid+1,high,2*idx+2,l,r);
            }
            return max(left,right);
        }
};

int main(){

    int n;
    cin>>n;

    vector<int>v(3*n);

    for(int i=0;i<n;i++){
        cin>>v[i];
        v[i+n] = v[i];
        v[i+2*n] = v[i];
    }
    
    

    SGT st = SGT(3*n,v);

    st.build(0,(3*n-1),0,v);

    vector<int>ans(n,-1);
    int preMax = 0;
    int s=0;
    int e=0;
    while(s<n){
        
        while(e<3*n && 2*v[e]>=preMax){
            preMax = max(preMax,v[e]);
            e++;
        }
        if(e==3*n) ans[s] = -1;
        else ans[s] = e-s;

        preMax = st.query(0,3*n-1,0,s+1,e-1);
        s++;
        
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }



}