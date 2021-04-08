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
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> ii;

typedef vector<ll> vi;
typedef vector<ii> vii;
 


const ll MAX = 5e4 +100;
const ll inf = 1e9;
const ll mod = 1e9 + 7;

ll ac[MAX][100],a[MAX];
int main(){
	fastio;
	ll n,m,q,l,r;
	cin >> n >> m >> q;	
	f(i,1,n+1) cin >> a[i];

	f(i,1,n+1) a[i]+=a[i-1],a[i]%=m;
	ac[0][0]++;
	f(i,1,n+1){
		ac[i][a[i]]++;
		f(j,0,m) ac[i][j] += ac[i-1][j]; 
	}
	while(q--){
		cin >> l >> r;
		long long ans = 0,c;
		f(i,0,m){
			if(l>1)	c = ac[r][i] - ac[l-2][i]; 
			else c = ac[r][i];
			ans += c*(c-1)  / 2;
		//	cout << c << " --"<<endl;
		} 
		cout << ans << endl;
	}

}