// https://codeforces.com/problemset/problem/630/I

# include <bits/stdc++.h>
using namespace std;

long long power(int a, int b){
    if(a==0) return 0; 
    if(b==0) return 1;

    long long val = power(a,b/2);
    long long ans = 1LL * val * val;

    if(b%2==1) ans = 1LL * a * ans;

    return ans;
}

// long long fact(int a){
//     if(a<2) return 1;
//     long long val = 1LL * a * fact(a-1);
//     return val;
// }

int main(){
    int n;
    cin>>n;

    int spaces = 2*n-2;

    int t_set = spaces/n;
    t_set += (spaces%n);

    long long ans = 1LL * 3 * power(4,t_set-1);

    ans = 1LL * 2 * ans;

    if(t_set-2>0){
    long long rem = (t_set-2)*3*3*power(4,t_set-2);
    ans = ans + rem;
    }


    cout<<ans<<endl;


}