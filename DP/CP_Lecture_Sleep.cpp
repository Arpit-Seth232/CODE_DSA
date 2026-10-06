// B. Lecture Sleep

# include <bits/stdc++.h>

using namespace std;

int main(){

    int n, k;
    cin>>n>>k;


    vector<int>theorem(n);
    vector<int>sleep(n);
    vector<long long>p(n);
    vector<long long>s(n);
    vector<long long>pre(n);

    for(int i=0;i<n;i++){
        cin>>theorem[i];
    }

    for(int i=0;i<n;i++){
        cin>>sleep[i];
    }

    p[0] = theorem[0] * sleep[0];
    s[n-1] = theorem[n-1] * sleep[n-1];
    pre[0] = theorem[0]; 

    for(int i=1;i<n;i++){
        p[i] = (theorem[i] * sleep[i]) + p[i-1];
    }
    for(int i=n-2;i>=0;i--){
        s[i] = (theorem[i] * sleep[i]) + s[i+1];
    }
    for(int i=1;i<n;i++){
        pre[i] = theorem[i] + pre[i-1];
    }

    long long ans = 0;

    for(int i=0;i<n-k+1;i++){
        long long run_sum = 0;
        if(i>0) run_sum += p[i-1];
        run_sum += pre[i+k-1];
        if(i>0) run_sum -= pre[i-1];
        if(i+k < n) run_sum += s[i+k];

        ans = max(ans,run_sum);
    }

    cout<<ans;
    
}