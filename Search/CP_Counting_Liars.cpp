// USACO 2022 US Open Contest, Bronze
// Problem 2. Counting Liars


# include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<char,int>&a, const pair<char,int>&b){
    if(a.second < b.second){
        return true;
    }
    else if(a.second>b.second){
        return false;
    }
    return a.first == 'G';
}

int main(){

    int n;
    cin>>n;

    vector<pair<char,int>>v(n);

    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }

    sort(v.begin(),v.end(),cmp);

    // for(auto it : v){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }

    vector<int>pre(n,0),suff(n,0);

    for(int i=1;i<n;i++){
        pre[i] += pre[i-1];

        if(v[i-1].first == 'L'){
            pre[i]++;
        }
    }

    for(int i = n-2;i>=0;i--){
        suff[i] +=suff[i+1];
        if(v[i+1].first == 'G'){
            suff[i]++;
        }
    }

    int mini = n;
    for(int i=0;i<n;i++){
        mini = min(mini,pre[i]+suff[i]);
    }

    cout<<mini;
}