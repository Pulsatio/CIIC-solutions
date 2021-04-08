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
  
const ll MAX = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;


ll d[MAX],t[MAX],h[MAX],c[MAX],l;

int n,m;
vector< pair<int,int> > adj[MAX];

ll dij(){
	for(int i = 0; i < n; i++) d[i] = -1;
	d[n-1] = l;
	priority_queue<pair<ll,int> > q;
	q.push({l,n-1});
	while(!q.empty()){
		pair<ll,int> aux = q.top();
		ll dis = aux.ff;
		int u = aux.ss;
		q.pop();
		if(dis != d[u]) continue;
		for(pair<int,int> it:adj[u]){
			int v = it.ff; 
			ll y = it.ss;

			ll time = dis - t[y];

			time += ((time%c[y] < h[y]%c[y])? h[y]%c[y] - time%c[y] - c[y] : h[y]%c[y] - time%c[y] );
			if(time < h[y] ) continue;
			if(time > d[v]){
				d[v] = time;
				q.push({d[v],v});
			}
		}
	}

	return d[0];
}

int main(){
    int u,v;
   	scanf("%d %d %lld",&n,&m,&l);
   	for(int i = 0; i < m; i++){
   		scanf("%d %d %lld %lld %lld",&u,&v,&t[i],&h[i],&c[i]);
   		adj[v].push_back({u,i});
   	}
   	ll ans = dij();
   	printf("%lld\n",ans);
    return 0;
}