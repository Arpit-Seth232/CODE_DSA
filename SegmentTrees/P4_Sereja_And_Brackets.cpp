#include<bits/stdc++.h>
using namespace std;

class Data
{
    public :
        int full;
        int open;
        int close;
    
        Data(){
            full = 0;
            open = 0;
            close =0;
        }

        Data(int f, int o, int c){
            this->full = f;
            this->close = c;
            this->open = o;
        }
};

class SGT{

    public :
        vector<Data>seg;
        SGT(int n){
            seg.resize(4*n);
        } 
        void build(int low, int high, int idx, string &s){
            if(low == high){
                seg[idx].close = (s[low] == ')' ? 1 : 0);
                seg[idx].open = (s[low] == '(' ? 1 : 0);
                seg[idx].full = 0;
                return;
            }

            int mid = (high+low)/2;
            build(low,mid,2*idx+1,s);
            build(mid+1,high,2*idx+2,s);

            seg[idx].full = seg[2*idx+1].full +  seg[2*idx+2].full+min(seg[2*idx+1].open,seg[2*idx+2].close);
            seg[idx].open = seg[2*idx+1].open + seg[2*idx+2].open - min(seg[2*idx+1].open,seg[2*idx+2].close);
            seg[idx].close = seg[2*idx+1].close + seg[2*idx+2].close - min(seg[2*idx+1].open,seg[2*idx+2].close);
        } 
        
        Data query(int low, int high, int idx, int l, int r){
            if(low>r || high<l){
                return Data();
            }
            if(l<=low && high<=r){
                // cout<<idx<<" "<<low<<" "<<high<<endl;
                return seg[idx];
            }

            int mid = (low+high)/2;
            Data left= Data(),right=Data();
            if(l<=mid){
                left = query(low,mid,2*idx+1,l,r);
            }
            if(r>mid){
                right = query(mid+1,high,2*idx+2,l,r);
            }

            int full = left.full + right.full + min(left.open , right.close);
            int open = left.open + right.open - min(left.open , right.close);
            int close = left.close + right.close - min(left.open , right.close);
            
            return Data(full, open,close);
        }


};



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin>>s;

    int n = s.size();

    int q;
    cin>>q;

    SGT st = SGT(n);
    st.build(0,n-1,0,s);

    // for(int i=0;i<st.seg.size();i++){
    //     cout<<"idx : "<<i<<" val : "<<st.seg[i].open<<" "<<st.seg[i].close<<" "<<st.seg[i].full<<endl;

    // }

    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;

        Data d = st.query(0,n-1,0,l-1,r-1);

        cout<< (d.full * 2) <<endl;
    }
}