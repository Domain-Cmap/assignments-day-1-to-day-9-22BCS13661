#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<set>
using namespace std;

class Graph {
private:
    unordered_map<char, list<char>> adjList;

public:
    void addEdge(char v, char w) {
        adjList[v].push_back(w);
        adjList[w].push_back(v); // Assuming it's an undirected graph
    }

    void BFS(char start) {
        set<char> visited;
        queue<char> q;

        visited.insert(start);
        q.push(start);

        while (!q.empty()) {
            char vertex = q.front();
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
};

int main() {
    Graph g;
    g.addEdge('A', 'B');
    g.addEdge('A', 'C');
    g.addEdge('B', 'D');
    g.addEdge('B', 'E');
    g.addEdge('C', 'F');

    cout << "BFS Traversal Order starting from vertex A: ";
    g.BFS('A');

    return 0;
}