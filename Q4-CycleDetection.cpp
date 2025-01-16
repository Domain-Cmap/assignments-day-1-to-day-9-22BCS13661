#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
using namespace std;

class Graph {
private:
    unordered_map<char, list<char>> adjList;

public:
    void addEdge(char v, char w) {
        adjList[v].push_back(w);
    }

    bool isCyclicUtil(char v, set<char>& visited, set<char>& recStack) {
        if (visited.find(v) == visited.end()) {
            visited.insert(v);
            recStack.insert(v);

            for (auto adj : adjList[v]) {
                if (visited.find(adj) == visited.end() && isCyclicUtil(adj, visited, recStack)) {
                    return true;
                } else if (recStack.find(adj) != recStack.end()) {
                    return true;
                }
            }
        }
        recStack.erase(v);
        return false;
    }

    bool isCyclic() {
        set<char> visited;
        set<char> recStack;

        for (auto i : adjList) {
            if (isCyclicUtil(i.first, visited, recStack)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g;
    g.addEdge('A', 'B');
    g.addEdge('B', 'C');
    g.addEdge('C', 'A');

    if (g.isCyclic()) {
        cout << "Cycle Detected: Yes" << endl;
    } else {
        cout << "Cycle Detected: No" << endl;
    }

    return 0;
}