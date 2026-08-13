# include <bits/stdc++.h>
using namespace std;

class Data{

    public :
        int gcd;
        int mini;
        int cntMini;

        Data(){
            gcd = 0;
            mini = INT_MAX;
            cntMini = 0;
        }

        Data(int gcd, int mini, int cntMini){
            this->gcd = gcd;
            this->mini = mini;
            this->cntMini = cntMini;
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
                seg[idx].gcd = v[low];
                seg[idx].mini = v[low];
                seg[idx].cntMini = 1;
                return;
            }

            int mid = (low+high)/2;

            build(low,mid,2*idx+1,v);
            build(mid+1,high,2*idx+2,v);

            Data left = seg[2*idx+1];
            Data right = seg[2*idx+2];

            seg[idx].gcd = __gcd(left.gcd , right.gcd);
            seg[idx].mini = min(left.mini , right.mini);
            if(left.mini < right.mini){
                seg[idx].cntMini = left.cntMini;
            }
            else if(left.mini > right.mini){
                seg[idx].cntMini = right.cntMini;
            }
            else{
                seg[idx].cntMini = left.cntMini + right.cntMini;
            }

        }

        Data query(int low, int high, int idx, int l, int r){
            if(low > r || high < l){
                return Data();
            }

            if(l<=low && high<=r){
                return seg[idx];
            }

            int mid = (low+high)/2;

            Data left = Data() , right = Data();

            if(l<=mid){
                left = query(low,mid,2*idx+1,l,r);
            }
            if(r>mid){
                right = query(mid+1,high,2*idx+2,l,r);
            }

            int gcd = __gcd(left.gcd , right.gcd);
            int mini = min(left.mini , right.mini);
            int cnt = 0;
            if(left.mini < right.mini){
                cnt = left.cntMini;
            }
            else if(left.mini > right.mini){
                cnt = right.cntMini;
            }
            else{
                cnt = left.cntMini + right.cntMini;
            }
            
            return Data(gcd,mini,cnt);


        }



};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<int>v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    SGT st = SGT(n);

    st.build(0,n-1,0,v);

    int q;
    cin>>q;

    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;

        Data d = st.query(0,n-1,0,l-1,r-1);

        int cnt = ((d.gcd == d.mini) ? d.cntMini : 0);

        cout<<((r-l+1) - cnt)<<endl;
    }

}

