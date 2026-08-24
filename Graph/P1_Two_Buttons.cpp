// CF
// B. Two Buttons

# include <bits/stdc++.h>

using namespace std;

int calc(int st, int &end){
    
    vector<int>dist(1e5,INT_MAX);    

    set<vector<int>>s;

    s.insert({0,st});
    

    while(!s.empty()){
        auto v = *s.begin();
        int dis = v[0] , val = v[1];

        s.erase(v);

        if (val<end){
            if(val-1 > 0 && dist[val-1] > dis + 1) {
                dist[val-1] = dis+1;
                s.insert({dis+1,val-1});
            }  
            if(dist[val*2] > dis +1){ 
                dist[val*2] = dis+1;
                s.insert({dis+1,val*2});
            }
        }
        else if(val>end){
            if(dist[end] > dis+(val-end)){
                dist[end] = dis+(val-end);
                s.insert({dist[end],end});
            }
        }

    }

    return dist[end];
}

int main(){

    int n,m;
    cin>>n>>m;


    if(n==m){
        cout<<0;
    }
    else cout<<calc(n,m);
}