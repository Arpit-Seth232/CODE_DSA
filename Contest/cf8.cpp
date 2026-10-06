# include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int>odd,even;
        for(int i=0;i<n;i++){
            int val;
            cin>>val;

            if(val%2 == 0) even.push_back(val);
            else odd.push_back(val);
        }

        int cntodd = odd.size();
        int cnt0=0, cnt2 =0;
        for(int i=0;i<even.size();i++){
            if(even[i]%4==0) cnt0++;
            else cnt2++;
        }


        cout<<max({cntodd,cnt0,cnt2})<<endl;

    }
}