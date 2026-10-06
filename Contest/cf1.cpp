# include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    for(int k=0;k<t;k++){
        int a,b,c;
        cin>>a>>b>>c;

        int maxi = max({a,b,c});
        int mini = min({a,b,c});
        int mid;
        if(a!=maxi && a!=mini){
            mid = a;
        }
        else if(b!=maxi && b!=mini){
            mid = b;
        }
        else{
            mid = c;
        }

        int diff1 = abs(maxi-mid);
        int diff2 = abs(mid-mini);

        cout<<min(diff1,diff2)<<endl;
    }
}