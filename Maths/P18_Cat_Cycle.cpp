# include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,h;
        cin>>n>>h;

        if(n%2==0){
            cout<< (h%n == 0 ? n : h%n)<<endl;
        }
        else{
            int catA = (h%n == 0 ? 1 : n+1 - (h%n));

            int mid = (n+1)/2;
            int cnt = (h/mid);

            cout<< ((catA+cnt)%n == 0 ? 1 : (catA+cnt)%n )<<endl;
        }

    }
}