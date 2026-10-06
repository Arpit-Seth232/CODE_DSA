// https://codeforces.com/problemset/problem/1742/B

# include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int>v(n);

        bool poss = true;
        map<int,int>mp;
        for(int i = 0; i<n;i++){
            cin>>v[i];
            mp[v[i]]++;
            if(mp[v[i]]>1) poss = false;
        }    

        if(poss){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }


    }
}