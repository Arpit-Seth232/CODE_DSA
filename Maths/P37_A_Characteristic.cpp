// https://codeforces.com/problemset/problem/1823/A
# include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        int c1=n, c2 =0;
        bool found = false;

        while(c1>=0){
            int p = (c1 * (c1-1))/2 + (c2 * (c2-1))/2;
            if(p==k) {
                found = true;
                break;
            }
            c1--;
            c2++;
        }

        if(found){
            cout<<"Yes"<<endl;
            for(int i=0;i<c1;i++){
                cout<<1<<" ";
            }
            for(int i=0;i<c2;i++){
                cout<<-1<<" ";
            }
            cout<<endl;
        }

        else cout<<"No"<<endl;

        
    }
}