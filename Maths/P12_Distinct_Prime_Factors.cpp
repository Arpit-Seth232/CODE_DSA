#include <bits/stdc++.h>
using namespace std;

int N = 1000000;

// spf => smallest prime factor
vector<int>spf(N+1,0);
vector<int>dpf(N+1,0);

void createSieve(){
   
    for(int i=0;i<=N;i++){
        spf[i] = i;
    }
    
    for(int i=2;i*i<=N;i++){
        if(spf[i] == i){
            
            for(int j=i*i;j<=N;j+=i){
                if(spf[j]==j){
                    spf[j] = i;
                }
            }


        }
    }

    for(int i=2;i<=N;i++){
        dpf[i] = dpf[i/spf[i]] + (spf[i] != spf[i/spf[i]] ? 1 : 0);
    }



}

int main(){

    int n;
    cin>>n;

    createSieve();

    for(int i=1;i<=n;i++){
        cout<<i<<" "<<dpf[i]<<endl;
    }

}