// https://codeforces.com/problemset/problem/1743/A

# include <bits/stdc++.h>
using namespace std;

vector<long long> fact(11,1);

void calc(){
    for(int i=2;i<11;i++){
        fact[i] = 1LL * i * fact[i-1];
    }
}

int main(){

    int t;
    cin>>t;

    calc();

    while(t--){
        int n;
        cin>>n;

        for(int i=0;i<n;i++){
            int x;
            cin>>x;
        }

        int m = 10-n;

        long long div = 1LL * 2 * fact[m-2];
        long long ans = (1LL * fact[m])/div;

        cout<<1LL * 6 * ans<<endl;

    }
}