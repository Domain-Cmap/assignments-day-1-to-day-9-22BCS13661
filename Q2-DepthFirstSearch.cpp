#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
using namespace std;

class Graph {
private:
    unordered_map<int, list<int>> adjList;

public:
    void addEdge(int v, int w) {
        adjList[v].push_back(w);
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
};

int main() {
    Graph g;
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 6);

    cout << "DFS Traversal Order starting from vertex 1: ";
    g.DFS(1);

    return 0;
}