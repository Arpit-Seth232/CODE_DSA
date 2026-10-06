# include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    for(int k=0;k<t;k++){
        int n;
        cin>>n;

        vector<int>v(n);

        vector<int>freq(1001);

        int maxi = 0;
        int sum = 0;
        int cnt = 0;
          
        for(int i=0;i<n;i++) {
            cin>>v[i];
            sum+=v[i];
            freq[v[i]]++;

            if(cnt == freq[v[i]]){
                maxi = max(maxi,v[i]);
            }

            else if(cnt<freq[v[i]]){
               
                cnt = freq[v[i]];
                maxi = v[i];
            }
        }

        int other = n - cnt;

        if(cnt <= other+1){
            cout<<sum<<endl;
        }

        else{
            cout<< sum - (cnt*maxi) + ((other + 2) * maxi)<<endl; 

        }

        
    }
}