#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        long long x,y,k;
        cin>>x>>y>>k;

        long long d = y-x;

        long long ans = 0;

        long long cnt;
        for(cnt = 0; cnt<k && d>=(x+cnt); cnt++){
            ans += (d%(x+cnt));
        }

        if(cnt<k && d<(x+cnt)){
            ans += ((k-cnt)*d);
        }

        cout<<ans<<endl;

    }
}