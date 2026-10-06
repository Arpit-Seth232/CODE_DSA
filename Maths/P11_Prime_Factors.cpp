# include <bits/stdc++.h>
using namespace std;

vector<int>sieve(1000001,0);

void createSieve(){
    
    for(int i=0;i<1000001;i++){
        sieve[i] = i;
    }

    for(int i=2;i*i<=1000000;i++){
        if(sieve[i]==i){

            for(int j=i*i;j<=1000000;j+=i){
                if(sieve[j]==j){
                    sieve[j] = i;
                }
            }

        }

    }
}

void findPrimeFactors(int n){
    while(sieve[n] != n){
        cout<<sieve[n]<<" ";
        n/=sieve[n];
    }
    if(n>1) cout<<n;
}

int main(){
    int t;
    cin>>t;

    createSieve();

    while(t--){
        int n;
        cin>>n;
        findPrimeFactors(n);
        cout<<endl;

    }

    
}