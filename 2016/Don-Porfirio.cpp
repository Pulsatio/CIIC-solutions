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
#define inter ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

// policy-based
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;	


using namespace std;


typedef long long ll; // int or long long
typedef long double ld;
typedef pair<ll,ll> ii ;
typedef vector<ll>  vi ;
typedef vector<ii> vii ;

/*
typedef tree<
ll,
null_type,
less<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/
 
const ll MAX = 2e5;
const ll inf = 1e12;
const ll mod = 1e9+7;


ll ans = 0;
ll p[MAX],t[MAX];

ll find(ll u){
	if(p[u] == u) return u;
	p[u] = find(p[u]);
	return p[u];
}

void uni(ll u,ll v){
	ll x = find(u),y = find(v);
	if(x == y) return;
	p[x] = y;
	// t[] es el tamaño de la componente conexa 
	t[y] += t[x];
}

struct Edge{
	ll u,v,w;
	bool operator<(Edge o){
		return w < o.w;
	}
};

Edge edges[MAX];
int main(){
	fastio;
	ll n,u,v,w;
	cin >> n;
	
	// inicializacion del union-find
	f(i,1,n+1) p[i] = i,t[i] = 1;

	f(i,0,n-1){
		cin >> u >> v >> w;
		edges[i] = {u,v,w};
	}
	sort(edges,edges+n-1);
	f(i,0,n-1){
		u = edges[i].u,v = edges[i].v;
		(ans += ((t[find(u)]*t[find(v)] )%mod )*edges[i].w)%=mod; 
		uni(u,v);
	}
	cout << ans << endl;
}