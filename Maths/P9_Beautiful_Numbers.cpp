# include <bits/stdc++.h>

using namespace std;

long long mod = 1e9+7;

long long power(long long a, long long b){
    if(a==0) return 0;
    if(b==0) return 1;

    long long val = power(a,b/2);
    long long ans = ((val%mod) * (val%mod))%mod;

    if(b%2==1) ans = (ans * (a%mod))%mod;

    return ans;
}

void preCompute(vector<long long>&fact){
    fact[0] = 1;
    for(int i=1;i<fact.size();i++){
        fact[i] = (1LL * i * fact[i-1])%mod;
    }
}

bool isGood(int sum,int a, int b){
    while(sum>0){
        int rem = sum%10;
        if(rem!=a && rem!=b) return false;
        sum /=10;
    }
    return true;
}


int main(){
    int a, b, n;
    cin>>a>>b>>n;

    vector<long long>fact(n+1,0);

    preCompute(fact);

    int ans = 0;

    for(int i=0;i<=n;i++){

        int j = n-i;

        int sum = a*i + b*j;

        if(isGood(sum,a,b)){
        int val = ((fact[n]%mod) * (power(fact[i],mod-2)%mod))%mod;
        val = (val * (power(fact[n-i],mod-2)%mod))%mod;
        
        ans = ((ans%mod) + (val%mod))%mod;

        }

    }

    cout<<ans;

}
