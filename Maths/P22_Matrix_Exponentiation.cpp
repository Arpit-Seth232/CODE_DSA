// Finding nth fibonacci with matrix exponentiation O(log n)
// https://codeforces.com/problemset/gymProblem/102644/C

# include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

vector<vector<int>>A = {{0,1},{1,1}};
vector<vector<int>>I = {{1,0},{0,1}};

vector<vector<int>>st = {{0},{1}};

vector<vector<int>>matMul(vector<vector<int>>v1, vector<vector<int>>v2){
    int r = v1.size();
    int m = v2.size();
    int c = v2[0].size();


    vector<vector<int>>res(r,vector<int>(c));

    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int sum =0;

            for(int k=0;k<m;k++){
                int mul= (1LL * v1[i][k] * v2[k][j])%mod;
                sum = (1LL * sum + mul)%mod;
            }

            res[i][j] = sum;
        }
    }

    return res;
}

vector<vector<int>> power(vector<vector<int>>v,long long b){
    if(b==0) return I;
    
    vector<vector<int>> val = power(v,b/2);
    vector<vector<int>> ans = matMul(val,val);
    
    if(b%2==1) ans = matMul(ans,v);

    return ans;

}



int main(){

    long long n;
    cin>>n;

    if(n==0) cout<<0;
    else if(n==1) cout<<1;
    else{
        vector<vector<int>>powerA = power(A,n-1);
        vector<vector<int>> ans = matMul(powerA,st);

        // for(int i=0;i<2;i++){
        //     for(int j=0;j<2;j++){
        //         cout<<powerA[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        cout<<ans[1][0]<<endl;
    }


    

}