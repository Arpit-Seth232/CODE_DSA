// The 3 trigger questions to ask yourself on any contest problem:

// 1. Can I expand/simplify the formula?
// 2. What does each element contribute independently?
// 3. What's constant vs what changes with my choices?

// D. Array Splitting

# include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    vector<long long>v(n),suff(n);

    for(int i=0;i<n;i++) cin>>v[i];

    suff[n-1] = v[n-1];

    for(int i=n-2;i>=0;i--){
        suff[i] = suff[i+1]+v[i];
    }

    long long ans = suff[0];

    sort(suff.begin()+1,suff.end(),greater<long long>());

    for(int i=1;i<=k-1;i++){
        ans += suff[i];
    }

    cout<<ans;
}