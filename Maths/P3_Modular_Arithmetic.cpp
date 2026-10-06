# include <bits/stdc++.h>

using namespace std;

long long mod = 1e9+7;

vector<long long>fact;

void preCompute(int m){
    
    fact[0] = 1;
    if(m>1) fact[1] = 1;

    for(long long i=2;i<=m;i++){
        fact[i] = (i%mod * fact[i-1]%mod)%mod;
    }

}

long long power(long long a, long long b){
    if(a==0){
        return 0;
    }
    if(b==0) return 1;
    
    long long val = power(a,b/2);
    long long ans = ((val%mod) * (val%mod))%mod;

    if(b%2==1) ans = ((a%mod) * (ans%mod))%mod;

    return ans;
}

int main(){

    long long n,k;
    cin>>n>>k;

    long long x = n-1, y = k-1;

    long long maxi = max(x,y);
    fact.resize(maxi+1,-1);
   
    preCompute(maxi);

    long long ans = ((fact[y]%mod) * (power(fact[x],mod-2)%mod))%mod;

    ans = (ans * (power(fact[y-x],mod-2)%mod))%mod;

    cout<<ans;

   
}