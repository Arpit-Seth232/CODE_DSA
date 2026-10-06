// Treasure Hunt


# include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;

    

    string s1,s2,s3;
    cin>>s1>>s2>>s3;

    long long m = s1.size();

    if(m==1){
        cout<<"Draw";
        return 0;
    }


    map<char,long long>mp1,mp2,mp3;

    long long maxi1 =0 , maxi2=0, maxi3=0;

    for(auto ch : s1){
        mp1[ch]++;
        maxi1 = max(maxi1,mp1[ch]);
    }
    for(auto ch : s2){
        mp2[ch]++;
         maxi2 = max(maxi2,mp2[ch]);
    }
    for(auto ch : s3){
        mp3[ch]++;
         maxi3 = max(maxi3,mp3[ch]);
    }

    long long ans1 = ((m-maxi1)<=n ? ((n -(m-maxi1))%2 == 0 ? m : m-1 ) : maxi1+n );
    long long ans2 = ((m-maxi2)<=n ? ((n -(m-maxi2))%2 == 0 ? m : m-1 ) : maxi2+n );
    long long ans3 = ((m-maxi3)<=n ? ((n -(m-maxi3))%2 == 0 ? m : m-1 ) : maxi3+n );

    cout << m << endl;
    cout << maxi1 << endl;
    cout << m-maxi1 << endl;
    cout << n << endl;

    cout<<maxi1<<" "<<maxi2<<" "<<maxi3<<endl;
    cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;

    long long best = max({ans1,ans2,ans3});
    int cnt = (ans1==best)+(ans2==best)+(ans3==best);
    if(cnt>1) cout<<"Draw";
    else if(ans1==best) cout<<"Kuro";
    else if(ans2==best) cout<<"Shiro";
    else cout<<"Katie";
    

}