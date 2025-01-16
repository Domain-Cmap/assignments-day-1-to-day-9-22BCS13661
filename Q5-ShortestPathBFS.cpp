#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Graph {
private:
    unordered_map<char, list<char>> adjList;

public:
    void addEdge(char v, char w) {
        adjList[v].push_back(w);
        adjList[w].push_back(v); // Assuming it's an undirected graph
    }

    vector<char> shortestPathBFS(char start, char end) {
        unordered_map<char, char> parent;
        unordered_set<char> visited;
        queue<char> q;

        visited.insert(start);
        q.push(start);
        parent[start] = '\0'; // Mark the start node's parent as null

        while (!q.empty()) {
            char vertex = q.front();
            q.pop();

            if (vertex == end) {
                break;
            }

            for (auto adj : adjList[vertex]) {
                if (visited.find(adj) == visited.end()) {
                    visited.insert(adj);
                    q.push(adj);
                    parent[adj] = vertex;
                }
            }
        }

        vector<char> path;
        for (char at = end; at != '\0'; at = parent[at]) {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());

        return path;
    }
};

int main() {
    Graph g;
    g.addEdge('S', 'A');
    g.addEdge('S', 'B');
    g.addEdge('A', 'C');
    g.addEdge('B', 'D');
    g.addEdge('C', 'D');
    g.addEdge('C', 'E');
    g.addEdge('D', 'E');

    vector<char> path = g.shortestPathBFS('S', 'E');

    cout << "Shortest Path from S to E: ";
    for (char vertex : path) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}