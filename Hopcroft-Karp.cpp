//complexity O(E*sqrt(V))
 
struct hopcroft_karp {
 
    const ll now_inf = 1e9 + 7;
    ll n, m;
    vll ml, mr, dist;
    vector<vll> adj;
    list<ll> queue;
 
    hopcroft_karp(ll n, ll m) {
        this->m = m;
        this->n = n;
        dist.resize(n + 1);
        ml.resize(n + 1, 0);
        mr.resize(m + 1, 0);
        adj.resize(n + 1);
    }
 
    void addEdge(ll u, ll v) {
        adj[u].pb(v);
    }
 
    bool bfs() {
        ll i;
        queue.clear();
        dist[0] = now_inf;
        rep(i,1,n + 1) {
            if(!ml[i]) queue.pb(i), dist[i] = 0;
            else dist[i] = now_inf;
        }
        while(!queue.empty()) {
            ll z = queue.front();
            queue.pop_front();
            for(auto &i : adj[z]) if(dist[mr[i]] == now_inf) queue.pb(mr[i]), dist[mr[i]] = dist[z] + 1;
        }
        return dist[0] != now_inf;
    }
 
    bool dfs(ll u) {
        if(!u) return 1;
        for(auto &i : adj[u]) {
            if(dist[mr[i]] == dist[u] + 1 && dfs(mr[i])) {
                ml[u] = i, mr[i] = u;
                return 1;
            }
        }
        dist[u] = now_inf;
        return 0;
    }
 
    ll match() {
        ll ans = 0, i;
        while(bfs()) rep(i,1,n + 1) if(!ml[i] && dfs(i)) ++ans;
        return ans;
    }
};