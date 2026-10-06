// A. Beautiful Matrix

# include <bits/stdc++.h>

using namespace std;
int main(){

    int c_i=0,c_j=0;

    int val;

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){

            cin>>val;

            if(val==1){
                c_i = i;
                c_j = j;
                break;
            }
            
        }
    }

    cout<<(abs(2-c_i) + abs(2-c_j));
}