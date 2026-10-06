# include <bits/stdc++.h>

using namespace std;

int main(){

    freopen("gymnastics.in","r",stdin);
   
    int k,n;
    cin>>k>>n;


    vector<vector<int>>v(n+1);

    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            int cow;
            cin>>cow;
            v[cow].push_back(j+1);
        }
    }

    int cnt = 0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int win_i = 0;
            for(int m=0;m<k;m++){
                if(v[i][m] < v[j][m]){
                    win_i++;
                }
            }
            if(win_i == k || win_i == 0){
                cnt++;
            }
            
        }
    }

      freopen("gymnastics.out","w",stdout);

    cout<<cnt;
}