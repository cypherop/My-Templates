#include <bits/stdc++.h>
#include <unistd.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

#define rep(i,j,n) for(i=j;i<n;i++)
#define repi(i,j,n) for(i=j;i>n;i--)
#define pie 3.141592653589793238
#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define pb push_back
#define F first
#define S second
#define endl '\n'
#define UQ(x) (x).resize(distance((x).begin(),unique(x.begin(),x.end())))

using namespace std;
using namespace __gnu_pbds; 

template<typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rnd64(chrono::high_resolution_clock::now().time_since_epoch().count());

ll power(ll a,ll m,ll mod){
	ll ans = 1;
	while(m){
		if(m%2) ans *= a, ans %= (mod);
		a = (a*a) % mod;
		m >>= 1;
	}
	return ans;
}

struct custom_hash {  // Credits: https://codeforces.com/blog/entry/62393
 	static uint64_t splitmix64(uint64_t x) {
    	// http://xorshift.di.unimi.it/splitmix64.c
    	x += 0x9e3779b97f4a7c15;
    	x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    	x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    	return x ^ (x >> 31);
  	}
 
  	size_t operator()(uint64_t x) const {
    	static const uint64_t FIXED_RANDOM =
        	chrono::steady_clock::now().time_since_epoch().count();
    	return splitmix64(x + FIXED_RANDOM);
  	}
  	size_t operator()(pair<int64_t, int64_t> Y) const {
    	static const uint64_t FIXED_RANDOM =
        	chrono::steady_clock::now().time_since_epoch().count();
    	return splitmix64(Y.first * 31 + Y.second + FIXED_RANDOM);
  	}
};

const long long inf = 1e18;
const long long M = 1000000007;

void solve(){
	ll i,j,_;
}

int main()
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	ll T=1;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}


