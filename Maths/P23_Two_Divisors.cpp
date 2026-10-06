// https://codeforces.com/contest/1916/problem/B

# include <bits/stdc++.h>
using namespace std;

long long findMini(long long a, long long b){
    long long mini = min(a,b);
    for(long long i=2;i*i <= mini;i++){
        if(a%i==0 || b%i==0){
            return i;
        }
    }

    return (a>1 ? a : b);
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int a,b;
        cin>>a>>b;

        long long val = 1LL*a*b;
        val = val/(__gcd(a,b));

        if(val>a && val>b){
            cout<<val<<endl;
        }
        else{
            long long mini = findMini(a,b);
            cout<<1LL*val*mini<<endl;
        }
        
    }
}