# include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        long long n,m;
        cin>>n>>m;

        vector<long long>v(n);

        for(int i=0;i<n;i++){
            cin>>v[i];
        }

        long long ans = LLONG_MIN;
        long long sum = 0;

        multiset<long long>s;

        for(int i=0;i<n;i++){

            if(s.size() == m-1){
                ans = max(ans, m*v[i] -sum);
            }

            s.insert(v[i]);
            sum+=v[i];

            if(s.size()>m-1){
                auto it = prev(s.end());
                sum -= *it;
                s.erase(it);
            }

        }

        cout<<ans<<endl;
        

    }
}