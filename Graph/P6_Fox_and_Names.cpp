# include <bits/stdc++.h>
using namespace std;

string ans = "";

void calc( map<char,int>&inDegree,map<char,vector<char>>adj){

    queue<char>q;

    for(auto it : inDegree){
        if(it.second == 0) q.push(it.first);
    }

    while(!q.empty()){
        char node = q.front();
        q.pop();

        ans += node;

        for(auto child : adj[node]){
            inDegree[child]--;
            if(inDegree[child] == 0) q.push(child);
        }
    }

    if(ans.size() != 26){
        cout<<"Impossible";
    }
    else{
        cout<<ans;
    }

}

int main(){

    int n;
    cin>>n;

    vector<string>v(n);
    bool poss = true;

    for(int i=0;i<n;i++) cin>>v[i];

    map<char,int>inDegree;
    map<char,vector<char>>adj;
    for(char ch = 'a'; ch<='z';ch++){
        inDegree[ch] = 0;
        adj[ch] = {};
    }


    for(int i=0;i<n-1;i++){
        string s1 = v[i] , s2 =v[i+1];
        bool diff = false;

        int mini = min(s1.size(),s2.size());

        for(int j=0;j<mini;j++){
            if(s1[j] != s2[j]){
                adj[s1[j]].push_back(s2[j]);
                inDegree[s2[j]]++;
                diff = true;
                break;
            }
        }

        if(!diff && s1.size() > s2.size()) {
            poss = false;
            break;
        }

    }

    if(!poss){
        cout<<"Impossible";
    }
    else{

        calc(inDegree,adj);
    }
    
}