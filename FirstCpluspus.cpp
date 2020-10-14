#include <iostream>
#include <queue>

const int maxn = 10;
const int maxm = 20;

int n, m, first, last;
int head[maxn + 2], adj[maxn + 1], adv[maxn + 1], minlength[maxn + 1],
		u[maxm + 1],v[maxm + 1],t[maxm + 1],trace[maxn + 1];
std::queue<int> q;
bool freeu[maxn + 1];

void docf() {
	std::cin >> n >> m;
	for (int i = 0; i <= n + 1; i++) {
		head[i] = 0;
	}

	for (int i = 1; i <= m; i++) {
		std::cin >> u[i] >> v[i] >> t[i];
		head[u[i]]++;
		head[v[i]]++;
	} 

	for (int i = 2; i <= n + 1; i++)
		head[i] += head[i - 1];

	for (int i = 1; i <= m; i++) {
		adj[head[u[i]]] = v[i];
		adj[head[v[i]]] = u[i];
		adv[head[u[i]]] = t[i];
		adv[head[v[i]]] = t[i];
		head[u[i]]--;
		head[v[i]]--;
	}
}

void bfs() {
	int u, v;
	while (!q.empty()) {
		u = q.front();
		std::cout << u << " ";
		q.pop();
		for (int i = head[u] + 1; i <= head[u + 1]; i++) {
			if (freeu[adj[i]]) {
				v = adj[i];
				q.push(v);
				freeu[v] = false;
				trace[v] = u;
			}
		}
	}
}

void init() {
	memset(freeu, true, maxn + 1);
	memset(trace, 0, maxn + 1);
	memset(minlength, 1000000, maxn + 1);
	q.push(1);
	freeu[1] = false;
}

int main() {
	freopen("file.inp", "r", stdin);
	freopen("file.out", "w", stdout);

	init();
	docf();
	bfs();

	return 0;
}