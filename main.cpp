#include <iostream>
#include <string>
#include <windows.h>
#include <thread>
#include <chrono>
#include "utils.h"
#include "sorting.h"
#include "graph.h"

/**
 * AlgoVault - Interactive Algorithm Visualizer
 * A C++ console application that visualizes sorting and graph algorithms step-by-step
 *
 * Author: GitHub Copilot
 * Language: C++
 * Version: 1.0
 */

class AlgoVault
{
private:
    static void showMainMenu();
    static void showWelcomeMessage();
    static void showExitMessage();
    static void showAbout();

public:
    static void run();
};

void AlgoVault::showWelcomeMessage()
{
    Utils::clearConsole();

    // Set console window title
    SetConsoleTitleA("AlgoVault - Interactive Algorithm Visualizer");

    Utils::setColor(LIGHT_CYAN);
    std::cout << R"(
    ╔═══════════════════════════════════════════════════════════════╗
    ║                                                               ║
    ║      $$\      $$\                  $$\    $$\                ║
    ║      $$ |     $$ |                 $$ |   $$ |               ║
    ║   $$$$$$$ |$$$$$$ | $$$$$$\        $$ |   $$ | $$$$$$\  $$\  ║
    ║  $$  __$$ |$$  __$$ |\____$$\      $$ |   $$ |$$  __$$\  $$ | ║
    ║  $$ /  $$ |$$ /  $$ |$$$$$$$ |     \$$\  $$  /$$ /  \__|$$ | ║
    ║  $$ |  $$ |$$ |  $$ |$$  __$$ |      \$$\$$  / $$ |     $$ | ║
    ║  \$$$$$$$ |\$$$$$$$ |\$$$$$$$ |       \$$$  /  $$ |     $$ | ║
    ║   \_______| \_______| \_______|        \___/   \__|     \__| ║
    ║                                                               ║
    ║           Interactive Algorithm Visualizer                    ║
    ║                                                               ║
    ╚═══════════════════════════════════════════════════════════════╝
    )" << std::endl;
    Utils::resetColor();

    Utils::setColor(YELLOW);
    std::cout << "                 Welcome to AlgoVault!" << std::endl;
    std::cout << "         Visualize algorithms step-by-step" << std::endl;
    Utils::resetColor();

    Utils::printSeparator('=', 65);

    Utils::setColor(LIGHT_GREEN);
    std::cout << "Features:" << std::endl;
    std::cout << "• Sorting Algorithms: Bubble, Quick, Merge, Heap Sort" << std::endl;
    std::cout << "• Graph Algorithms: BFS, DFS, Dijkstra's Shortest Path" << std::endl;
    std::cout << "• Step-by-step visualization with color-coded output" << std::endl;
    std::cout << "• Time & Space complexity analysis" << std::endl;
    std::cout << "• Interactive input and sample data options" << std::endl;
    Utils::resetColor();

    Utils::printSeparator('=', 65);
    Utils::pauseConsole();
}

void AlgoVault::showMainMenu()
{
    Utils::printHeader("ALGOVAULT - MAIN MENU");

    Utils::setColor(LIGHT_BLUE);
    std::cout << "┌─────────────────────────────────────────────┐" << std::endl;
    std::cout << "│              Choose an option:              │" << std::endl;
    std::cout << "├─────────────────────────────────────────────┤" << std::endl;
    std::cout << "│  1. 🔢 Sorting Algorithms                   │" << std::endl;
    std::cout << "│      • Bubble Sort                          │" << std::endl;
    std::cout << "│      • Quick Sort                           │" << std::endl;
    std::cout << "│      • Merge Sort                           │" << std::endl;
    std::cout << "│      • Heap Sort                            │" << std::endl;
    std::cout << "├─────────────────────────────────────────────┤" << std::endl;
    std::cout << "│  2. 🕸️  Graph Algorithms                    │" << std::endl;
    std::cout << "│      • Breadth-First Search (BFS)          │" << std::endl;
    std::cout << "│      • Depth-First Search (DFS)            │" << std::endl;
    std::cout << "│      • Dijkstra's Shortest Path            │" << std::endl;
    std::cout << "├─────────────────────────────────────────────┤" << std::endl;
    std::cout << "│  3. ℹ️  About AlgoVault                     │" << std::endl;
    std::cout << "├─────────────────────────────────────────────┤" << std::endl;
    std::cout << "│  4. 🚪 Exit                                 │" << std::endl;
    std::cout << "└─────────────────────────────────────────────┘" << std::endl;
    Utils::resetColor();

    Utils::printSeparator('-', 45);
}

void AlgoVault::showAbout()
{
    Utils::clearConsole();
    Utils::printHeader("ABOUT ALGOVAULT");

    Utils::setColor(CYAN);
    std::cout << "AlgoVault is an interactive algorithm visualizer designed to help" << std::endl;
    std::cout << "students and developers understand how algorithms work through" << std::endl;
    std::cout << "step-by-step visualization." << std::endl;
    std::cout << std::endl;

    Utils::setColor(YELLOW);
    std::cout << "📚 Educational Features:" << std::endl;
    Utils::resetColor();
    std::cout << "• Real-time visualization of algorithm execution" << std::endl;
    std::cout << "• Color-coded output for better understanding" << std::endl;
    std::cout << "• Time and space complexity analysis" << std::endl;
    std::cout << "• Interactive input with validation" << std::endl;
    std::cout << "• Sample data for quick testing" << std::endl;
    std::cout << std::endl;

    Utils::setColor(YELLOW);
    std::cout << "🔧 Technical Details:" << std::endl;
    Utils::resetColor();
    std::cout << "• Language: C++" << std::endl;
    std::cout << "• Platform: Windows Console Application" << std::endl;
    std::cout << "• Architecture: Modular design with separate classes" << std::endl;
    std::cout << "• Data Structures: Vectors, Lists, Queues, Stacks, Priority Queues" << std::endl;
    std::cout << std::endl;

    Utils::setColor(YELLOW);
    std::cout << "🎯 Supported Algorithms:" << std::endl;
    Utils::resetColor();

    Utils::setColor(LIGHT_GREEN);
    std::cout << "Sorting Algorithms:" << std::endl;
    Utils::resetColor();
    std::cout << "  • Bubble Sort    - O(n²) time, O(1) space" << std::endl;
    std::cout << "  • Quick Sort     - O(n log n) avg, O(n²) worst time, O(log n) space" << std::endl;
    std::cout << "  • Merge Sort     - O(n log n) time, O(n) space" << std::endl;
    std::cout << "  • Heap Sort      - O(n log n) time, O(1) space" << std::endl;
    std::cout << std::endl;

    Utils::setColor(LIGHT_GREEN);
    std::cout << "Graph Algorithms:" << std::endl;
    Utils::resetColor();
    std::cout << "  • BFS            - O(V + E) time, O(V) space" << std::endl;
    std::cout << "  • DFS            - O(V + E) time, O(V) space" << std::endl;
    std::cout << "  • Dijkstra       - O((V + E) log V) time, O(V) space" << std::endl;
    std::cout << std::endl;

    Utils::setColor(LIGHT_CYAN);
    std::cout << "Created with ❤️ for learning and education" << std::endl;
    Utils::resetColor();

    Utils::pauseConsole();
}

void AlgoVault::showExitMessage()
{
    Utils::clearConsole();

    Utils::setColor(LIGHT_CYAN);
    std::cout << R"(
    ╔═══════════════════════════════════════════════════════════════╗
    ║                                                               ║
    ║                    Thanks for using                           ║
    ║                     AlgoVault!                               ║
    ║                                                               ║
    ║              🚀 Keep Learning, Keep Growing! 🚀               ║
    ║                                                               ║
    ║         Remember: Understanding algorithms is the key         ║
    ║              to becoming a better programmer!                 ║
    ║                                                               ║
    ╚═══════════════════════════════════════════════════════════════╝
    )" << std::endl;
    Utils::resetColor();

    Utils::setColor(YELLOW);
    std::cout << "              Hope you enjoyed the journey!" << std::endl;
    std::cout << "                  See you next time! 👋" << std::endl;
    Utils::resetColor();

    Utils::printSeparator('=', 65);
    Utils::pauseConsole();
}

void AlgoVault::run()
{
    // Show welcome message
    showWelcomeMessage();

    int choice;
    bool running = true;

    while (running)
    {
        Utils::clearConsole();
        showMainMenu();

        Utils::setColor(WHITE);
        std::cout << "Enter your choice (1-4): ";
        Utils::resetColor();

        std::cin >> choice;

        // Validate input
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            Utils::setColor(RED);
            std::cout << "Invalid input! Please enter a number between 1 and 4." << std::endl;
            Utils::resetColor();
            Utils::pauseConsole();
            continue;
        }

        switch (choice)
        {
        case 1:
            Utils::clearConsole();
            Utils::setColor(LIGHT_GREEN);
            std::cout << "🔢 Launching Sorting Algorithms Module..." << std::endl;
            Utils::resetColor();
            // Pause removed for compatibility
            SortingAlgorithms::runSortingAlgorithms();
            break;

        case 2:
            Utils::clearConsole();
            Utils::setColor(LIGHT_GREEN);
            std::cout << "🕸️ Launching Graph Algorithms Module..." << std::endl;
            Utils::resetColor();
            // Pause removed for compatibility
            Graph::runGraphAlgorithms();
            break;

        case 3:
            showAbout();
            break;

        case 4:
            running = false;
            showExitMessage();
            break;

        default:
            Utils::setColor(RED);
            std::cout << "❌ Invalid choice! Please select a number between 1 and 4." << std::endl;
            Utils::resetColor();
            Utils::pauseConsole();
            break;
        }
    }
}

// Main function - Entry point of the application
int main()
{
    try
    {
        // Enable console colors and UTF-8 support
        SetConsoleOutputCP(CP_UTF8);

        // Run the AlgoVault application
        AlgoVault::run();
    }
    catch (const std::exception &e)
    {
        Utils::setColor(RED);
        std::cout << "An error occurred: " << e.what() << std::endl;
        Utils::resetColor();
        Utils::pauseConsole();
        return 1;
    }
    catch (...)
    {
        Utils::setColor(RED);
        std::cout << "An unknown error occurred!" << std::endl;
        Utils::resetColor();
        Utils::pauseConsole();
        return 1;
    }

    return 0;
}