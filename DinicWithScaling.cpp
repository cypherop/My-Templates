struct DinicEdge{
    ll u, v, f, c;

    DinicEdge(ll u, ll v, ll f, ll c) {
        this->u = u;
        this->v = v;
        this->f = f;
        this->c = c;
    }
};

struct DinicWithScaling {

    const ll now_inf = 1e9 + 7;

    ll n, m, s, i, t, limit;
    vector<DinicEdge> edges;
    vector<vll> adj;
    vll ptr, level;
    list<ll> queue;
    

    DinicWithScaling(ll n, ll s, ll t) {
        this->n = n;
        this->s = s;
        this->t = t;
        adj.resize(n + 1);
        ptr.resize(n + 1);
        level.resize(n + 1);
    }

    void addEdge(ll u, ll v, ll c) {
        adj[u].push_back(edges.size());
        edges.push_back(DinicEdge(u, v, 0, c));
        adj[v].push_back(edges.size());
        edges.push_back(DinicEdge(v, u, c, c));
    }

    bool bfs() {
        rep(i,s,t + 1) level[i] = now_inf;
        level[s] = 0;
        queue.clear();
        queue.push_back(s);
        while(!queue.empty()) {
            ll z = queue.front();
            queue.pop_front();
            for(auto i : adj[z]) {
                if(level[edges[i].v] != now_inf || edges[i].c - edges[i].f < limit) continue;
                level[edges[i].v] = level[z] + 1;
                queue.push_back(edges[i].v); 
            }
        }
        return level[t] != now_inf;
    }

    bool dfs(ll v, ll flow) {
        if(!flow) return 0;
        if(v == t) return 1;
        rep(ptr[v], ptr[v], adj[v].size()) {
            if(level[edges[adj[v][ptr[v]]].v] != level[v] + 1 || edges[adj[v][ptr[v]]].c - edges[adj[v][ptr[v]]].f < flow) continue;
            if(dfs(edges[adj[v][ptr[v]]].v, flow)) {
                edges[adj[v][ptr[v]]].f += flow;
                edges[adj[v][ptr[v]] ^ 1].f -= flow;
                return 1;
            }
        }
        return 0;
    }

    ll maxFlow() {
        ll flow = 0;
        for(limit = (1 << 30); limit > 0;) {
            if(!bfs()) {
                limit >>= 1;
                continue;
            }
            rep(i,s,t + 1) ptr[i] = 0;
            while(dfs(s, limit)) {
                flow += limit;
            }
        }
        return flow;
    }
};