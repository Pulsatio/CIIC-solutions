#include <bits/stdc++.h>

#define f(i,a,b) for( ll i = a; i < b ; i++ ) 
#define af(i,a,b) for( ll i = a; i >= b ; i--)
#define rep(i,a,b,k) for(ll i = a; i < b ; i+= k )
#define arep(i,a,b,k) for( ll i = a; i >= b ; i-= k)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(a) (ll) a.size()
#define all(a) a.begin(), a.end()
#define sor(a) sort( a.begin(), a.end() )
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ller ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
 
const ll MAX = 1e6 + 3;
const ll inf = 1e18;
const ll mod = 1e6 + 3;

map<ll,ll> ind;
ll a[40],ans[1LL<<22],b[40],dp[1LL << 22],aux[1LL << 22];
ll sum[MAX];

int main(){
    fastio;
    f(i,1,MAX){
        f(j,2,(MAX+i-1)/i ) sum[i*j] += i*i; 
    }
    ll tc,x,n,q;
    tc = 1;
    cin >> n >> q;
    f(i,0,n) cin >> a[i],ind[a[i]] = i;
    
    ll to = (1LL<< n) -1;
    
    f(mask,1,(1LL<<n)){
        ll prod = 1;
        f(i,0,n) 
            if(mask&(1LL<<i)) (prod *= a[i])%=mod;
        dp[to^mask] = sum[prod];
    }


    f(i,0,n){
        f(mask,0,(1LL<< n)) 
            if(mask & (1LL<<i)) dp[mask] += dp[mask^(1LL<<i)]; 
    }
    
    while(q--){
        cin >> x;
        ll submask = 0;
        f(i,0,x) cin >> b[i], submask += (1LL<<ind[b[i]]);
        cout << dp[to^submask]<<" ";
    }

    return 0;
}