// https://codeforces.com/problemset/problem/1364/A

# include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        vector<int>v(n);

        for(int i=0;i<n;i++) cin>>v[i];

        vector<int>pre(n),suff(n);

        pre[0]=v[0] , suff[n-1] = v[n-1];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + v[i];
        }

        for(int i=n-2;i>=0;i--){
            suff[i] = suff[i+1] + v[i];
        }

        if(suff[0]%k!=0){
            cout<<n<<endl;
        }
        else{
            int i=-1,j=-1;
            for(i=0;i<n;i++){
                if(pre[i]%k!=0) break;
            }

            for(j=n-1;j>=0;j--){
                if(suff[j]%k!=0) break;
            }

            int ele = -1;

            if(i != -1) ele = max(ele,(n-i-1));
            if(j != -1) ele = max(ele, j);

            cout<<ele<<endl;
        }
    }
}