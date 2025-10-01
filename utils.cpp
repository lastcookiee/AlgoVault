#include "utils.h"
#include <windows.h>
#include <conio.h>
#include <iomanip>

void Utils::printArray(const std::vector<int> &arr, const std::string &message)
{
    if (!message.empty())
    {
        std::cout << message << ": ";
    }
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i];
        if (i < arr.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

void Utils::printArrayRange(const std::vector<int> &arr, int start, int end, const std::string &message)
{
    if (!message.empty())
    {
        std::cout << message << ": ";
    }
    std::cout << "[";
    for (int i = start; i <= end && i < static_cast<int>(arr.size()); ++i)
    {
        std::cout << arr[i];
        if (i < end && i < static_cast<int>(arr.size()) - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

std::vector<int> Utils::getArrayFromUser()
{
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    return arr;
}

int Utils::getPositiveIntFromUser(const std::string &prompt)
{
    int value;
    do
    {
        std::cout << prompt;
        std::cin >> value;
        if (value <= 0)
        {
            std::cout << "Please enter a positive number." << std::endl;
        }
    } while (value <= 0);

    return value;
}

void Utils::printSeparator(char c, int length)
{
    for (int i = 0; i < length; ++i)
    {
        std::cout << c;
    }
    std::cout << std::endl;
}

void Utils::printHeader(const std::string &title)
{
    printSeparator('=', 60);
    std::cout << std::setw(30 + title.length() / 2) << title << std::endl;
    printSeparator('=', 60);
}

void Utils::printComplexity(const std::string &algorithm, const std::string &timeComplexity, const std::string &spaceComplexity)
{
    setColor(YELLOW);
    std::cout << "\n--- Complexity Analysis ---" << std::endl;
    resetColor();
    setColor(LIGHT_CYAN);
    std::cout << "Algorithm: " << algorithm << std::endl;
    std::cout << "Time Complexity: " << timeComplexity << std::endl;
    std::cout << "Space Complexity: " << spaceComplexity << std::endl;
    resetColor();
    printSeparator('-', 30);
}

void Utils::pauseConsole()
{
    std::cout << "\nPress any key to continue...";
    _getch();
    std::cout << std::endl;
}

void Utils::clearConsole()
{
    system("cls");
}

void Utils::setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void Utils::resetColor()
{
    setColor(LIGHT_GRAY);
}