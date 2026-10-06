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


        vector<int>evenA;
        vector<int>oddA;
        vector<int>evenB;
        vector<int>oddB;

        for(int i=0;i<n;i++){
           
            if(i%2==0){
                if(a[i]=='1')evenA.push_back(i/2);
                if(b[i]=='1')evenB.push_back(i/2);
            }
            else{
               if(a[i]=='1') oddA.push_back(i/2);
                if(b[i]=='1')oddB.push_back(i/2);
            }
        
        }

        if(evenA.size() == evenB.size() && oddA.size() == oddB.size()){
            int cnt = 0;

            for(int j=evenA.size()-1;j>=0;j--){
                cnt += abs(evenA[j] - evenB[j]);
            }
            for(int j=oddA.size()-1;j>=0;j--){
                cnt += abs(oddA[j] - oddB[j]);
            }

            cout<<cnt<<endl;
        }
        else{
            cout<<-1<<endl;
        }

    }
}
