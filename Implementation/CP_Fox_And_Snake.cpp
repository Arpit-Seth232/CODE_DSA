// A. Fox And Snake

# include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<char>>v(n,vector<char>(m,'.'));

    int left = 0;

    for(int i=0;i<n;i++){

        if(i%2==0){
            for(int j=0;j<m;j++){
                v[i][j] = '#';
            }
        }

        else{

            if(left == 0){
                v[i][m-1] = '#';
                left=1;
            }
            else{
                v[i][0] = '#';
                left=0;
            }
        }


    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }
}