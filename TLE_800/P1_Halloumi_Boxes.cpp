# include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        vector<int>v(n);

        int prev = 0;
        bool sorted = true;

        for(int i=0;i<n;i++){
            cin>>v[i];
            if(prev > v[i]) sorted = false;
            prev = v[i];
        }

        if(sorted || k>=2){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }


    }
}