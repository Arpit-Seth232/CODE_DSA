// A. Soldier and Bananas

# include <bits/stdc++.h>

using namespace std;

int main(){

    int k,n,w;
    cin>>k>>n>>w;

    long long total = k * ((w * (w+1))/2);

    cout<< (total > n ? (total - n) : 0);
}