// A. BowWow and the Timetable

# include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    int i=s.size()-1;
    int cnt =0;
    int cnt1=0;
    while(i>=0){
        if(s[i]=='1' && (i>0 || cnt1>0)){
            cnt++;
            cnt1++;
        }
        else if(s[i]=='0' && i>0){
            cnt++;
        }
        if(i-1>=0 && s[i-1]=='1') cnt1++;
        i-=2;
    }

    cout<<cnt;
}