#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const long long N = 1534567;
const long long mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    int maxCoins(vector<int>& a) {
        int n = a.size();
        a.insert(a.begin() , 1);
        a.insert(a.end() , 1);
        
        int dp[n + 2][n + 2];
        
        rep(i , 0 , n + 1) {
            rep(j , 0 , n + 1) dp[i][j] = 0;
        }

        rep(l , 1 , n) {
            rep(i , 1 , n - l + 1) {
                int j = i + l - 1;

                int best = 0;

                rep(k , i , j) {
                    int temp = dp[i][k - 1] + dp[k + 1][j];
               //     cout << i - 1 << " " << k << " " << j - 1 << endl;
                    temp += a[i - 1] * a[k] * a[j + 1];
                    best = max(best , temp);
                }

                dp[i][j] = best;
            }
        }

        return dp[1][n];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll MOD= 1000000007;
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define pb push_back
#define mpr make_pair
void recur(ll i,ll x,vector <ll> v,ll k)
{
    if(i==0)
    {
        //cout<<x<<endl;
        ll x2=x^1;
        ll numOfx1= (upper_bound(v.begin(),v.end(),x)-v.begin()) - (lower_bound(v.begin(),v.end(),x)-v.begin());
        ll numOfx2= (upper_bound(v.begin(),v.end(),x2)-v.begin()) - (lower_bound(v.begin(),v.end(),x2)-v.begin());
        if(x>x2)
        {
            k-=numOfx1;
            if(k<=0)
                cout<<x<<endl;
            else
                cout<<x2<<endl;
        }
        else
        {
            k-=numOfx2;
            if(k<=0)
                cout<<x2<<endl;
            else
                cout<<x<<endl;
        }
        return;
    }
    ll x2=0;
    for(int j=i;j<=30;j++)
        x2|=((x>>j)&1)<<j;
    x2^=(1<<i);
    ll lo=0,hi=(1<<i)-1;
    lo+=x2;hi+=x2;
    ll ind1=lower_bound(v.begin(),v.end(),lo)-v.begin();
    ll ind2=upper_bound(v.begin(),v.end(),hi)-v.begin();
    //cout<<x<<" "<<x2<<" "<<lo<<" "<<hi<<" "<<ind1<<" "<<ind2<<endl;
    ll numOfElements= ind2-ind1;
    if(numOfElements>=k)
    {
        recur(i-1,x^(1<<i),v,k);
    }
    else
    {
        recur(i-1,x,v,k-numOfElements);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    ll n;
    cin>>n;
    vector <ll> v;
    ll x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v.pb(x);
    }
    cin>>x;
    ll k;
    cin>>k;
    sort(v.begin(),v.end());
    recur(30,x,v,k);
}