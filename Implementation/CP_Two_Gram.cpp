// B. Two-gram

# include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;

    map<string,int>mp;

    string st;
    cin>>st;

    for(int i=0;i<n-1;i++){
        string sub = st.substr(i,2);

        mp[sub]++;
    }

    int max = 0;
    string ans = "";

    for(auto it : mp){
        if(it.second > max){
            ans = it.first;
            max = it.second;
        }
    }

    cout<<ans;

}