# include <bits/stdc++.h>

using namespace std;

long long mygcd(long long a, long long b){

    if(b==0) return a;
    return mygcd(b,a%b);
}

int main(){
    long long a,b;
    cin>>a>>b;


    if(a>b){
        cout<<mygcd(a,b);
    }
    else{
        cout<<mygcd(b,a);
    }
    
}