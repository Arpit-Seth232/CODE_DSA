# include <bits/stdc++.h>
using namespace std;

vector<bool>isPrime(1e6+1,true);
vector<int>pre(1e6+1,0);

void sieve(){
    isPrime[0] = false;
    isPrime[1] = false;

    for(int i=2;i*i <= 1e6;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=1e6;j+=i){
                isPrime[j] = false;
            }
        }
    }

    for(int i=2;i<=1e6;i++){
        pre[i] = pre[i-1] + (isPrime[i] ? i : 0);
    }

    
}



int main(){

    int n;
    cin>>n;

    sieve();

    cout<<pre[n];

}