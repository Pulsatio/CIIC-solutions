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
#define inter   ios::sync_with_stdio(false);cin.tie(0)

// policy-based



using namespace std;


typedef long long ll; // int or long long
typedef long double ld;
typedef pair<ll,ll> ii ;
typedef vector<ll>  vi ;
typedef vector<ii> vii ;



 
const ll MAX = 2e5+10;
const ll inf = 1e9;
const ll mod = 1e9+7;


ll value[MAX],weapon[MAX];
vii Querie[MAX];
vi adj[MAX];
ll cant[MAX];
ll ans[MAX];
// segment tree
struct Node{
  ll sum,c;
  Node operator+(Node o){
    return {sum+o.sum,c+o.c};
  }
};

Node tree[MAX*10];
const ll N = 1e6+1;

void update(ll v,Node x){
  v+=N; tree[v] = tree[v] +  x;
  while(v) v>>=1,tree[v] = tree[v<<1] + tree[v<<1|1];
}

Node query(ll l,ll r){
  Node ans = {0,0};
  for(l+=N,r+=N;l<r;l>>=1,r>>=1){
    if(l&1) ans = ans + tree[l++];
    if(r&1) ans = ans + tree[--r];
  }
  return ans;
}

// end of the segment tree

void dfs(ll u,ll f){
  if( cant[weapon[u]] == 0){
 
    update(value[weapon[u]],{value[weapon[u]],1});
  }
  cant[weapon[u]]++;

  for(ii it:Querie[u]){
   
    Node aux = query(it.ff,N);
 
    ans[it.ss] = aux.sum - aux.c * it.ff;
  }

  for(ll v:adj[u]){
    if(v == f) continue;
    dfs(v,u);
  }

  if( cant[weapon[u]] == 1){
    update(value[weapon[u]],{-value[weapon[u]],-1});
  }
  cant[weapon[u]]--;

}

int main(){
  fastio;
  ll n,m,q,u,v,t,k;
  cin >> n >> m >> q;
  f(i,1,m+1) cin >> value[i];
  f(i,2,n+1){
    cin >> u;
    adj[u].push_back(i);
    adj[i].push_back(u);
    cin >> weapon[i];
  } 
  f(i,0,q){
    cin >> t >> k;
    Querie[t].push_back({k,i});
  }
  f(i,0,N) tree[i+N] = {0,0}; 
  dfs(1,0);
  
  f(i,0,q) cout << ans[i] << endl;
  return 0;
}