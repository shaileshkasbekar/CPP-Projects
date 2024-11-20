#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class GraphMatrix {
    int V;
    vector<vector<int>> adjMatrix;

public:
    GraphMatrix(int V) {
        this->V = V;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int i = 0; i < V; i++) {
                if (adjMatrix[current][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> s;

        s.push(start);
        cout << "DFS Traversal: ";

        while (!s.empty()) {
            int current = s.top();
            s.pop();

            if (!visited[current]) {
                cout << current << " ";
                visited[current] = true;
            }

            for (int i = V - 1; i >= 0; i--) {
                if (adjMatrix[current][i] == 1 && !visited[i]) {
                    s.push(i);
                }
            }
        }
        cout << endl;
    }
};

class GraphList {
    int V;
    vector<vector<int>> adjList;

public:
    GraphList(int V) {
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int vertex, vector<bool> &visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main() {
    GraphMatrix gMatrix(5);
    gMatrix.addEdge(0, 1);
    gMatrix.addEdge(0, 2);
    gMatrix.addEdge(1, 3);
    gMatrix.addEdge(1, 4);
    gMatrix.addEdge(2, 4);

    cout << "Graph Representation using Adjacency Matrix:" << endl;
    gMatrix.BFS(0);
    gMatrix.DFS(0);

    cout << endl;

    GraphList gList(5);
    gList.addEdge(0, 1);
    gList.addEdge(0, 2);
    gList.addEdge(1, 3);
    gList.addEdge(1, 4);
    gList.addEdge(2, 4);

    cout << "Graph Representation using Adjacency List:" << endl;
    gList.BFS(0);
    gList.DFS(0);

    return 0;
}