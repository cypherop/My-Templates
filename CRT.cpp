void exgcd(ll a, ll b, ll &x, ll &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return;
	} 
	exgcd(b,a%b,x,y);
	ll x1 = x, y1 = y;
	x = y1;
	y = x1 - a / b * y1;
}

pll crt(vll mod,vll rem) {
	ll n = mod.size();
	ll m = 1, r = 0, i;
	rep(i,0,n) {
		rem[i] %= mod[i];
		rem[i] += mod[i];
		rem[i] %= mod[i];
		if(mod[i] > m) {
			swap(rem[i], r);
			swap(mod[i], m);
		}
		if(m % mod[i] == 0) {
			if(r % mod[i] != rem[i]) {
				m = -1;
				r = -1;
				break;
			}
			continue;
		}
		ll g = __gcd(mod[i], m);
		if((rem[i] - r) % g) {
			m = -1;
			r = -1;
			break;
		}
		ll lcm = (mod[i] / g) * m;
		ll x, y;
		exgcd(m, mod[i], x, y);
		y = mod[i] / g;
		x %= y;
		m %= lcm;
		r %= lcm;
		r = (r + ((((x * (((rem[i] - r) / g) % y)) % y) * m) % lcm)) % lcm;
		m = lcm;
		if(r < 0) r += m;
	}
	return {m, r};
}