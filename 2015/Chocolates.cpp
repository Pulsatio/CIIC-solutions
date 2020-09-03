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
 


const ll MAX = 5e5 +100;
const ll inf = 1e9;
const ll mod = 1e9 + 7;

ll a[MAX],n;

bool go(ll x){
	ll ac = 0;
	f(i,0,n){
		ac += a[i];
		if(ac < x) return false;
		ac -= x;
	}
	return true;
}

int main(){
	fastio;
	cin >> n;	
	f(i,0,n) cin >> a[i];
	ll ini = 0,fin = inf;
	while(ini < fin){
		ll mid = (ini + fin +1)/2;
		if(go(mid)) ini = mid;
		else fin = mid -1;
	}
	cout << ini << endl;
}