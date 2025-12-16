// main.cpp - Algorithm Battle Arena Tournament System
// Entry Point

#include <iostream>
#include <string>
#include "menu.h"
#include "utils.h"

using namespace std;

void displayWelcomeBanner() {
    clearScreen();
    cout << "============================================================\n";
    cout << "                                                              \n";
    cout << "         ALGORITHM BATTLE ARENA TOURNAMENT SYSTEM             \n";
    cout << "                                                              \n";
    cout << "           DSA Competition & Learning Platform                \n";
    cout << "                                                              \n";
    cout << "============================================================\n";
    cout << "\n";
    cout << "Welcome to the ultimate Data Structures & Algorithms competition!\n";
    cout << "\nThis system demonstrates:\n";
    cout << "  - Sorting Algorithms (QuickSort, MergeSort, BubbleSort)\n";
    cout << "  - Graph Algorithms (BFS, DFS, Dijkstra)\n";
    cout << "  - Linked List Operations (Reverse, Cycle Detection)\n";
    cout << "  - Hashing Applications (Frequency Count, Unique Elements)\n";
    cout << "  - Stack/Queue Operations (Balanced Parentheses)\n";
    cout << "\nTournament Features:\n";
    cout << "  * 10-Round Competition\n";
    cout << "  * Multiple DSA Categories\n";
    cout << "  * Real-time Performance Scoring\n";
    cout << "  * Top 3 Finale Championship\n";
    cout << "  * Comprehensive Leaderboard\n";
    cout << "\n";
    pauseScreen();
}

int main() {
    try {
        displayWelcomeBanner();
        
        // Initialize system
        if (!initializeSystem()) {
            cerr << "Error: Failed to initialize system!\n";
            return 1;
        }
        
        // Launch main menu
        mainMenu();
        
        cout << "\n============================================================\n";
        cout << "  Thank you for using Algorithm Battle Arena!               \n";
        cout << "  Keep practicing DSA!                                    \n";
        cout << "============================================================\n";
        
    } catch (const exception& e) {
        cerr << "Fatal Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}

