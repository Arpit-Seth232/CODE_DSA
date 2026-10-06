// A. Sum of Round Numbers

# include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    vector<string>v;

    for(int i=0;i<n;i++){
        int num;
        cin>>num;

        string val = to_string(num);
        string temp = "";

        for(int j=val.size()-1;j>=0;j--){

            if(val[j]!='0'){

                string p = to_string(val[j]-'0')+temp;
                

                v.push_back(p);
            }

            temp +="0";

        }

        cout<<v.size()<<endl;
        for(int k=0;k<v.size();k++){
            cout<<v[k]<<" ";
        }
        cout<<endl;
        v.clear();
    }
}