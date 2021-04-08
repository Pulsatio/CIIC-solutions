#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma")
 
#define f(i,a,b) for(ll  i = a; i < (ll) b ; i++ ) 
#define af(i,a,b) for(ll i = a; i >= (ll) b ; i--)
#define rep(i,a,b,k) for(ll  i = a; i < (ll) b ; i+= k )
#define arep(i,a,b,k) for(ll i = a; i >= (ll) b ; i-= k)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define sz(a) (ll) a.size()
#define sor(a) sort( a.begin(), a.end() )
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define inter   ios::sync_with_stdio(false);cin.tie(0)
 
// policy-based
 
 
 
 
using namespace std;
 
typedef long long ll; // int or long long
typedef long double ld;
typedef pair<ll,ll> ii ;
typedef vector<ll>  vi ;
typedef vector<ii> vii ;
  
const ll MAX = 3e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;



struct Ele{
	ll p,r,t;
	bool operator<(Ele x){
		return (r*x.t > t*x.r);
	}
};

Ele a[MAX];


ll dp[1010][2010];
int main(){
    fastio;
    ll n,time,ans = 0;
    cin >> n >> time;
    f(i,1,n+1) cin >> a[i].p >> a[i].r >> a[i].t;
    sort(a+1,a+n+1);
    f(i,1,n+1){
    	f(j,1,time+1){
    		dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    		if(j >= a[i].t)
    			dp[i][j] = max(dp[i][j],dp[i-1][j-a[i].t] + max(0LL,a[i].p - j*a[i].r) );
    	}
    }
    cout << dp[n][time] << endl;
    return 0;
}
