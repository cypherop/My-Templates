vll LCP(string s, vll &p) {
	ll n = s.length(), i;
	ll tmp[n];
	vll lcp(n-1);
	rep(i,0,n) tmp[p[i]] = i;
	ll now = 0, k;
	rep(i,0,n) {
		now -= (bool)now;
		k = tmp[i];
		if(!k) {
			now = 0;
			continue;
		} 
		while(p[k] + now < n && p[k-1] + now < n && s[p[k] + now] == s[p[k-1] + now]) now++;
		lcp[k - 1] = now;
	}
	return lcp;
}

vll suffixArray(string s) {
	ll n = s.size(), classes = 0, i, _;
	vll p(n), c(n);
	ll cnt[max(n + 5,(ll)260)] = {0};
	for(auto &i : s) cnt[i]++;
	rep(i,1,260) cnt[i] += cnt[i-1];
	rep(i,0,n) p[--cnt[s[i]]] = i;
	c[p[0]] = classes;
	rep(i,1,n) {
		if(s[p[i]] != s[p[i-1]]) classes++;
		c[p[i]] = classes;
	}
	vll ptmp(n), ctmp(n);
	for(_ = 0; (1ll << _) < n; ++_) {
		swap(c, ctmp);
		rep(i,0,n) ptmp[i] = (p[i] + n - (1ll << _)) % n;
		rep(i,0,classes + 1) cnt[i] = 0;
		for(auto &i : ctmp) cnt[i]++; 
		rep(i,1,classes + 1) cnt[i] += cnt[i-1];
		classes = 0;
		repi(i,n-1,-1) p[--cnt[ctmp[ptmp[i]]]] = ptmp[i];
		c[p[0]] = 0;
		rep(i,1,n) {
			if(ctmp[p[i]] != ctmp[p[i-1]] || ctmp[(p[i] + (1ll << _)) % n] != ctmp[(p[i-1] + (1ll << _)) % n]) classes++;
			c[p[i]] = classes;
		}
	}
	return p;
}