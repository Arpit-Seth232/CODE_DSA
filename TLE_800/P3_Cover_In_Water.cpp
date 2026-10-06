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

        vector<int>b;
        for(int i=0;i<n;i++){
            if(s[i]=='#') b.push_back(i);
        }
        b.push_back(n);


        int prev = -1;

        int cnt = 0;

        for(int i=0;i<b.size();i++){
            int emp = b[i]-prev-1;
            if( emp<3) cnt += emp;
            else cnt += (emp+1)/2;

            prev = b[i];
        }

        cout<<cnt<<endl;
        

    }
}