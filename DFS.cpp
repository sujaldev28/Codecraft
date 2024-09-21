#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int v) : V(v), adj(v) {}
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> s; s.push(start);
        while (!s.empty()) {
            int vertex = s.top(); s.pop();
            if (!visited[vertex]) {
                visited[vertex] = true;
                cout << vertex << " ";
                for (int neighbor : adj[vertex])
                    if (!visited[neighbor]) s.push(neighbor);
            }
        }
    }
};

int main() {
    int V, E, u, v, start;
    cin >> V;
    Graph g(V);
    cin >> E;
    for (int i = 0; i < E; i++) {
        cin >> u >> v; g.addEdge(u, v);
    }
    cin >> start;
    g.DFS(start);
    cout << endl;
    return 0;
}
