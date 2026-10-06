# include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    for(int k=0;k<t;k++){

        int n;
        cin>>n;

        string s;
        cin>>s;

        int cnt0 = (s[0] == '0' ? 1 : 0);
        int cnt1 = (s[0] == '1' ? 1 : 0);
        vector<pair<int,int>>v;

        
        for(int i=1;i<n;i++){
            if(s[i] == '0' && s[i-1] == '0'){
                cnt0++;
            }
            else if(s[i] == '1' && s[i-1] == '1'){
                cnt1++;
            }
            else{
                if(cnt0 > 0) v.push_back({cnt0,0});
                if(cnt1 > 0) v.push_back({cnt1,1});

                cnt0 = (s[i] == '0' ? 1 : 0);
                cnt1 = (s[i] == '1' ? 1 : 0);
                
            }
        }

        if(cnt0 > 0) v.push_back({cnt0,0});
        if(cnt1 > 0) v.push_back({cnt1,1});

        int del0 = 0;
        int del1 = 0;

        for(int i = 0;i<v.size();i++){
            if(v[i].first > 1){
                if(v[i].second == 0) del0 += (v[i].first - 1);
                else del1 += (v[i].first - 1);
            }
        }

        if(abs(del0 - del1)<=1){
            cout<<del0 + del1<<endl;
        }
        else{
            
        }

        


    }
}