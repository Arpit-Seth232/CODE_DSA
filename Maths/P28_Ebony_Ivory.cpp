// https://codeforces.com/contest/633/problem/A

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

    x = y1;
    y = x1 - y1*(a/b);

    return g;
}

bool find_any_solution(int p, int q,int a, int b, int c, int &x0, int &y0){
    int g = gcd(p,q,x0,y0);

    if(c%g!=0){
        return false;
    }

    x0 = x0 * (c/g);
    y0 = y0 * (c/g);

    int x = ((p==a) ? x0 : y0); 
    int y = ((p==a) ? y0 : x0); 

    x0 = x, y0 = y;

    int dx = b/g, dy = a/g;

    int kMin;
    if (x0 >= 0)
        kMin = -(x0/dx);
    else
        kMin = (-x0 + dx - 1) / dx;


    int kMax = y0/dy;

    return (kMin<=kMax);

    
}

int main(){

    int a,b,c;
    cin>>a>>b>>c;

    int p = min(a,b);
    int q = max(a,b);

    int x0,y0;

    bool ans = find_any_solution(p,q,a,b,c,x0,y0);

    if(ans){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    
}