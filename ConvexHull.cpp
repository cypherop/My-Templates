vector<pll> lines;
vector<ld> points;

ld intersect(pll a,pll b){
	if(a.F==b.F)return inf;
	return (a.S-b.S)/(ld)(b.F-a.F);
}

void add(ll m,ll c){
	if(!lines.size()){
		lines.pb({m,c});
		points.pb(-inf);
		return;
	}
	ld k;
	while(lines.size()>1){
		k=intersect({m,c},lines.back());
		if(k<=points.back()){
			lines.pop_back();
			points.pop_back();
		}else break;
	}
	points.pb(intersect({m,c},lines.back()));
	lines.pb({m,c});
}

ll Y(ll x){
	ll k=upper_bound(points.begin(),points.end(),x)-points.begin();
	--k;
	return lines[k].F*x+lines[k].S;
}
