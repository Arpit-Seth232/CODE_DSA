// A. Nearly Lucky Number

# include <bits/stdc++.h>

using namespace std;

bool checkLucky(long long n){
    if(n==0) return false;
    while(n>0){
        int rem = n%10;
        if(n!=4 && n!=7) return false;
        n/=10;
    }

    return true;
}

int main(){

    long long num;
    cin>>num;

    long long cnt =0;

    while(num>0){
        int rem = num%10;
        if(rem == 4 || rem== 7) cnt++;
        num /=10;
    }

    cout<< (checkLucky(cnt) ? "YES" : "NO");

}