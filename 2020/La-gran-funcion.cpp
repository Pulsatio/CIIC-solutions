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
 
typedef int ll; // int or long long
typedef long double ld;
typedef pair<ll,ll> ii ;
typedef vector<ll>  vi ;
typedef vector<ii> vii ;
  
const ll MAX = 3e3 + 100;
const ll mod = 1e9;
const ll inf = 1e9;

ll s[40][60],c[60][60];



ll mul(ll a,ll b){
	return ( (1LL*a)*(1LL*b))%mod;
}
ll add(ll a,ll b){
	return (a+b)%mod;
}

ll calc(ll n,ll k){
	if(k == 0) return n;
	if(n == 1) return 1;
	ll ans = 0, ant = 0,aux = 0;
	while( (n&(1<<ant)) == 0 ) ant++;
	ans = s[ant][k];
	aux = 1<<ant;
	f(i,ant+1,30){
		if(n&(1<<i)){
			ll pot = 1;
			f(j,0,k+1)
				ans = add(ans,mul(c[k][j], mul(pot, s[i][k-j]))), pot = mul(pot,aux);
			aux += 1<<i;
		}
	}
	return ans;
}



int main(){
    fastio;
  	ll n,k;
  	cin >> n >> k;
  	f(i,0,k+1){
  		f(j,0,i+1){
  			if(i == j || j == 0) c[i][j] = 1;
  			else c[i][j] = add(c[i-1][j],c[i-1][j-1]);
  		}
  	}
  	f(i,0,31){
  		f(j,0,k+1) {
  			if(i == 0) s[i][j] = 1;
  			else if(j == 0) s[i][j] = (1<<i)%mod;
  			else{
  				s[i][j] = s[i-1][j];
  				ll aux = 1;
  				f(it,0,k+1) s[i][j] = add(s[i][j],mul( c[j][it] ,mul( s[i-1][j-it] ,aux) )),aux = mul(aux,(1<<(i-1))%mod);
  			}
    	}
    }
	ll x = sqrt(n),ans = 0;
    f(i,1,x){
    	ans = add(ans,mul(i,add(calc(n/i,k),mod-calc(n/(i+1),k) ) ));
    }
    f(i,1,n/x+1) {
    	ll aux = 1;
    	f(j,0,k) aux = mul(aux,i);
    	ans = add(ans,mul(aux,n/i));
    }
    cout << ans << endl;
    return 0;
}
 