# include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int>v(n);

        int cnt0 = 0;
        for(int i=0;i<n;i++){
            cin>>v[i];

            if(v[i]==0) cnt0++;
        }

        if(cnt0<2) cout<<-1<<endl;
        else{

            if(v[0]==0 && v[n-1]==0){
                cout<<0<<endl;
            }
            else if(v[0]==0 || v[n-1]==0){
                cout<<1<<endl;
            } 
            else{
                cout<<2<<endl;
            }


        }

    }
}