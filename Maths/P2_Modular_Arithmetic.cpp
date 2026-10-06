// 🟢 Level 1 — Warm your hands

// Given n, compute (1 + 2 + 3 + ... + n) % MOD
// where n can be up to 10¹⁸.
// MOD = 1e9+7.

// Formula for sum = n*(n+1)/2. But division under mod — you know what to do.

// 🟡 Level 2 — Modular subtraction trap

// Given a and b, compute (a² - b²) % MOD.
// Constraints: 1 ≤ b ≤ a ≤ 10^18, MOD = 1e9+7.
// Example: a=10, b=3 → (100-9) % MOD = 91.

// Observation before code:

// What is the danger of computing (a²%MOD - b²%MOD) % MOD directly?
// How do you fix it?

// ⏱ 3 minutes. Observation first, then code.

# include <bits/stdc++.h>

using namespace std;

long long mod = 1e9+7;

long long power(long long a, long long b){
    if(a==0) return 0;
    if(b==0) return 1;

    long long val = power(a,b/2);
    long long ans = ((val%mod) * (val%mod))%mod;

    if(b%2==1) ans = ((a%mod) * (ans%mod))%mod;

    return ans;
}



void solve1(){
    long long n = 1000000000000000000LL;
   
    long long v2 = ((n%mod) + 1)%mod;

    long long ans = ((n%mod) * (v2%mod))%mod;

    long long inv = power(2,mod-2);
    ans = ((ans%mod) * inv)%mod;

    cout<<ans;

}

void solve2(){
     long long a,b;
     cin>>a>>b;

     long long asq= power(a,2);
     long long bsq= power(b,2);

     long long ans = (asq%mod - bsq%mod + mod)%mod;
      cout<<ans;
}

void solve3(){
    long long a,b;
    cin>>a>>b;

    
    long long ans = 1;
    while(a>b){
        ans = (ans%mod * a%mod)%mod;
        a--;
    }

    cout<<ans;
    
}


int main(){
    
    // solve1();
    solve3();


}