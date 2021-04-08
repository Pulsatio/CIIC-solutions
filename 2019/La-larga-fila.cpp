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
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;

typedef vector<ll> vi;
typedef vector<ii> vii;
 


const ll MAX = 5e5 +100;
const ll inf = 1e16;
const ll mod = 1e9 + 7;


map<string,ll> ind;

struct Node{
	ll hero,i;
	struct Node *prev;
	struct Node *next;

};


Node arr[MAX];
Node* direc[MAX];


ll val[110][110];
int main(){
	fastio;
	ll t,x,l,r,n,k,q;
	string s,a,b;
	cin >> n >> k >> q;
	f(i,1,n+1){
		cin >> s >> x;
		ind[s] = i;
		arr[i].hero = x, arr[i].i  = i;
		
		arr[i].prev =  &arr[i-1];

		arr[i].next = &arr[i+1];

		direc[i] = &arr[i];
	}

	arr[0].prev = NULL;
	arr[0].next = &arr[1];

	arr[n+1].prev = &arr[n];
	arr[n+1].next = NULL;

	f(i,0,k) f(j,0,k) cin >> val[i+1][j+1];
	
	while(q--){
		cin >> t;
		
		if(t == 1){
			cin >> b >> a;
			Node *left  = direc[ind[a]];
			Node *right = direc[ind[b]];

			((*right).prev) -> next = right -> next;
			((*right).next)->prev = right ->prev;

			(*right).next = left;
			(*right).prev = (*left).prev;

			(*(*left).prev).next = right;
			(*left).prev = right;
		}
		else if (t == 2){
			cin >> a >> x;
			(*direc[ ind[a] ]).hero =  x;
		}
		else{
			cin >> a;
			ll ans = 0,h = (*direc[ind[a]]).hero;

			Node *left = (*direc[ ind[a] ]).prev;
			f(i,0,34){
				if(left == &arr[0]) break;
				ans += val[(*left).hero ][h] / (1LL<<i); 
				left = (*left).prev; 
			}

			Node *right = (*direc[ ind[a] ]).next;
			
			f(i,0,34){
				if(right == &arr[n+1]) break;
				ans += val[(*right).hero ][h] / (1LL<<i); 
				right = (*right).next; 
			}
			cout << ans << endl;
		}
	}

	return 0;
}