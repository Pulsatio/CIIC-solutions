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
 
const ll MAX = 3e6 + 1;


ll lug[MAX],tree[MAX],n;

void add(ll x,ll v){
  while( x <= n) tree[x] += v, x += x & (-x);
}

void sum(ll x,ll *res){
  while(x >  0) (*res) += tree[x], x -= x& (-x);
} 

int main(){
  ll x,res = 0;
  scanf("%d",&n);

  n = n/2;
 
  f(i,1,n+1)  scanf("%d",&x), tree[x] = i;
  f(i,1,n+1)  scanf("%d",&x), lug[ tree[x] ] = i;
  f(i,0,n+1) tree[i] = 0;
 
  long long ans = 0;
 
  af(i,n,1){
    res = 0;
    sum(lug[i],&res);
    ans += res;
    add(lug[i],1);
  }

  printf("%lld\n",ans);
}