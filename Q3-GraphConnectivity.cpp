#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<set>
using namespace std;

class Graph {
private:
    unordered_map<int, list<int>> adjList;

public:
    void addEdge(int v, int w) {
        adjList[v].push_back(w);
        adjList[w].push_back(v); // Assuming it's an undirected graph
    }

    void BFS(int start) {
        set<int> visited;
        queue<int> q;

        visited.insert(start);
        q.push(start);

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            cout << vertex << " ";

            for (auto adj : adjList[vertex]) {
                if (visited.find(adj) == visited.end()) {
                    visited.insert(adj);
                    q.push(adj);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int v, set<int>& visited) {
        visited.insert(v);
        cout << v << " ";

        for (auto adj : adjList[v]) {
            if (visited.find(adj) == visited.end()) {
                DFSUtil(adj, visited);
            }
        }
    }

    void DFS(int start) {
        set<int> visited;
        DFSUtil(start, visited);
        cout << endl;
    }

    bool isConnected() {
        set<int> visited;
        DFSUtil(0, visited);
        return visited.size() == adjList.size();
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);

    cout << "BFS Traversal Order starting from vertex 0: ";
    g.BFS(0);

    cout << "DFS Traversal Order starting from vertex 0: ";
    g.DFS(0);

    if (g.isConnected()) {
        cout << "Graph is connected." << endl;
    } else {
        cout << "Graph is not connected." << endl;
    }

    return 0;
}