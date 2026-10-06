# include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;

    bool isHard = false;

    int val;

    for(int i=0;i<n;i++){

        cin>>val;

        if(val) isHard = true;

    }

    if(isHard){
        cout<<"Hard";
    }
    else{
        cout<<"Easy";
    }
}