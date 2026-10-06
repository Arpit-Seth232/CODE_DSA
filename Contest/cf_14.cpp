# include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int>v(n);

        for(int i=0;i<n;i++){
            cin>>v[i];
        }

        vector<pair<int,int>>p;

        for(int i=0;i<n;i++){
            if(v[i]!= i+1) p.push_back({v[i],i+1});
        }

        int s=0,e=p.size()-1;

        bool poss = true;

        while(s<e){
            if(p[s].first == p[e].second && p[s].second == p[e].first){
                s++;
                e--;
            }
            else{
                poss = false;
                break;
            }
        }

        if(poss) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
}