// A. Bit++

# include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;

    long long x =0;

    for(int i=0;i<n;i++){
        string st;
        cin>>st;

        if(st[0]=='+' || st[st.size()-1]=='+'){
            x++;    
        }
        else{
            x--;
        }
    }

    cout<<x;
}