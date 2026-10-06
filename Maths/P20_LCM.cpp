# include <bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;

int N = 1e6;

vector<int>spf(N+1,0);

void createSieve(){
    
    for(int i=0;i<=N;i++){
        spf[i] = i;
    }

    for(int i=2;i*i<=N;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=N;j+=i){
                if(spf[j]==j) spf[j] = i;
            }
        }
    }
}

long long power(long long a, long long b){
    if(a==0) return 0;
    if(b==0) return 1;

    long long val = power(a,b/2);

    long long ans = ((val%mod) * (val%mod))%mod;

    if(b%2==1) ans = ((ans%mod) * (a%mod))%mod;

    return ans;
}

map<int,int> findFactors(long long num){
    map<int,int>mp;

    while(num>1){
        mp[spf[num]]++;
        num /= spf[num];
    }

    return mp;
}

int main(){

    createSieve();

    int n;
    cin>>n;

    vector<int>v(n);

    int maxi = 0;

    for(int i=0;i<n;i++){
        cin>>v[i];
        maxi = max(maxi,v[i]);
    }

    vector<int>done(maxi+1,0);
    vector<int>powers(maxi+1,0);
    powers[1] = 1;
    done[1] =1;

    for(int i=0;i<n;i++){
      if(!done[v[i]]){
         map<int,int> pf = findFactors(v[i]);

        //  cout<<"num : "<< v[i]<<endl;
        //  for(auto it : pf){
        //     cout<<it.first<<" "<< it.second<<endl;
        //  }

        for(auto it : pf){
            if(it.second > powers[it.first]){
                powers[it.first] = it.second;
            }
        }
        done[v[i]]=1;
    }

    }

    long long ans = 1;

    for(int i=1;i<=maxi;i++){
        ans = ((ans%mod) * power(i,powers[i]))%mod;
    }

    cout<<ans<<endl;




}