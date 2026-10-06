// A. Anton and Polyhedrons

# include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;

    string st;

    long long ans = 0;

    for(int i=0;i<n;i++){
        cin>>st;

        if(st == "Tetrahedron"){
            ans+=4;
        }
        else if(st == "Cube"){
            ans+=6;
        }
        else if(st == "Octahedron"){
            ans+=8;
        }
        else if(st=="Dodecahedron"){
            ans+=12;
        }
        else{
            ans+=20;
        }


    }

    cout<<ans;
}