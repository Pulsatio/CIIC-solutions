#include <bits/stdc++.h>

#define f(i,a,b) for( ll  i = a; i < (ll) b ; i++ ) 
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



using namespace std;


typedef long long ll; // int or long long
typedef long double ld;
typedef pair<ll,ll> ii ;
typedef vector<ll>  vi ;
typedef vector<ii> vii ;



 
const ll MAX = 1e3+10;
const ll inf = 2e18;
const ll mod = 1e9+7;



bool uni[MAX][MAX],cc[MAX][MAX];
int num1[MAX],num2[MAX],vis[MAX],cant1,cant2;
set<int> adj[MAX];
void dfs1(int u){
	vis[u] = true;
	for(int i=0;i<cant1;i++) uni[u][num1[i]] = true;
	for(int v:adj[u]) if(!vis[v]) dfs1(v);
}

void dfs2(int u){
	vis[u] = true;
	for(int i=0;i<cant2;i++) uni[u][num2[i]] = true;
	for(int v:adj[u]) if(!vis[v]) dfs2(v);
}

int main(){
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++) cc[i][i] = uni[i][i] = true;
	for(int i = 0;i<m;i++){
		scanf("%d%d",&u,&v);
		if(cc[u][v]){
			adj[u].erase(v);
			adj[v].erase(u);
			cc[u][v] = false;
			continue;
		}
	
		cant1 = 0;
		for(int j=1;j<=n;j++) if ( (uni[v][j] && !uni[u][j]) ) num1[cant1++] = j;
		cant2 = 0;
		for(int j=1;j<=n;j++) if ( (uni[u][j] && !uni[v][j]) ) num2[cant2++] = j;
		if(cant1){	
			for(int j=1;j<=n;j++) vis[j] = false;
			dfs1(u);
		}
		if(cant2){
			for(int j=1;j<=n;j++) vis[j] = false;
			dfs2(v);
		}

		adj[u].insert(v);
		adj[v].insert(u);
		cc[u][v] = true;
	}
	for(int i=1;i<=n;i++){
		int ans = 0;
		for(int j=1;j<=n;j++) if(uni[i][j]) ans++;
		printf("%d\n",ans);
	
	}
}