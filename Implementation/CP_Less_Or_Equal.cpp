// C. Less or Equal

# include <bits/stdc++.h>

using namespace std;

int main(){

    int n,k;
    cin>>n>>k;

    vector<int>v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end());
    if(k==0 ){
        if(v[0]>1){
            cout<<v[0]-1;
        }
        else{
            cout<<-1;
        }

    }

    else if((k-1<n-1 && v[k-1] == v[k])){
        
            cout<<-1;

    }
    else{
    cout<<v[k-1];
    }

}