//ASSIGNMENT 2: BFS traversal display
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph {
    int vertices;
    vector<vector<int> > adjacencyList;

public:
    Graph(int v) : vertices(v), adjacencyList(v) {}

    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    void BFS(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int current = q.front();
            cout << current << " ";
            q.pop();

            for (int neighbor : adjacencyList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int numVertices;

    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    Graph g(numVertices);

    char isConnected;
    for (int u = 0; u < numVertices; ++u) {
        for (int v = u + 1; v < numVertices; ++v) {
            cout << "Are vertex " << u << " and vertex " << v << " connected? (y/n): ";
            cin >> isConnected;

            if (isConnected == 'y' || isConnected == 'Y') {
                g.addEdge(u, v);
            }
        }
    }

    int startVertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    cout << "BFS Traversal starting from vertex " << startVertex << ": ";
    g.BFS(startVertex);

    return 0;
}
