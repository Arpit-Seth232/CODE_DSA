# include<bits/stdc++.h>
using  namespace std;

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

        seg[idx] = seg[2*idx+1]+seg[2*idx+2];
    }
    
    void update(int low, int high, int idx, int i, int val){
        if(low == high){
            seg[idx] += val;
            return;
        }

        int mid = (high+low)/2;

        if(i<=mid){
            update(low,mid,2*idx+1,i,val);
        }
        else{
            update(mid+1,high,2*idx+2,i,val);
        }

        seg[idx] = seg[2*idx+1]+seg[2*idx+2];

    }


    int query(int low, int high, int idx, int l, int r){
        if(r<low || high<l){
            return 0;
        }
        if(l<=low && high<=r){
            return seg[idx];
        }

        int mid = (low+high)/2;
        int left =0, right =0;
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<int>v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    vector<int>left(n),right(n);
    map<int,int>mpl,mpr;

    for(int i=0;i<n;i++){
        mpl[v[i]]++;
        mpr[v[n-i-1]]++;
        left[i] = mpl[v[i]];
        right[n-i-1] = mpr[v[n-i-1]];
    }

    vector<int>freq(n+1,0);

    for(int i=0;i<n;i++){
        freq[right[i]]++;
    }

    SGT st = SGT(n+1);

    st.build(0,n,0,freq);

    long long ans = 0;
    for(int i=0;i<n-1;i++){
        st.update(0,n,0,right[i],-1);
        ans = ans + (long long)st.query(0,n,0,0,left[i]-1);
    }
    
    cout<<ans<<endl;
    
}