// A. Presents

# include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int>v(n);

    int pi;
    for(int i=0;i<n;i++){
        cin>>pi;

        v[pi-1] = i+1; 

    }

    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

}