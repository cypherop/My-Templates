ll basis[30];
ll m;

void func(ll n){
	ll i;
	repi(i,29,-1){
		if((1<<i)&n){
			if(basis[i])n^=basis[i];
			else{
				m++;
				ll j;
				repi(j,i-1,-1){
					if(basis[j]&&(n&(1<<j))){
						n^=basis[j];
					}
				}
				rep(j,i+1,30){
					if((1<<i)&basis[j]){
						basis[j]^=n;
					}
				}
				basis[i]=n;
				return;
			}
		}
	}
}


//basis[i] = mask with last set bit i and no other mask have ith bit set other than this.
