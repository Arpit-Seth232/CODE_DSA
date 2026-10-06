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

        vector<int>neg;
        
        int first1 = 1e8;
        int last1 = -1;

        for(int i=0;i<n;i++){
            if(v[i]==-1) neg.push_back(i);

            if(v[i] == 1) {
                first1 = min(first1,i);
                last1 =  max(last1,i);
            }   
           
        }

        if(neg.size()>0 && neg[0]<first1){
            v[neg[0]] = 1;
        }

        if(neg.size()>0 && neg[neg.size()-1]>last1){
            v[neg[neg.size()-1]]=1;
        }

        if(neg.size()>0){
        for(int i=1;i<neg.size()-1;i++){
            v[neg[i]]=0;
        }
        }

        for(int i=0;i<n;i++){
            if(v[i]==-1) cout<<0<<" ";
            else cout<<v[i]<<" ";
        }
       
        cout<<endl;
        
        

        }

    
}