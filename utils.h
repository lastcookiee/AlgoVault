#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <string>
#include <chrono>

/**
 * Utility functions for AlgoVault
 * Contains common functions used across sorting and graph algorithms
 */

class Utils
{
public:
    // Array printing utilities
    static void printArray(const std::vector<int> &arr, const std::string &message = "");
    static void printArrayRange(const std::vector<int> &arr, int start, int end, const std::string &message = "");

    // Input utilities
    static std::vector<int> getArrayFromUser();
    static int getPositiveIntFromUser(const std::string &prompt);

    // Display utilities
    static void printSeparator(char c = '-', int length = 50);
    static void printHeader(const std::string &title);
    static void printComplexity(const std::string &algorithm, const std::string &timeComplexity, const std::string &spaceComplexity);

    // Pause and clear utilities
    static void pauseConsole();
    static void clearConsole();

    // Color output utilities (for Windows console)
    static void setColor(int color);
    static void resetColor();
};

// Color constants for Windows console
enum ConsoleColors
{
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LIGHT_GRAY = 7,
    DARK_GRAY = 8,
    LIGHT_BLUE = 9,
    LIGHT_GREEN = 10,
    LIGHT_CYAN = 11,
    LIGHT_RED = 12,
    LIGHT_MAGENTA = 13,
    YELLOW = 14,
    WHITE = 15
};

#endif // UTILS_H