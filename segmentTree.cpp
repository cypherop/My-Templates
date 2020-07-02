ll a[N],st[4*N],lazy[4*N],sb[4*N],se[4*N];


void lazyp(ll node){
	lazy[2*node]+=lazy[node];
	lazy[2*node+1]+=lazy[node];
	lazy[node]=0;
}

void build(ll node,ll l,ll r){
	sb[node]=l;
	se[node]=r;
	if(l==r){
		st[node]=a[l];
		return;	
	}
	ll mid=(l+r)/2;
	build(2*node,l,mid);
	build(2*node+1,mid+1,r);

	st[node]=st[2*node]+st[2*node+1];
	return;
}

ll query(ll node,ll l,ll r){
	if(sb[node]>r||se[node]<l)	
		return 0;
	if(sb[node]>=l&&se[node]<=r)
		return st[node]+lazy[node]*(se[node]-sb[node]+1);
	lazyp(node);
	ll left=query(2*node,l,r);
	ll right=query(2*node+1,l,r);
	st[node]=st[2*node]+lazy[2*node]*(se[2*node]-sb[2*node]+1)+st[2*node+1]+lazy[2*node+1]*(se[2*node+1]-sb[2*node+1]+1);
	return left+right;
}

void update(ll node,ll l,ll r,ll val){
	if(sb[node]>r||se[node]<l)	
		return;
	if(sb[node]>=l&&se[node]<=r){
		lazy[node]+=val;
		return;
	}lazyp(node);
	update(2*node,l,r,val);
	update(2*node+1,l,r,val);

	st[node]=st[2*node]+lazy[2*node]*(se[2*node]-sb[2*node]+1)+st[2*node+1]+lazy[2*node+1]*(se[2*node+1]-sb[2*node+1]+1);
}

