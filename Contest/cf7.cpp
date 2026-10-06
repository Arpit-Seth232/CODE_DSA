#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;
        string st;
        cin>>st;

        int ans =0;

        vector<int>pre(n,0);

        if(st[0] == '0') pre[0] = 1;

        for(int i=1;i<n;i++){
            pre[i] = pre[i-1];
            if(st[i]=='0') pre[i] += 1;
        }

        int e = k-1;
        while(e<n){
            int cnt = pre[e];
            if(e-k>=0) cnt-=pre[e-k];

            if(cnt == 0) ans++;
            e = e+k;
        }

        cout<<ans<<endl;


    }
}