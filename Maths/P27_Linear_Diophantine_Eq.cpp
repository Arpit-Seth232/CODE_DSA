// Linear Diophantine Equation

// Find integer any solution of ax+by = c (if exists)

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

bool find_any_solution(int a, int b, int c, int &x0, int &y0){
    int g = gcd(abs(a),abs(b),x0,y0);

    if(c%g!=0){
        return false;
    }

    x0 = x0 * (c/g);
    y0 = y0 * (c/g);

    if(a<0) x0 = -x0;
    if(b<0) y0 = -y0;

    return true;
}

int main(){

    int a,b,c;
    cin>>a>>b>>c;

    int p = min(abs(a),abs(b));
    int q = max(abs(a),abs(b));

    int x0,y0;

    bool ans = find_any_solution(p,q,c,x0,y0);

    if(ans){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    
}