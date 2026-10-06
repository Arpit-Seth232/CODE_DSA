# include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int>freq(101,0);
        set<int>s;

        for(int i=0;i<n;i++){
            int val;
            cin>>val;

            s.insert(val);
            freq[val]++;
        }

        while(!s.empty()){
            int val = *s.rbegin();

            int fq = freq[val];

            auto it = s.end();

            while(it != s.begin()){

                --it;

                int mn = min(fq,freq[*it]);

                for(int i=0;i<mn;i++){
                    cout<<*it<<" ";
                }

                freq[*it] -= mn;

                if(freq[*it]==0){
                    it = s.erase(it);
                }
            }
            

        }

        cout<<endl;

    }
}