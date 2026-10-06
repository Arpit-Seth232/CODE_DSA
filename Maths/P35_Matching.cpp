// https://codeforces.com/problemset/problem/1821/A

# include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        if(s[0]=='0') cout<<0<<endl;
        else{

            long long ans = 1;
            int n = s.size();

            for(int i=0;i<n;i++){
                if(s[i]=='?'){
                    if(i>0) ans = ans * 10;
                    else ans = ans * 9;
                }
            }

            cout<<ans<<endl;
        }

    }
}