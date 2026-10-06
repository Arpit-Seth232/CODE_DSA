# include <bits/stdc++.h>

using namespace std;

int N = 300001;
vector<vector<int>>pf(N);

void createSieve(){
    

    for(int i=2;i<N;i++){
        if(pf[i].size()==0){

            for(int j=i;j<N;j+=i){
                pf[j].push_back(i);
            }
        }
    }


}


int main(){
    int t;
    cin>>t;

    createSieve();

    while(t--){
        int n,x;
        cin>>n>>x;

        vector<long long>v(n);

        for(int i=0;i<n;i++){
            cin>>v[i];
        }

        if(x==1){
            cout<<0<<endl;
            continue;
        }

        vector<int>fac = pf[x];

        map<int,long long>mp;

        for(auto f : fac){
            mp[f] = 0;
        }

        for(int i=0;i<n;i++){
            
            for(auto &it : mp){
                if((v[i]%it.first) == 0){
                    it.second += v[i];
                }
            }
        }

        long long ans = 0;

        for(auto it : mp){
            ans = max(ans,it.second);
        }

        cout<<ans<<endl;

    }
}