# include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;

    vector<long long>v(n+1);

    v[0]=1;

    for(int i=1;i<=n;i++){
        v[i] = v[i-1]*2;
    }

    for(int i=2;i<=n;i++){
        v[i] += v[i-1];
    }

    cout<<v[n];
    
}