// https://codeforces.com/problemset/problem/1025/B

# include <bits/stdc++.h>
using namespace std;

set<long long>fc;

void findPF(long long a){

    
    for(long long p=2; p*p <=a;p++){
        if(a%p == 0){
            fc.insert(p);
            
            while(a%p==0){
                a/=p;
            }
        }
    }
    
        if(a>1) fc.insert(a);
}


int main(){
     int n;
     cin>>n;
     vector<pair<long long, long long>>v(n);

     for(int i=0;i<n;i++){
        long long a,b;
        cin>>a>>b;

        v[i] = {a,b};
     }

     findPF(v[0].first);
     findPF(v[0].second);
 

     for(int i=1;i<n;i++){
        
        for(auto it = fc.begin(); it != fc.end(); ){
            if(v[i].first % *it != 0 && v[i].second % *it != 0){
                it = fc.erase(it);
            }
            else{
                ++it;
            }
        }
     }

     if(fc.empty()){
        cout<<-1<<endl;
     }
     else{
        cout<<*fc.begin()<<endl;
     }
     
}