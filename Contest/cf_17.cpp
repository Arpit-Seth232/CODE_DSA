# include <bits/stdc++.h>
using namespace std;

int main(){
   int t;
   cin>>t;

   while(t--){
    long long a,b,c;
    cin>>a>>b>>c;

    long long ans = abs(a-b);
    long long val = abs(a+c-b);
    if( val >= ans){
        ans = val;
    }

    cout<<ans<<endl;
    

   }


}