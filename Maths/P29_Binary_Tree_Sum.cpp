// https://codeforces.com/problemset/problem/1843/C

# include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        long long n;
        cin>>n;

        long long sum = 1;

        while(n>1){
            sum+=n;
            if(n%2==0) n/=2;
            else n = (n-1)/2;
        }

        cout<<sum<<endl;
    }
}