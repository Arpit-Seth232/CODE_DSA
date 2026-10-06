// A. Arrival of the General

# include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int>v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int max_idx = 0,min_idx = 0;

    for(int i=0;i<n;i++){

        if(v[i] > v[max_idx]) max_idx = i;
        if(v[i]<= v[min_idx]) min_idx = i;
    }

    long long t_swap = 0;

    if(max_idx > min_idx){
        t_swap += max_idx + (n-1-min_idx) - 1;
    }
    else{
        t_swap += max_idx + (n-1-min_idx);
    }

    cout<<t_swap;
}