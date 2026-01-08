// C++ Program to Implement Adjacency Matrix
#include <iostream>
using namespace std;
// Number of vertices
#define V 6

// Function to initialize the adjacency matrix
void initAdjMatrix(int adjMatrix[V][V])
{
    // Initialize all elements of the adjacency matrix to 0
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(int adjMatrix[V][V], int u, int v)
{
    // Mark the edge between vertices u and v as 1
    adjMatrix[u][v] = 1;
    // For undirected graph, mark opposite edge as well
    adjMatrix[v][u] = 1;
}

// Function to print the adjacency matrix
void printAdjMatrix(int adjMatrix[V][V])
{
    // Print the adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int adjMatrix[V][V];

    // Initialize the adjacency matrix
    initAdjMatrix(adjMatrix);

    // Add edges to the graph
    addEdge(adjMatrix, 0, 3);
    addEdge(adjMatrix, 0, 4);
    addEdge(adjMatrix, 1, 4);
    addEdge(adjMatrix, 1, 5);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 2, 5);
    addEdge(adjMatrix, 2, 3);
    addEdge(adjMatrix, 3, 5);
    addEdge(adjMatrix, 4, 5);

    cout << "Adjacency Matrix:" << endl;
    // Print the adjacency matrix
    printAdjMatrix(adjMatrix);

    return 0;
}
