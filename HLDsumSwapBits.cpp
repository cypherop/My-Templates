const ll N = 1e5 + 7;

vector<ll> parent, depth, heavy, head, pos;
ll cur_pos, n;
ll v[N][2], st[4*N][2],lazy[4*N];


void lazyp(ll node){
  if(lazy[node] == 0) return;
  lazy[node] = 0;
  swap(st[2 * node][0], st[2 * node][1]);
  swap(st[2 * node + 1][0], st[2 * node + 1][1]);
  lazy[2 * node] ^= 1;
  lazy[2 * node + 1] ^= 1;
}

void build(ll node,ll l,ll r){
  if(l==r){
    st[node][0] = v[l][0];
    st[node][1] = v[l][1];
    return; 
  }
  ll mid = (l+r)/2;
  build(2*node,l,mid);
  build(2*node+1,mid+1,r);
  st[node][0] = st[2 * node][0] + st[2 * node + 1][0];
  st[node][1] = st[2 * node][1] + st[2 * node + 1][1];
  return;
}

ll query(ll node,ll l,ll r,ll sb,ll se){
  if(sb>r||se<l) return 0;
    if(sb>=l&&se<=r) return st[node][0];
  lazyp(node);
  ll mid=(sb+se)/2;
  ll left=query(2*node,l,r,sb,mid);
  ll right=query(2*node+1,l,r,mid+1,se);
  st[node][0] = st[2 * node][0] + st[2 * node + 1][0];
  st[node][1] = st[2 * node][1] + st[2 * node + 1][1];
  return left+right;
}

void update(ll node,ll l,ll r, ll sb,ll se){
  if(sb>r||se<l) return;
  if(sb>=l&&se<=r){
    swap(st[node][0],st[node][1]);
    lazy[node] ^= 1;
    return;
  }lazyp(node);
  ll mid=(sb+se)/2;
  update(2*node,l,r,sb,mid);
  update(2*node+1,l,r,mid+1,se);
  st[node][0] = st[2 * node][0] + st[2 * node + 1][0];
  st[node][1] = st[2 * node][1] + st[2 * node + 1][1];
}


ll dfs(ll v, vector<vector<ll>> & adj) {
    ll size = 1;
    ll max_c_size = 0;
    for (ll c : adj[v]) {
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            ll c_size = dfs(c, adj);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    }
    return size;
}

void decompose(ll v, ll h, vector<vector<ll>> & adj) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (ll c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
}

void init(vector<vector<ll>> & adj) {
    ll n = adj.size();
    parent = vector<ll>(n);
    depth = vector<ll>(n);
    heavy = vector<ll>(n, -1);
    head = vector<ll>(n);
    pos = vector<ll>(n);
    cur_pos = 0;

    dfs(0, adj);
    decompose(0, 0, adj);
}

ll query(ll a, ll b) {
    ll res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        res += query(1, pos[head[b]], pos[b], 0, n - 1);
    }
    if (depth[a] > depth[b])
        swap(a, b);
    res += query(1, pos[a], pos[b], 0, n - 1);
    return res;
}

void update(ll a, ll b) {
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        update(1, pos[head[b]], pos[b], 0, n - 1);
    }
    if (depth[a] > depth[b])
        swap(a, b);
    update(1, pos[a], pos[b], 0, n - 1);
}

ll l;
vector<vector<ll>> adj;

ll timer;
vector<ll> tin, tout;
vector<vector<ll>> up;

void dfs(ll v, ll p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (ll i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (ll u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(ll u, ll v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

ll lca(ll u, ll v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (ll i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(ll root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<ll>(l + 1));
    dfs(root, root);
}