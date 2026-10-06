// https://codeforces.com/problemset/problem/2108/A

# include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        long long sum = 0;
        int s=0,e=n-1;

        while(s<e){
            sum += 2*(e-s);
            s++;
            e--;
        }

        cout<<(sum/2)+1<<endl;
    }
}