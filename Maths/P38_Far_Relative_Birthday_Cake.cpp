// A. Far Relative’s Birthday Cake

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char ch;
            cin>>ch;

            if(ch == 'C') v[i][j] = 1;
        }
    }

    long long cnt =0;

    for(int i=0;i<n;i++){
        int r =0 ,c=0;
        for(int j=0;j<n;j++){
            r+=v[i][j];
            c+=v[j][i];
        }

        cnt += ((r*(r-1)/2) + (c*(c-1)/2));
    }

    cout<<cnt<<endl;
}