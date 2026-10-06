// Extended Euclidean Algo

// find integer solu. of ax + by = gcd(a,b)

# include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int &x, int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }

    int x1,y1;
    int g = gcd(b,a%b,x1,y1);
    x=y1;
    y=x1 - y1*(a/b);
    return g;
}

int main(){
    int a,b;
    cin>>a>>b;

    int p = min(a,b);
    int q = max(a,b);

    int x,y;

    int g = gcd(p,q,x,y);

    cout<<"gcd : "<<g<<endl;

    cout<<"x : "<<((p==a) ? x : y)<<endl;
    cout<<"y : "<<((p==a) ? y : x)<<endl;

    

    
    
}