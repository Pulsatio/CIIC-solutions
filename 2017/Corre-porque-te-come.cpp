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
 
const ll MAX = 4e5 + 100;
const ll inf = 2e9;
ll n,m;

ll p[MAX];


ll find(ll u){
  return (p[u] == u?u:p[u] = find(p[u]));
}

void uni(ll u,ll v){
  p[find(u)] = find(v);
}

struct Edge{
  ll u,v,w;
  bool operator<(Edge o){
    return w > o.w;
  }
};

Edge edges[MAX];

vii adj[MAX];

ll anc[MAX][20],mini[MAX][20],tin[MAX],tout[MAX],cont = 0,c[MAX];

void dfs(ll u,ll f,ll up){
  tin[u] = ++cont;
  anc[u][0] = f;
  mini[u][0] = up;
  f(i,1,20) anc[u][i] = anc[ anc[u][i-1] ][i-1];
  f(i,1,20) mini[u][i] = min(mini[u][i-1],mini[ anc[u][i-1] ][u-1] );

  for(ii it:adj[u]){
    ll v = it.ff;
    if(v == f) continue;
    c[v] = c[u] + 1;
    dfs(v,u,it.ss);
  }
  tout[u] = ++cont; 
}

bool is_ancester(ll u,ll v){
  return (tin[u] <= tin[v]) && (tout[u] >= tout[v]);
}

ll dist(ll u,ll v){
  ll d = c[v] - c[u],ans = inf;
  f(i,0,20){
    if(d&(1<<i)){
      ans = min(ans,mini[v][i]);
      v = anc[v][i];
    }
  }
  return ans;
}

ll lca(ll u,ll v){
  if(is_ancester(u,v)) return u;
  if(is_ancester(v,u)) return v;
  af(i,19,0){
    if(!is_ancester(anc[u][i],v)){
      u = anc[u][i];
    }
  }
  return anc[u][0];
}

int main(){
  fastio;
  cin >> n >> m;
  ll u,v,q;
  f(i,1,n+1) p[i] = i;
  f(i,0,m) cin >> edges[i].u >> edges[i].v >> edges[i].w;
  sort(edges,edges + m);
  f(i,0,m){
    u = edges[i].u,v = edges[i].v;
    if(find(u)!=find(v)){
      adj[u].push_back({v,edges[i].w});
      adj[v].push_back({u,edges[i].w});
      uni(u,v);
    }
  }
  dfs(1,1,inf);

  cin >> q;
  while(q--){
    cin >> u >> v;
    ll g = lca(u,v);
  
    cout << min(dist(g,u),dist(g,v))  - 1<< endl;
  } 
  
}