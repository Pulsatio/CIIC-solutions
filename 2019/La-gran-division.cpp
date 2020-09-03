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


typedef int ll; // int or long long
typedef long double ld;
typedef pair<ll,ll> ii ;
typedef vector<ll>  vi ;
typedef vector<ii> vii ;



 
const ll MAX = 66000;
const ll inf = 1e9;
const ll mod = 1e9+7;

ll p[MAX],a[MAX],cc = 1;

vi component[MAX];
ll sum[MAX];
vi adj[MAX];

ll est[MAX];

ll find(ll u){
    return (p[u]== u? u: p[u] = find(p[u]));
}
void uni(ll u,ll v){
    p[find(u)] = find(v);
}

bool dp[1000][100001] = {0};


int main(){
    fastio;
    ll n,m,u,v,T = 0;
    cin >> n >> m;
    f(i,1,n+1) cin >> a[i],T += a[i];
    f(i,0,m){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi aux; 
    f(i,1,n+1) p[i] = i;
    f(i,1,n+1){
        if( sz(adj[i]) < n/2 ) aux.push_back(i);
        else{
            for(ll x:adj[i]) est[x] = 1;
            f(j,1,n+1) if(est[j] == 0) uni(i,j);
            for(ll x:adj[i]) est[x] = 0;
        }
    }
    
    f(i,0,aux.size() - 1) uni(aux[i],aux[i+1]);
    
    f(i,1,n+1) if(find(i) == i) est[i] = cc++;

    f(i,1,n+1) component[est[find(i)]].push_back(i),sum[est[find(i)]]+=a[i];
    
    dp[0][0] = true;

    f(i,1,cc){
        f(j,0,100001){
            dp[i][j] = dp[i-1][j];
            if(j >= sum[i]) dp[i][j] |= dp[i-1][j - sum[i]];
        }
    }
    ll ans = inf,element = cc - 1,res;
    f(i,1,T/2+1) if(dp[cc-1][i])  ans = T - 2*i, res = i;
    cout << ans << endl;

    vi subset;

    while(res>0){
      //  dp[element][i] = true
        if(dp[element-1][res]) element --;
        else{
            subset.push_back(element);
            res -= sum[element];
        }

    }
    for(ll u:subset) for(ll v:component[u]) cout << v << " ";
    cout << endl;
    return 0;
}