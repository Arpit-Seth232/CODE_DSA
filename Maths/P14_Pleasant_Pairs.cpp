// B. Pleasant Pairs

# include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;


    while(t--){
    int n;
    cin>>n;

    vector<int>v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    int cnt =0;
    for(int i=0;i<n;i++){

        for(int x=1;x*v[i]<=2*n;x++){

            int j = x*v[i]-i-2;

            if(j>i && j<n && v[j]==x){
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;
} 

}   