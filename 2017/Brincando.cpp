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
 
const ll MAX = 1e5+10;
const ll inf = 1e9;

ll dp[MAX];
long long mod = 1e6;

int main(){
	fastio;
	ll tc,n,k,v;
	cin >> k >> n;
	dp[0] = 1;

	long long sum = 1;

	f(i,1,k) dp[i] = sum,(sum+=1LL*dp[i])%=mod;
	if(n<k){
		cout<< dp[n] << endl;
		return 0;
	}
	deque<ll> q;

	f(i,0,k) q.push_back(dp[i]);
	ll ans = 0;
	f(i,k,n){
		q.push_back(sum);
		(sum += mod+1LL*q.back() - 1LL*q.front())%=mod;
		q.pop_front();
	}

	cout << sum << endl;
	
}