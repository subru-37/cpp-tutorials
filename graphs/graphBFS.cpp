#include <iostream>
#include <vector>
#include <queue>
#include <stack>


using namespace std;


//graphs in cpp
//adjacent matrix representation:
//it is a matrix n x n where n is the number of vertices
//a[i][j] is 1, if i and j are adjacent, 0 otherwise
// space complexity theta(n**2)
// better for dense graphs

//adjacent list  representation:
//consists of n number of linked list with each linked list containing the adjacent nodes of each node
// space complexity theta(n + 2e)
//better for sparse graphs

// BFS(level order) and DFS search

//BFS involves a queue and inserting each adjacent node which has not been visited/added to queue

//DFS involves a stack and adding any one of the adjacent node which has not been visited and backtrack on reaching
//   dead-end to go to unvisited nodes
//   stop DFS when the stack is empty
void bfs(vector<vector<int> >& adjList, int startNode, vector<bool>& visited){
    
    queue<int> q;
    visited[startNode] = true;
    q.push(startNode);
    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";
        for (int neighbor : adjList[currentNode]) {
            // cout<<neighbor<<endl;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
// adjacent matrix representation
void dfsmatrix(vector<vector<int>>& adjList, vector<bool>& vis, int i){
    cout<<i<<" ";
    vis[i] = true;
    for(int j=0;j<adjList.size(); j++){
        if(!vis[j] && adjList[i][j] == 1)
            dfsmatrix(adjList, vis, j);
    }
}

// adjacent list representation 
void dfslist( vector<vector<int>>&adj_list, vector<bool>&vis,int i){
    cout<<i<<" ";
    vis[i] = true;
    for(auto neighbor:adj_list[i]){
        if(!vis[neighbor])
            dfslist(adj_list,vis,neighbor);
            // cout<<neighbor<<endl;
    }
}

void DFS(vector<vector<int> >& adjList, int startNode, vector<bool>& visited){
    stack<int> mystack;

    mystack.push(startNode);
    while(!mystack.empty()){
        int currentNode = mystack.top();
        if(!visited[currentNode]) cout << currentNode << " ";
        visited[currentNode] = true;
        mystack.pop();
        for(int neighbor: adjList[currentNode]){
            if(!visited[neighbor]){
                mystack.push(neighbor);
            }
        }
    }

}

// Function to add an edge to the graph
void addEdge(vector<vector<int> >& adjList, int u, int v){
    adjList[u].push_back(v);
}

int main(){
    // Number of vertices in the graph
    int vertices = 5;

    // Adjacency list representation of the graph
    vector<vector<int> > adjList(vertices);

    // Add edges to the graph
    // addEdge(adjList, 0, 1);
    // addEdge(adjList, 0, 2);
    // addEdge(adjList, 1, 3);
    // addEdge(adjList, 1, 0);
    // addEdge(adjList, 1, 2);
    // addEdge(adjList, 2, 1);
    // addEdge(adjList, 2, 0);
    // addEdge(adjList, 2, 4);
    // addEdge(adjList, 3, 1);
    // addEdge(adjList, 3, 4);
    // addEdge(adjList, 4, 2);
    // addEdge(adjList, 4, 3);

    addEdge(adjList,0, 1);
    addEdge(adjList,0, 2);
    addEdge(adjList,0, 3);
    addEdge(adjList,1, 0);
    addEdge(adjList,2, 3);
    addEdge(adjList,2, 4);
    addEdge(adjList,3, 2);
    addEdge(adjList,3, 0);
    addEdge(adjList,4, 2);

    // Mark all the vertices as not visited
    vector<bool> visited(vertices, false);

    // Perform BFS traversal starting from vertex 0
    cout << "Breadth First Traversal starting from vertex "
            "0: ";
    int start = 1;
    dfslist(adjList, visited, start);

    return 0;
}