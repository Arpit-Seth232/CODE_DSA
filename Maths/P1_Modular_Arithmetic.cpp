// 🧩 MAIN PROBLEM — Topic: Modular arithmetic & fast exponentiation

// CF 1100–1300 level | ⏱ 25 minutes

// Compute (a^b) % MOD where:

// 1 ≤ a ≤ 10^9
// 1 ≤ b ≤ 10^18
// MOD = 1e9 + 7

// But there's a twist: you're given q queries (up to 10^5), each with a different (a, b) pair. Total runtime must be well within 1 second.

// Extend it: After computing a^b % MOD for each query, also output a^(b-1) % MOD — without making a separate exponentiation call. Reuse your first result.

// Before you write a single line of code:

// State your key observation in plain English:

// How do you compute a^b % MOD fast for large b?
// How do you get a^(b-1) cheaply from a^b?


// Approach : 
// for a^b ,  we can do :
// if b%2 ==0 ,  calculate value = a^(b/2)  and then a^b = value * value
// if b%2 ==1,  calculate value = a^(b/2)  and then a^b  = a * value * value


// and then if we have a^b  then a^(b-1) = (a^b)/a;


# include <bits/stdc++.h>

using namespace std;

long long mod = 1e9+7;

long long power(long long a, long long b){
    if(a==0) return 0;
    if(b==0){
        return 1;
    }

    long long val = power(a,b/2);

    long long ans = ((val%mod) * (val%mod))%mod;

    if(b%2==1) ans = ((ans%mod) * (a%mod))%mod;

    return ans;
}

int main(){

    long long a , b;
    cin>>a>>b;

    long long ans = power(a,b);

    cout<<"Power of a^b : "<< ans<<endl;

    long long inv = power(a,mod-2);

    cout<<"Power of a^(b-1) : "<< ((ans % mod) * (inv %mod))%mod<<endl;

    // cout<<(power(2,10) * power(3,10))%mod;

}