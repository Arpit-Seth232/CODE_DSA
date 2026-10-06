// G. Short Task

#include <bits/stdc++.h>

using namespace std;

int N = 10000000;

// spf => smallest prime factor
vector<int>spf(N+1,0);
vector<int>sum_f(N+1,INT_MAX);

void createSieve(){
   
    
    sum_f[1] = 1;

    for(int i=1;i<=N;i++){

            for(int j=i;j<=N;j+=i){

                spf[j] += i;

            }

       
    }

    for(int i=2;i<=N;i++){
        if(spf[i]<=N) sum_f[spf[i]] = min(i,sum_f[spf[i]]);
    }

   



}

int main(){

    int t;
    cin>>t;

    createSieve();

    while(t--){
        int c;
        cin>>c;

        // cout<<"Output : ";

        if(c<=N) cout<<(sum_f[c] == INT_MAX ? -1 : sum_f[c])<<endl;
        else cout<<-1<<endl;
        
       
    }

}

