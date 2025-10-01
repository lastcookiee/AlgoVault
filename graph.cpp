#include "graph.h"
#include "utils.h"
#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>

// Constructor
Graph::Graph(int v) : vertices(v)
{
    adjList.resize(v);
    weightedAdjList.resize(v);
}

// Add edge for unweighted graph
void Graph::addEdge(int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u); // For undirected graph
}

// Add weighted edge for weighted graph
void Graph::addWeightedEdge(int u, int v, int weight)
{
    weightedAdjList[u].push_back(std::make_pair(v, weight));
    weightedAdjList[v].push_back(std::make_pair(u, weight)); // For undirected graph
}

// Create sample unweighted graph for demonstration
void Graph::createSampleGraph()
{
    // Sample graph structure:
    //     0
    //    / |
    //   1---2
    //   |   |
    //   3---4

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 4);

    Utils::setColor(LIGHT_GREEN);
    std::cout << "Sample graph created with 5 vertices (0-4)" << std::endl;
    std::cout << "Graph structure:" << std::endl;
    std::cout << "    0" << std::endl;
    std::cout << "   / \\" << std::endl;
    std::cout << "  1---2" << std::endl;
    std::cout << "  |   |" << std::endl;
    std::cout << "  3---4" << std::endl;
    Utils::resetColor();
}

// Create sample weighted graph for Dijkstra
void Graph::createSampleWeightedGraph()
{
    // Sample weighted graph
    addWeightedEdge(0, 1, 4);
    addWeightedEdge(0, 2, 1);
    addWeightedEdge(1, 2, 2);
    addWeightedEdge(1, 3, 5);
    addWeightedEdge(2, 3, 8);
    addWeightedEdge(2, 4, 10);
    addWeightedEdge(3, 4, 2);

    Utils::setColor(LIGHT_GREEN);
    std::cout << "Sample weighted graph created with 5 vertices (0-4)" << std::endl;
    std::cout << "Edges with weights:" << std::endl;
    std::cout << "0-1 (4), 0-2 (1), 1-2 (2), 1-3 (5)" << std::endl;
    std::cout << "2-3 (8), 2-4 (10), 3-4 (2)" << std::endl;
    Utils::resetColor();
}

// Input graph from user
void Graph::inputGraph()
{
    int edges;
    std::cout << "Enter number of edges: ";
    std::cin >> edges;

    std::cout << "Enter edges (format: u v):" << std::endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        std::cout << "Edge " << (i + 1) << ": ";
        std::cin >> u >> v;

        if (u >= 0 && u < vertices && v >= 0 && v < vertices)
        {
            addEdge(u, v);
        }
        else
        {
            Utils::setColor(RED);
            std::cout << "Invalid vertices! Please enter values between 0 and " << (vertices - 1) << std::endl;
            Utils::resetColor();
            i--; // Retry this edge
        }
    }
}

// Input weighted graph from user
void Graph::inputWeightedGraph()
{
    int edges;
    std::cout << "Enter number of edges: ";
    std::cin >> edges;

    std::cout << "Enter edges with weights (format: u v weight):" << std::endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v, weight;
        std::cout << "Edge " << (i + 1) << ": ";
        std::cin >> u >> v >> weight;

        if (u >= 0 && u < vertices && v >= 0 && v < vertices && weight >= 0)
        {
            addWeightedEdge(u, v, weight);
        }
        else
        {
            Utils::setColor(RED);
            std::cout << "Invalid input! Vertices should be between 0 and " << (vertices - 1)
                      << " and weight should be non-negative." << std::endl;
            Utils::resetColor();
            i--; // Retry this edge
        }
    }
}

// Display unweighted graph
void Graph::displayGraph()
{
    Utils::setColor(CYAN);
    std::cout << "\n--- Graph Adjacency List ---" << std::endl;
    Utils::resetColor();

    for (int i = 0; i < vertices; i++)
    {
        std::cout << "Vertex " << i << ": ";
        for (auto &neighbor : adjList[i])
        {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}

// Display weighted graph
void Graph::displayWeightedGraph()
{
    Utils::setColor(CYAN);
    std::cout << "\n--- Weighted Graph Adjacency List ---" << std::endl;
    Utils::resetColor();

    for (int i = 0; i < vertices; i++)
    {
        std::cout << "Vertex " << i << ": ";
        for (auto &edge : weightedAdjList[i])
        {
            std::cout << "(" << edge.first << "," << edge.second << ") ";
        }
        std::cout << std::endl;
    }
}

// Print traversal step for visualization
void Graph::printTraversalStep(int vertex, const std::string &algorithm, const std::string &structure)
{
    Utils::setColor(LIGHT_GREEN);
    std::cout << algorithm << " - Visiting vertex " << vertex;
    Utils::resetColor();
    std::cout << " [" << structure << "]";
    std::cout << std::endl;
    // Pause removed for compatibility
}

// Show complexity information
void Graph::showComplexityInfo(const std::string &algorithm)
{
    if (algorithm == "BFS")
    {
        Utils::printComplexity("Breadth-First Search", "O(V + E)", "O(V)");
    }
    else if (algorithm == "DFS")
    {
        Utils::printComplexity("Depth-First Search", "O(V + E)", "O(V)");
    }
    else if (algorithm == "Dijkstra")
    {
        Utils::printComplexity("Dijkstra's Algorithm", "O((V + E) log V)", "O(V)");
    }
}

// ==================== BREADTH-FIRST SEARCH ====================

void Graph::BFS(int startVertex)
{
    Utils::printHeader("BREADTH-FIRST SEARCH (BFS) VISUALIZATION");
    Utils::setColor(CYAN);
    std::cout << "BFS explores vertices level by level using a queue." << std::endl;
    Utils::resetColor();

    displayGraph();

    std::vector<bool> visited(vertices, false);
    std::queue<int> queue;

    Utils::setColor(YELLOW);
    std::cout << "\nStarting BFS from vertex " << startVertex << std::endl;
    Utils::resetColor();

    visited[startVertex] = true;
    queue.push(startVertex);

    std::cout << "\nTraversal order:" << std::endl;
    Utils::printSeparator('-', 40);

    while (!queue.empty())
    {
        int currentVertex = queue.front();
        queue.pop();

        // Show current queue state
        std::string queueState = "Queue: [";
        std::queue<int> tempQueue = queue;
        bool first = true;
        while (!tempQueue.empty())
        {
            if (!first)
                queueState += ", ";
            queueState += std::to_string(tempQueue.front());
            tempQueue.pop();
            first = false;
        }
        queueState += "]";

        printTraversalStep(currentVertex, "BFS", queueState);

        // Explore all adjacent vertices
        Utils::setColor(LIGHT_BLUE);
        std::cout << "  Exploring neighbors of " << currentVertex << ": ";
        Utils::resetColor();

        for (auto &neighbor : adjList[currentVertex])
        {
            std::cout << neighbor << " ";
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                queue.push(neighbor);
                Utils::setColor(GREEN);
                std::cout << "(added to queue) ";
                Utils::resetColor();
            }
            else
            {
                Utils::setColor(RED);
                std::cout << "(already visited) ";
                Utils::resetColor();
            }
        }
        std::cout << std::endl;
        Utils::printSeparator('-', 20);
    }

    Utils::setColor(LIGHT_GREEN);
    std::cout << "\nBFS traversal completed!" << std::endl;
    Utils::resetColor();

    showComplexityInfo("BFS");
}

// ==================== DEPTH-FIRST SEARCH ====================

void Graph::DFS(int startVertex)
{
    Utils::printHeader("DEPTH-FIRST SEARCH (DFS) VISUALIZATION");
    Utils::setColor(CYAN);
    std::cout << "DFS explores as far as possible along each branch using a stack." << std::endl;
    Utils::resetColor();

    displayGraph();

    std::vector<bool> visited(vertices, false);
    std::stack<int> stack;

    Utils::setColor(YELLOW);
    std::cout << "\nStarting DFS from vertex " << startVertex << std::endl;
    Utils::resetColor();

    stack.push(startVertex);

    std::cout << "\nTraversal order:" << std::endl;
    Utils::printSeparator('-', 40);

    while (!stack.empty())
    {
        int currentVertex = stack.top();
        stack.pop();

        if (!visited[currentVertex])
        {
            visited[currentVertex] = true;

            // Show current stack state
            std::string stackState = "Stack: [";
            std::stack<int> tempStack = stack;
            std::vector<int> stackContents;
            while (!tempStack.empty())
            {
                stackContents.push_back(tempStack.top());
                tempStack.pop();
            }

            for (int i = stackContents.size() - 1; i >= 0; i--)
            {
                if (i < (int)stackContents.size() - 1)
                    stackState += ", ";
                stackState += std::to_string(stackContents[i]);
            }
            stackState += "]";

            printTraversalStep(currentVertex, "DFS", stackState);

            // Add all unvisited neighbors to stack (in reverse order to maintain left-to-right traversal)
            Utils::setColor(LIGHT_BLUE);
            std::cout << "  Adding unvisited neighbors of " << currentVertex << " to stack: ";
            Utils::resetColor();

            std::vector<int> neighbors;
            for (auto &neighbor : adjList[currentVertex])
            {
                neighbors.push_back(neighbor);
            }

            // Add in reverse order to maintain proper traversal order
            for (int i = neighbors.size() - 1; i >= 0; i--)
            {
                int neighbor = neighbors[i];
                std::cout << neighbor << " ";
                if (!visited[neighbor])
                {
                    stack.push(neighbor);
                    Utils::setColor(GREEN);
                    std::cout << "(added) ";
                    Utils::resetColor();
                }
                else
                {
                    Utils::setColor(RED);
                    std::cout << "(already visited) ";
                    Utils::resetColor();
                }
            }
            std::cout << std::endl;
            Utils::printSeparator('-', 20);
        }
    }

    Utils::setColor(LIGHT_GREEN);
    std::cout << "\nDFS traversal completed!" << std::endl;
    Utils::resetColor();

    showComplexityInfo("DFS");
}

// ==================== DIJKSTRA'S SHORTEST PATH ====================

void Graph::dijkstra(int startVertex)
{
    Utils::printHeader("DIJKSTRA'S SHORTEST PATH VISUALIZATION");
    Utils::setColor(CYAN);
    std::cout << "Dijkstra's algorithm finds shortest paths from source to all vertices." << std::endl;
    Utils::resetColor();

    displayWeightedGraph();

    // Initialize distances and parent array
    std::vector<int> dist(vertices, std::numeric_limits<int>::max());
    std::vector<int> parent(vertices, -1);
    std::vector<bool> visited(vertices, false);

    // Priority queue to store vertices and their distances
    std::priority_queue<MinHeapNode, std::vector<MinHeapNode>, Compare> pq;

    // Distance of source vertex from itself is always 0
    dist[startVertex] = 0;
    pq.push(MinHeapNode(startVertex, 0));

    Utils::setColor(YELLOW);
    std::cout << "\nStarting Dijkstra's algorithm from vertex " << startVertex << std::endl;
    Utils::resetColor();

    std::cout << "\nStep-by-step execution:" << std::endl;
    Utils::printSeparator('-', 50);

    int step = 1;
    while (!pq.empty())
    {
        // Extract minimum distance vertex from priority queue
        int u = pq.top().vertex;
        pq.pop();

        if (visited[u])
            continue; // Skip if already visited

        visited[u] = true;

        Utils::setColor(LIGHT_GREEN);
        std::cout << "Step " << step++ << " - Processing vertex " << u
                  << " (distance: " << dist[u] << ")" << std::endl;
        Utils::resetColor();

        // Update distances of all adjacent vertices
        Utils::setColor(LIGHT_BLUE);
        std::cout << "  Checking neighbors of vertex " << u << ":" << std::endl;
        Utils::resetColor();

        for (auto &edge : weightedAdjList[u])
        {
            int v = edge.first;
            int weight = edge.second;

            std::cout << "    Neighbor " << v << " (edge weight: " << weight << ")";

            if (!visited[v] && dist[u] != std::numeric_limits<int>::max() &&
                dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push(MinHeapNode(v, dist[v]));

                Utils::setColor(GREEN);
                std::cout << " -> Updated distance to " << dist[v] << std::endl;
                Utils::resetColor();
            }
            else if (visited[v])
            {
                Utils::setColor(RED);
                std::cout << " -> Already visited" << std::endl;
                Utils::resetColor();
            }
            else
            {
                Utils::setColor(YELLOW);
                std::cout << " -> No improvement (current: " << dist[v] << ")" << std::endl;
                Utils::resetColor();
            }
        }

        // Show current distances
        Utils::setColor(CYAN);
        std::cout << "  Current distances: ";
        for (int i = 0; i < vertices; i++)
        {
            if (dist[i] == std::numeric_limits<int>::max())
            {
                std::cout << "∞ ";
            }
            else
            {
                std::cout << dist[i] << " ";
            }
        }
        std::cout << std::endl;
        Utils::resetColor();

        Utils::printSeparator('-', 30);
        // Pause removed for compatibility
    }

    // Print final results
    Utils::setColor(LIGHT_GREEN);
    std::cout << "\nShortest distances from vertex " << startVertex << ":" << std::endl;
    Utils::resetColor();

    for (int i = 0; i < vertices; i++)
    {
        std::cout << "Vertex " << i << ": ";
        if (dist[i] == std::numeric_limits<int>::max())
        {
            Utils::setColor(RED);
            std::cout << "∞ (unreachable)" << std::endl;
            Utils::resetColor();
        }
        else
        {
            Utils::setColor(GREEN);
            std::cout << dist[i];
            Utils::resetColor();
            if (i != startVertex)
            {
                std::cout << " (Path: ";
                printPath(parent, i);
                std::cout << ")";
            }
            std::cout << std::endl;
        }
    }

    showComplexityInfo("Dijkstra");
}

// Print path from source to target
void Graph::printPath(const std::vector<int> &parent, int target)
{
    if (parent[target] == -1)
    {
        std::cout << target;
        return;
    }
    printPath(parent, parent[target]);
    std::cout << " -> " << target;
}

// ==================== MENU FUNCTIONS ====================

void Graph::showGraphMenu()
{
    Utils::printHeader("GRAPH ALGORITHMS MENU");
    std::cout << "1. Breadth-First Search (BFS)" << std::endl;
    std::cout << "2. Depth-First Search (DFS)" << std::endl;
    std::cout << "3. Dijkstra's Shortest Path" << std::endl;
    std::cout << "4. Back to Main Menu" << std::endl;
    Utils::printSeparator('-', 30);
}

void Graph::runGraphAlgorithms()
{
    int choice;

    while (true)
    {
        Utils::clearConsole();
        showGraphMenu();

        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;

        if (choice >= 1 && choice <= 3)
        {
            Utils::clearConsole();

            int vertices, startVertex;
            char useSample;

            std::cout << "Use sample graph? (y/n): ";
            std::cin >> useSample;

            if (useSample == 'y' || useSample == 'Y')
            {
                vertices = 5; // Sample graph has 5 vertices
                Graph g(vertices);

                if (choice == 3)
                { // Dijkstra needs weighted graph
                    g.createSampleWeightedGraph();
                }
                else
                { // BFS and DFS use unweighted graph
                    g.createSampleGraph();
                }

                std::cout << "\nEnter starting vertex (0-" << (vertices - 1) << "): ";
                std::cin >> startVertex;

                if (startVertex >= 0 && startVertex < vertices)
                {
                    Utils::clearConsole();

                    switch (choice)
                    {
                    case 1:
                        g.BFS(startVertex);
                        break;
                    case 2:
                        g.DFS(startVertex);
                        break;
                    case 3:
                        g.dijkstra(startVertex);
                        break;
                    }
                }
                else
                {
                    Utils::setColor(RED);
                    std::cout << "Invalid starting vertex!" << std::endl;
                    Utils::resetColor();
                }
            }
            else
            {
                vertices = Utils::getPositiveIntFromUser("Enter number of vertices: ");
                Graph g(vertices);

                if (choice == 3)
                { // Dijkstra
                    g.inputWeightedGraph();
                }
                else
                { // BFS and DFS
                    g.inputGraph();
                }

                std::cout << "\nEnter starting vertex (0-" << (vertices - 1) << "): ";
                std::cin >> startVertex;

                if (startVertex >= 0 && startVertex < vertices)
                {
                    Utils::clearConsole();

                    switch (choice)
                    {
                    case 1:
                        g.BFS(startVertex);
                        break;
                    case 2:
                        g.DFS(startVertex);
                        break;
                    case 3:
                        g.dijkstra(startVertex);
                        break;
                    }
                }
                else
                {
                    Utils::setColor(RED);
                    std::cout << "Invalid starting vertex!" << std::endl;
                    Utils::resetColor();
                }
            }

            Utils::pauseConsole();
        }
        else if (choice == 4)
        {
            return;
        }
        else
        {
            Utils::setColor(RED);
            std::cout << "Invalid choice! Please try again." << std::endl;
            Utils::resetColor();
            Utils::pauseConsole();
        }
    }
}