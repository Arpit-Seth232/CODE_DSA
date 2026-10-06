#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    for(int k=0;k<t;k++){
        int n;
        cin>>n;

        string s;
        cin>>s;

        vector<pair<char,int>>p;
        p.push_back({s[0],1});
        for(int i=1;i<n-1;i++){
            if(s[i]!=p.back().first){
                p.push_back({s[i],1});
            }
            else{
                p.back().second +=1;
            }
        }

        if(s[n-1]!=p.back().first){
                p.push_back({s[n-1],1});
            }
            else{
                p.back().second +=1;
        }




        int mini = p.size();
        if(p.size() <= 2){
            cout<<mini<<endl;
            continue;
        }
        for(int i=1;i<p.size()-1;i++){
            int ps = p.size();
            
          
                if(p[i].second == 1){
                    if(p[i-1].first == p[i+1].first){
                        mini = min(mini,ps-2);
                    }
                    else{
                        mini = min(mini,ps-1);
                    }
                    
                }
                
        
        }


        cout<<mini<<endl;

    }
}