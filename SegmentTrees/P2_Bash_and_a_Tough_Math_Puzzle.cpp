# include <bits/stdc++.h>

using namespace std;

class SGT{
    public :
        vector<int>seg;
        SGT(int n){
            seg.resize(4*n);
        }


        void build(int low,int high, int idx, vector<int>&arr){
            if(low == high){
                seg[idx] = arr[low];
                return;
            }

            int mid = (high+low)/2;
            build(low,mid,2*idx+1,arr);
            build(mid+1,high,2*idx+2,arr);

            seg[idx] = __gcd(seg[2*idx+1],seg[2*idx+2]);

        }

        void update(int low, int high, int idx, int i, int val){
            if(low==high){
                seg[idx] = val;
                return;
            }
            
            int mid = (high+low)/2;
            if(i<=mid){
                update(low,mid,2*idx+1,i,val);
            }
            else{
                update(mid+1,high,2*idx+2,i,val);
            }

            seg[idx] = __gcd(seg[2*idx+1],seg[2*idx+2]);
        }

        // int check(int low, int high, int idx, int x){
            
        //     if(low==high){
        //         return ((seg[idx]%x)==0 ? 0 : 1);
        //     }
        //     int mid = (low+high)/2;
        //     if(seg[2*idx+1]%x!=0 && seg[2*idx+2]%x!=0){
        //         return 2;
        //     }
        //     else if(seg[2*idx+1]%x!=0 && seg[2*idx+2]%x==0){
        //         return check(low,mid,2*idx+1,x);
        //     }
        //     else if(seg[2*idx+1]%x==0 && seg[2*idx+2]%x!=0){
        //         return check(mid+1,high,2*idx+2,x);
        //     }
        //     return 0;
            
        // }

        void query(int low, int high, int idx, int l, int r, int x, int &cnt){
            if(cnt>=2){
                return;
            }
           
            if(high <l || low>r){
                return ;
            }

            if(low >= l && high <=r && seg[idx]%x==0){
                
                // if(seg[idx]%x==0){
                //     return 0;
                // }
                // else{
                //     int cnt = check(low,high,idx,x);
                    
                //     return cnt;
                // }
                
                return ;
            }

            if(low == high){
                cnt++;
                return ;
            }

            

            int mid = (low+high)/2;
            if(l<=mid) query(low,mid,2*idx+1,l,r,x,cnt);


            if(cnt>=2) return;
           
            if(r>mid) query(mid+1,high,2*idx+2,l,r,x,cnt);

            // return min(2,left+right);
        }




};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;

    vector<int>v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int q;
    cin>>q;

    SGT st = SGT(n);

    st.build(0,n-1,0,v);

   

    for(int i=0;i<q;i++){
        int t;
        cin>>t;
        if(t==1){
            int l,r,x;
            cin>>l>>r>>x;
            int cnt = 0;
            st.query(0,n-1,0,l-1,r-1,x,cnt);
            
            if(cnt<2){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
            int idx,val;
            cin>>idx>>val;

            st.update(0,n-1,0,idx-1,val);
            v[idx] = val;
        }
    }


}