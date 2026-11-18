// graph.cpp
#include <vector>
#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;
// Go ahead and get the code for today's lecture!
/* Puzzle : Get back the gold! 
Given a graph G = (V, E) and a source vertex (s). 
Somewhere deeper in the graph is gold at some vertex (goldVertex).
You only learn its value when you reach that vertex.
How do you bring the gold back to the source?*/

class Graph{
    public:
        Graph(int n){
            adjList.resize(n);
        }

        void addEdge(int source, int dest){
            adjList[source].insert(dest); // insert directed edge for a directed graph only do this
           // adjList[dest].insert(source);  // for a undirected graph , also add this line

        }

        void display(){
            cout << "Displaying the adjacency list: " << endl;
            for(int v = 0; v < adjList.size(); v++){
                cout << v << " : ";
                for (auto u : adjList[v]){
                    cout << u << " ";
                }
                cout << endl;

            }

        }

        void exploreBFS(int source){
            queue<int> q;
            int n = adjList.size(); // number of vertices
            vector<bool> visited(n, false);
            visited[source] = true;
            cout << source << " ";
            q.push(source);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                // Getting the element at the front of queue and pop it out.
                for (auto v : adjList[u]){
                    // if neghbor v is not visited, then visit v, push into the queue
                    if (!visited[v]) {
                        visited[v] = true; 
                        cout << v << " ";
                        q.push(v);
                    }
                }

            }

        }

        void exploreDFS(int v){
            // Keep track of what has already been explored
            vector<bool> visited(adjList.size(), false);
            exploreDFSHelper(v, visited);
        }
    
    private:
        void exploreDFSHelper(int v, vector<bool>&  visited){
            // recursive depth first search
            // Visit v
            visited[v] = true;
            cout << "Visited vertex " << v << endl;
            for (auto w : adjList[v]){
                if(!visited[w]){
                    exploreDFSHelper(w, visited);
                    cout << "Coming back to " << v << " from " << w << endl;
                }
            }
            cout << "Leaving vertex " << v << endl;
         }
        // Adjacency list
        vector<unordered_set<int>> adjList;

};

/*
(Set of vertices) V = {0, 1, 2, 3, 4, 5}
Edge List E = {  (0, 2),
                 (2, 3), (2, 1), (2, 4),
                 (3, 1),
                 (1, 5), (1, 4),
                 (4, 5)
                 }

Adjacency List:
adjList 
0 : {2},
1 : {5, 4},
2 : {1, 3, 4},
3 : {1},
4 : {5},
5 : {}

*/
int main(int argc, char const *argv[])
{
    Graph g(6);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 1);
    g.addEdge(2, 4);
    g.addEdge(3, 1);
    g.addEdge(1, 5);
    g.addEdge(1, 4);
    g.addEdge(4, 5);

    g.display();
    cout << "Breadth First Traversal" <<endl;
    g.exploreBFS(3);
    cout << endl;

    cout << "Depth Frist Traversal" << endl;

    g.exploreDFS(0);
    cout << endl;
    return 0;
}
