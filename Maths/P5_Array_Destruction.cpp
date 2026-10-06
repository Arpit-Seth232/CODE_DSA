// C. Array Destruction

# include <bits/stdc++.h>
using namespace std;

bool verify(int curr_mx, vector<pair<int,int>>&ans ,multiset<int>ms ){
    
    while(!ms.empty()){
    
    int val = *ms.rbegin();

    ms.erase(ms.find(val));

    if(ms.find(curr_mx-val)== ms.end()){
        return false;
    }

    ans.push_back({val,curr_mx-val});
    ms.erase(ms.find(curr_mx-val));

    curr_mx = val;

    }

    return true;

}

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        multiset<int>s;
        vector<int>v(2*n);

        for(int i=0;i<2*n;i++){ 
            cin>>v[i];
            s.insert(v[i]);
        }

        sort(v.rbegin(),v.rend());

        vector<int>val;
        for(int i=1;i<2*n;i++){
            val.push_back(v[0]+v[i]);
        }

        bool found = false;

        vector<pair<int,int>>ans;
        for(int i=0;i<val.size();i++){
            if(verify(val[i],ans,s)){
                cout<<"YES"<<endl;
                cout<<val[i]<<endl;
                for(auto it : ans){
                    cout<<it.first<<" "<<it.second<<endl;
                }
                found = true;
                break;
            }
            ans.clear();
        }

        if(!found){
            cout<<"NO"<<endl;
        }


    }
}