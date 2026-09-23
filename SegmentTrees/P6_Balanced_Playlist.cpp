// D. Balanced Playlist

# include <bits/stdc++.h>

using namespace std;

class Data{
    public :
        int maxi;
        int mini;
        int maxIdx;
        int minIdx;
        

        Data(){
            maxi = 0;
            mini = 0;
            maxIdx = 0;
            minIdx = 0;
        }

        Data(int maxi, int mini, int maxIdx, int minIdx){
            this->maxi = maxi;
           this->mini = mini;
           this->maxIdx = maxIdx;
           this->minIdx = minIdx;
        }

};

class SGT{
    public : 
        vector<Data>seg;

        SGT(int n){
            seg.resize(4*n);
        }

        void build(int low, int high, int idx, vector<int>&v){
            if(low == high){
                seg[idx].maxi = v[low];
                seg[idx].mini = v[low];
                seg[idx].maxIdx = low;
                seg[idx].minIdx = low;
                return;
            }

            int mid = (low+high)/2;

            build(low,mid,2*idx+1,v);
            build(mid+1,high,2*idx+2,v);

            Data left = seg[2*idx+1];
            Data right = seg[2*idx+2];

            seg[idx].maxi = max(left.maxi,right.maxi);
            seg[idx].mini = min(left.mini,right.mini);

            if(left.maxi == right.maxi){
                seg[idx].maxIdx = min(left.maxIdx,right.maxIdx);
            }
            else{
            seg[idx].maxIdx = left.maxi > right.maxi ? left.maxIdx : right.maxIdx;
            }

            if(left.mini == right.mini){
                seg[idx].minIdx = max(left.minIdx,right.minIdx);
            }
            else{
            seg[idx].minIdx = left.mini < right.mini ? left.minIdx : right.minIdx;
            }

        }

        Data query(int low, int high, int idx,int l, int r){
            if(low>r || high<l){
                return Data(INT_MIN,INT_MAX,INT_MAX,INT_MIN);
            }

            if(l<=low && high<=r){
                return seg[idx];
            }

            int mid = (low+high)/2;

            Data left = Data(INT_MIN,INT_MAX,INT_MAX,INT_MIN), right = Data(INT_MIN,INT_MAX,INT_MAX,INT_MIN);
            if(l<=mid){
                left = query(low,mid,2*idx+1,l,r);
            }
            if(r>mid){
                right = query(mid+1,high,2*idx+2,l,r);
            }

            int maxIdx,minIdx;
             if(left.maxi == right.maxi){
                maxIdx = min(left.maxIdx,right.maxIdx);
            }
            else{
            maxIdx = left.maxi > right.maxi ? left.maxIdx : right.maxIdx;
            }

            if(left.mini == right.mini){
                minIdx = max(left.minIdx,right.minIdx);
            }
            else{
            minIdx = left.mini < right.mini ? left.minIdx : right.minIdx;
            }


            return Data(max(left.maxi,right.maxi),min(left.mini,right.mini),maxIdx,minIdx);

        }
};

int main(){

    int n;
    cin>>n;

    vector<int>v(2*n);

    int maxi = 0;
    int maxiIdx = -1;

    for(int i=0;i<n;i++){
        cin>>v[i];
        v[i+n] = v[i];
        if(maxi<v[i]){
            maxi = v[i];
            maxiIdx = i;
        }
    }

    SGT st = SGT(2*n);

    st.build(0,(2*n-1),0,v);

    vector<int>ans(n);

    for(int i=0;i<n;i++){
        int s = i, e = i+n-1;
        
        int idx = -1;
        while(s<=e){
            
            int mid = (e+s)/2;

            Data d= st.query(0,2*n-1,0,i,mid);
            if((1LL*d.maxi) > (1LL*2*d.mini) && d.minIdx > d.maxIdx){
                e=mid-1;
            }
            else{
                idx = mid;
                s=mid+1;
            }

        }

        if(idx == i+n-1){

            if(maxiIdx < i){
                ans[i] = n + ans[maxiIdx] - (i-maxiIdx);
            }

            else{
                ans[i] = -1;
            }

        }
        else{
            ans[i] = idx - i+1;
        }



    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }



}