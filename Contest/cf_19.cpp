# include <bits/stdc++.h>

using namespace std;

vector<int>pf(1000000,-1);

void createSieve(){

    for(int i=0;i<1000000;i++){
        pf[i] = i;
    }

    for(int i=2;i*i<1000000;i++){
        if(pf[i]==i){
    
            for(int j = i*i;j<1000000;j+=i){
               if(pf[j]==j) pf[j] = i;
            }   
        }
    }

}

long long findOp(int val, int &k){
    long long t = 0;
    long long cnt = 1;

    while(val>k){
        int  p = pf[val];
        val = val / p;
        t += cnt;
        cnt = cnt * p;
    }

    return t;
}



int main(){
    int t;
    cin>>t;

    createSieve();


    while(t--){
        int n,k;
        cin>>n>>k;

        vector<int>v(n);
        for(int i=0;i<n;i++) cin>>v[i];

        vector<long long>op(n+1,-1);
        for(int i=0;i<=k;i++){
            op[i]=0;
        }

        long long ans = 0;

        for(int i=0;i<n;i++){
            if(op[v[i]]!=-1) ans += op[v[i]];
            else{
                long long p = findOp(v[i],k);
                ans += p;
                op[v[i]] = p;
            }
        }

        cout<<ans<<endl;

    }
}