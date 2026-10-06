# include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        char c;

        cin>>n>>c;

        string s;
        cin>>s;

        int l=0,r=s.size()-1;

        int coins = 0;

        while(l<r){
            if(s[l]!=s[r]){

                if(s[l]!=c) coins++;
                if(s[r]!=c) coins++;
                
            }
            l++;
            r--;
            
        }

        cout<<coins<<endl;
    }
}