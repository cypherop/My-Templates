long long a[N],st[4*N],lazy[4*N],sb[4*N],se[4*N];


void lazyp(long long node){
	lazy[2*node]+=lazy[node];
	lazy[2*node+1]+=lazy[node];
	lazy[node]=0;
}

void build(long long node,long long l,long long r){
	sb[node]=l;
	se[node]=r;
	if(l==r){
		st[node]=a[l];
		return;	
	}
	long long mid=(l+r)/2;
	build(2*node,l,mid);
	build(2*node+1,mid+1,r);

	st[node]=st[2*node]+st[2*node+1];
	return;
}

long long query(long long node,long long l,long long r){
	if(sb[node]>r||se[node]<l)	
		return 0;
	if(sb[node]>=l&&se[node]<=r)
		return st[node]+lazy[node]*(se[node]-sb[node]+1);
	lazyp(node);
	long long left=query(2*node,l,r);
	long long right=query(2*node+1,l,r);
	st[node]=st[2*node]+lazy[2*node]*(se[2*node]-sb[2*node]+1)+st[2*node+1]+lazy[2*node+1]*(se[2*node+1]-sb[2*node+1]+1);
	return left+right;
}

void update(long long node,long long l,long long r,long long val){
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

