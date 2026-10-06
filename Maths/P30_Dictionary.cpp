// https://codeforces.com/problemset/problem/1674/B

# include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        int v1 = s[0]-'a', v2= s[1]-'a';

        int idx = v1*25;
        if(v2<v1) idx += (v2+1);
        else idx += (v2);

        cout<<idx<<endl;

    }
}