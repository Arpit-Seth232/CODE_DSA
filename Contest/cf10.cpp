#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int>v(n);
        map<int,vector<int>>mp;

        for(int i=0;i<n;i++){
            cin>>v[i];
            mp[v[i]].push_back(i);
        }

        vector<char>ch(n,'C');
        int val = 0;
        int sum = -1, mx = -1;
        while(mp.find(val)!=mp.end()){
            if(mp[val].size()==1){
                ch[mp[val][0]]='A';
                sum = 2*val + val+1;
                mx = 2*(val+1);

                break;
            }
            else if(mp[val].size()==2){
                ch[mp[val][0]]='A';
                ch[mp[val][1]] = 'B';
                sum = val + 2*(val+1);
                mx = 2*(val+1);
                break;
            }
            else{
                ch[mp[val][0]]='A';
                ch[mp[val][1]] = 'B';

                val++;
            }
        }

        if((sum == -1 && mx == -1) || (sum >= mx)){
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++){
                cout<<ch[i];
            }
            cout<<endl;
        }

        else{
            cout<<"NO"<<endl;
        }
       
    }
}