// A. Theatre Square

# include <bits/stdc++.h>
using namespace std;

int main(){

    long long n,m,a;
    cin>>n>>m>>a;

    long long r = ceil((1.0 * n)/a);
    long long c = ceil((1.0 * m)/a);

    // cout<<r<<" "<<c<<endl;

    cout<<(1LL*r*c);


}