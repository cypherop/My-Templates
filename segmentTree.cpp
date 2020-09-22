ll a[N],st[4*N],lazy[4*N];


void lazyp(ll node){
	lazy[2*node]+=lazy[node];
	lazy[2*node+1]+=lazy[node];
	lazy[node]=0;
}

void build(ll node,ll l,ll r){
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

ll query(ll node,ll l,ll r,ll sb,ll se){
	if(sb>r||se<l) return 0;
	if(sb>=l&&se<=r) return st[node]+lazy[node]*(se-sb+1);
	lazyp(node);
	ll mid=(sb+se)/2;
	ll left=query(2*node,l,r,sb,mid);
	ll right=query(2*node+1,l,r,mid+1,se);
	st[node]=st[2*node]+lazy[2*node]*(mid-sb+1)+st[2*node+1]+lazy[2*node+1]*(se-mid);
	return left+right;
}

void update(ll node,ll l,ll r,ll val,ll sb,ll se){
	if(sb>r||se<l) return;
	if(sb>=l&&se<=r){
		lazy[node]+=val;
		return;
	}lazyp(node);
	ll mid=(sb+se)/2;
	update(2*node,l,r,val,sb,mid);
	update(2*node+1,l,r,val,mid+1,se);
	st[node]=st[2*node]+lazy[2*node]*(mid-sb+1)+st[2*node+1]+lazy[2*node+1]*(se-mid);
}

