// A. Tram

# include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;

    long long curr =0;
    long long max_cnt = 0;

    int ai,bi;

    for(int i=0;i<n;i++){
        cin>>ai>>bi;

        curr = curr-ai+bi;
        max_cnt = max(max_cnt,curr);
    }

    cout<<max_cnt<<endl;
}