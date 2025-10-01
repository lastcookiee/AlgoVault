#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <limits>

/**
 * Graph Algorithms Implementation for AlgoVault
 * Includes: BFS, DFS, Dijkstra's Shortest Path
 * Uses adjacency list representation
 */

class Graph
{
private:
    int vertices;
    std::vector<std::list<int>> adjList;                         // For BFS and DFS
    std::vector<std::list<std::pair<int, int>>> weightedAdjList; // For Dijkstra (vertex, weight)

public:
    // Constructors
    Graph(int v);

    // Graph building functions
    void addEdge(int u, int v);                     // For unweighted graphs
    void addWeightedEdge(int u, int v, int weight); // For weighted graphs
    void createSampleGraph();                       // Create a sample graph for demonstration
    void createSampleWeightedGraph();               // Create a sample weighted graph

    // Graph input functions
    void inputGraph();
    void inputWeightedGraph();

    // Graph display functions
    void displayGraph();
    void displayWeightedGraph();

    // Algorithm implementations
    void BFS(int startVertex);
    void DFS(int startVertex);
    void dijkstra(int startVertex);

    // Utility functions
    void printTraversalStep(int vertex, const std::string &algorithm, const std::string &structure);
    void printPath(const std::vector<int> &parent, int target);
    void showComplexityInfo(const std::string &algorithm);

    // Menu and driver functions
    static void showGraphMenu();
    static void runGraphAlgorithms();
};

// Structure for Dijkstra's algorithm priority queue
struct MinHeapNode
{
    int vertex;
    int distance;

    MinHeapNode(int v, int d) : vertex(v), distance(d) {}
};

// Comparator for priority queue (min heap)
struct Compare
{
    bool operator()(const MinHeapNode &a, const MinHeapNode &b)
    {
        return a.distance > b.distance;
    }
};

#endif // GRAPH_H