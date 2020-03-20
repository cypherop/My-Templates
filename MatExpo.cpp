
ll T[3][3]={{1,1,1},{1,0,0},{0,1,0}};
ll ans[3][3]={{1,0,0},{0,1,0},{0,0,1}};

void mulans(){
	ll s=0;
	ll i,j,k;
	ll t1[3][3];
	rep(i,0,3){
		rep(j,0,3){
			s=0;
			rep(k,0,3){
				s+=((ans[i][k]*T[k][j])%(M-1));
				s%=(M-1);
			}
			t1[i][j]=s;
		}
	}
	rep(i,0,3)rep(j,0,3)ans[i][j]=t1[i][j];
}

void mulT(){
	ll s=0;
	ll i,j,k;
	ll t1[3][3];
	rep(i,0,3){
		rep(j,0,3){
			s=0;
			rep(k,0,3){
				s+=(T[i][k]*T[k][j])%(M-1);
				s%=(M-1);
			}
			t1[i][j]=s;
		}
	}
	rep(i,0,3)rep(j,0,3)T[i][j]=t1[i][j];
}

void matPow(ll n){
	while(n){
		if(n%2){
			mulans();
		}
		mulT();
		n>>=1;
	}
}

