// A. Chewbaсca and Number

# include <bits/stdc++.h>

using namespace std;

int main(){

    long long n;
    cin>>n;

    string ans = "";

    while(n>0){
        int rem = n%10;
        
        int val = (((n!=9) && (9-rem < rem)) ? (9-rem) : rem);
        ans = to_string(val) + ans;
        n/=10;
    }

    cout<<ans;
}