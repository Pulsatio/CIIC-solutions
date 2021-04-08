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


typedef int ll; // int or long long
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
 
const ll MAX = 5e5+10;
const ll inf = 1e9;
const ll mod = 1e9+7;



vi adj[MAX];

ll n,p,k;

bool block[MAX];
ll up[MAX]; // father in centroid decomposition
ll szt[MAX]; // size of subtree


ll dfs_size(ll u, ll f){
	szt[u] = 1;
	for(ll v:adj[u]){
		if(v != f && !block[v])
			szt[u] += dfs_size(v,u);
	}
	return szt[u];
}

ll cont[MAX],c[MAX];
long long ans = 0;

void dfs_dist(ll u,ll f,ll dis){
	dis+=c[u];
	cont[dis]++;
	for(ll v:adj[u]){
		if(!block[v] && v != f)
			dfs_dist(v,u,dis);
	}
}

long long calc(ll sz){
	long long total = 0;
	f(i,0,min(k,sz) +1) if(k-i <= min(k,sz)) total += (1LL*cont[i])*(1LL*cont[k - i]);
	return total;
}

void decompose(ll u = 1, ll f = -1, ll sz = -1){ 
	// O(nlogn)
	if(sz<0) sz = dfs_size(u,-1);
	
	for(auto v:adj[u]){
		if(!block[v] && szt[v]*2 > sz){
		 	szt[u] = 0;
		 	decompose(v,f,sz);
		 	return;
		}
	}

	block[u] = true;
	up[u] = f;
	// u -> centroid
	dfs_size(u,-1);

	dfs_dist(u,-1,-c[u]);
	k-=c[u];
	ans += calc(szt[u]);

	f(i,0,szt[u]+1) cont[i] = 0;
	for(auto v:adj[u]){
		if(!block[v]){
			dfs_dist(v,-1,0);
			ans -= calc(szt[v]);
			f(i,0,szt[v]+1) cont[i] = 0;
		}
	}
	k+=c[u];
 
	for(auto v:adj[u])
		if(!block[v])  decompose(v,u);
	
}
int main(){
	fastio;
	ll e,u,v;
	cin >> n >> p >> k;
	k--;
	f(i,1,n+1) {
		cin >> e;
		c[i] = (e<p?1:0);
	}
	f(i,1,n){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	decompose();
	if(k==0){
		ll aux = 0;
		f(i,1,n+1) aux += 1 - c[i];
		ans = aux + (ans-aux)/2;
	} 
	else if(k==1){
		ll aux = 0;
		f(i,1,n+1) aux += c[i];
		ans = aux + (ans-aux)/2;
	}
	else ans/=2;

	cout << ans << endl;
}
