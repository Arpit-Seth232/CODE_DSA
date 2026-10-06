// https://codeforces.com/problemset/problem/199/A

# include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int>fib;

    int p = 0, q=0;
    fib.push_back(0);

    if(n>=1) {
        fib.push_back(1);
        q = 1;
    } 

    for(int i=2;q<n;i++){
        int val = p + q;
        if(val>n) break;
        fib.push_back(val);
        p=q;
        q=val;
    }

    
    bool found = false;

    int m = fib.size();

    for(int i=m-1;i>=0;i--){
        int val = n-fib[i];
        

        int s=0,e=i;
        int idx = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(fib[mid]==val){
                idx = mid;
                break;
            }
            else if(fib[mid]<val){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }

        if(idx != -1){
            cout<<0<<" "<<val<<" "<<fib[i]<<endl;
            found = true;
            break;
        }


    }

    if(!found){
    cout<<"I'm too stupid to solve this problem"<<endl;
    }


}