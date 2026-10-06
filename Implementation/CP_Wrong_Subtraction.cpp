// A. Wrong Subtraction

# include <bits/stdc++.h>
using namespace std;

int main(){

    long long n; int k;
    cin>>n>>k;

    while(k>0){

        int rem = n%10;
        if(rem!=0){
        int mini = min(rem,k);
        n -= mini;
        k -=mini;
        }
        else{
            n/=10;
            k--;
        }
    }

    cout<<n;
}