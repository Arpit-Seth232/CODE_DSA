// A. The New Year: Meeting Friends

# include<bits/stdc++.h>

using namespace std;

int main(){

    int x1,x2,x3;
    cin>>x1>>x2>>x3;

    int max_x=max({x1,x2,x3});
    int min_x = min({x1,x2,x3});

    int mid_val = (x1>x2) ? ((x2>x3) ? x2 : x3) : ((x1>x3) ? x1 : x3);


    cout<<(abs(max_x-mid_val) + abs(min_x - mid_val));
    
}