void dfs(int v, int p, bool keep) {
	int Max = -1, bigchild = -1;
	for(auto u : adj[v]) {
		if(u != p && Max < sz[u]) {
			Max = sz[u];
			bigchild = u;
		}
	}
	for(auto u : adj[v]) {
		if(u != p && u != bigchild) {
			dfs(u, v, 0);
		}
	}
	if(bigchild != -1) {
		dfs(bigchild, v, 1);
		swap(vec[v], vec[bigchild]);
	}
	vec[v].push_back(v);
	cnt[color[v]]++;
	for(auto u : adj[v]) {
		if(u != p && u != bigchild) {
			for(auto x : vec[u]) {
				cnt[color[x]]++;
				vec[v].push_back(x);
			}
		}
	}
	// there are cnt[c] vertex in subtree v color with c
	if(keep == 0) {
		for(auto u : vec[v]) {
			cnt[color[u]]--;
		}
	}
}