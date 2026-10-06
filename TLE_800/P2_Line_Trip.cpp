# include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
    int n,k;
    cin>>n>>k;

    vector<int>v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    

    int st = 0;
    int maxi = 0;

    for(int i=0;i<n;i++){
        maxi = max(maxi,v[i]-st);
        st = v[i];
    }

    maxi = max(maxi, 2*(k-st));

    cout<<maxi<<endl;
    }

}