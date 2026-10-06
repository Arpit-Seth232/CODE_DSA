# include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    for(int k=0;k<t;k++){

        int n;
        cin>>n;

        string a,b;
        cin>>a>>b;

        int cntAE = 0 , cntAO =0, cntBE = 0 , cntBO =0;

        for(int i=0;i<n;i++){
            if(i%2==0){
                cntAE += (a[i] == '1' ? 1 : 0);
                cntBE += (b[i] == '1' ? 1 : 0);
            }
            else{
                cntAO += (a[i] == '1' ? 1 : 0);
                cntBO += (b[i] == '1' ? 1 : 0);
            }
        }

        if(cntAE == cntBE && cntAO == cntBO){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
}
