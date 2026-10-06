// # Make Almost Equal With Mod

# include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<long long>v(n);



        for(int i=0;i<n;i++){
            cin>>v[i];
            
        }

        

           for(int i=1;i<=60;i++){
            long long k = 1LL<<i;
            set<long long>s;
            for(int j=0;j<n;j++){
               s.insert(v[j]%k);
            }
            
            if(s.size()==2){
                cout<<k<<endl;
                break;
            }
        }

          
    }
}