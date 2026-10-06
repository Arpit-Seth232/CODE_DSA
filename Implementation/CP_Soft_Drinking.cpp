// A. Soft Drinking

# include <bits/stdc++.h>

using namespace std;

int main(){

    int n, k, l, c, d, p, nl, np;

    cin>>n>>k>>l>>c>>d>>p>>nl>>np;

    long long slices = c*d;
    long long t_cnt_d = (k*l) / nl;
    long long t_cnt_s = p/np;

    cout<<(min({slices,t_cnt_d,t_cnt_s})/n);
}