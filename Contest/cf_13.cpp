# include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        long long x,y;
        cin>>x>>y;

        // x^y = x+y-2(x&y) => x&y = 0 => x bits must only contain those bits which are in x+y

        long long k = x & ~(x+y);  // so taking & ~(x+y) which bits are to be removed and that will k, number of operations

        cout<<x+y<<" "<<k<<endl;
        

    }
}