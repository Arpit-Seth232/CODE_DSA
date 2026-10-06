# include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        string s;
        cin>>s;

        vector<pair<int,int>>pre(n,{0,0});
        vector<pair<int,int>>suf(n,{0,0});

        if(s[0]=='0'){
            pre[0].first++;
        }
        else{
            pre[0].second++;
        }

        if(s[n-1]=='0'){
            suf[n-1].first++;
        }
        else{
            suf[n-1].second++;
        }



        for(int i=1;i<n;i++){
           if(s[i]=='0'){
            pre[i].first++;
        }
        else{
            pre[i].second++;
        }

        pre[i].first += pre[i-1].first;
        pre[i].second += pre[i-1].second;

        }

        for(int i=n-2;i>=0;i--){

            if(s[i]=='0'){
            suf[i].first++;
        }
        else{
            suf[i].second++;
        }

        suf[i].first += suf[i+1].first;
        suf[i].second += suf[i+1].second;


        }

        if(s[0]=='1'){
            cout<<suf[0].first<<endl;
            continue;
        }

        int ans = n;

        for(int i=1;i<n;i++){
            int val = 0;
            
            if(s[i]=='1'){
                val += pre[i-1].second;
                if(i+1<n) val += suf[i+1].first;

                ans = min(ans,val);

            }
            else{
                val += pre[i-1].second;
                if(i+1<n) val+= suf[i+1].second;

                ans = min(ans,val);
            }
            
        }

        cout<<ans<<endl;

    }
}
