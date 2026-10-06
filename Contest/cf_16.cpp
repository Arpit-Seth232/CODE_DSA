# include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,a,b,c;
        cin>>n;
        cin>>a>>b>>c;

        int ans = 0;
        ans = max({ans,(n-a),(n-b),(n-c)});

        cout<<ans<<endl;
        
    }
}
