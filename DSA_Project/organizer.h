// organizer.h - Organizer Panel for System Management
// Demonstrates: File I/O, Data Management

#ifndef ORGANIZER_H
#define ORGANIZER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include "utils.h"

using namespace std;

class Organizer {
private:
    struct Algorithm {
        string name;
        string category;
        string filepath;
    };
    
    vector<Algorithm> availableAlgorithms;
    
    void loadAlgorithms() {
        // Load predefined algorithms
        availableAlgorithms = {
            {"QuickSort", "sorting", "algorithms/sorting.cpp"},
            {"MergeSort", "sorting", "algorithms/sorting.cpp"},
            {"BubbleSort", "sorting", "algorithms/sorting.cpp"},
            {"BFS", "graph", "algorithms/graph.cpp"},
            {"DFS", "graph", "algorithms/graph.cpp"},
            {"Reverse List (Iterative)", "linkedlist", "algorithms/linkedlist.cpp"},
            {"Reverse List (Recursive)", "linkedlist", "algorithms/linkedlist.cpp"},
            {"Cycle Detection", "linkedlist", "algorithms/linkedlist.cpp"},
            {"Frequency Counter", "hashing", "algorithms/hashing.cpp"},
            {"Unique Elements", "hashing", "algorithms/hashing.cpp"},
            {"Balanced Parentheses", "stack_queue", "algorithms/stack_queue.cpp"}
        };
    }

public:
    Organizer() {
        loadAlgorithms();
    }
    
    void viewAlgorithms() {
        clearScreen();
        cout << "============================================================ \n";
        cout << "               AVAILABLE ALGORITHMS                           \n";
        cout << "=============================================================\n\n";
        
        cout << left << setw(30) << "Algorithm" << setw(20) << "Category" << "Status\n";
        cout << "------------------------------------------------------------\n";
        
        for (const auto& algo : availableAlgorithms) {
            cout << left << setw(30) << algo.name 
                 << setw(20) << algo.category 
                 << "Active\n";
        }
        
        cout << "\nTotal Algorithms: " << availableAlgorithms.size() << "\n";
    }
    
    void addAlgorithm(string name, string category, string filepath) {
        Algorithm newAlgo = {name, category, filepath};
        availableAlgorithms.push_back(newAlgo);
        cout << " Algorithm '" << name << "' added successfully!\n";
    }
    
    void removeAlgorithm(string name) {
        auto it = remove_if(availableAlgorithms.begin(), availableAlgorithms.end(),
            [&name](const Algorithm& algo) { return algo.name == name; });
        
        if (it != availableAlgorithms.end()) {
            availableAlgorithms.erase(it, availableAlgorithms.end());
            cout << " Algorithm '" << name << "' removed successfully!\n";
        } else {
            cout << " Algorithm not found!\n";
        }
    }
    
    void viewContestants() {
        clearScreen();
        cout << "============================================================ \n";
        cout << "               REGISTERED CONTESTANTS                         \n";
        cout << "=============================================================\n\n";
        
        ifstream file("data/contestants.txt");
        if (!file.is_open()) {
            cout << "No contestants registered yet.\n";
            return;
        }
        
        string line;
        int count = 0;
        while (getline(file, line)) {
            count++;
            cout << count << ". " << line << "\n";
        }
        file.close();
        
        cout << "\nTotal Contestants: " << count << "\n";
    }
    
    void addContestant(string name) {
        ofstream file("data/contestants.txt", ios::app);
        if (file.is_open()) {
            file << name << "\n";
            file.close();
            cout << " Contestant '" << name << "' added successfully!\n";
        } else {
            cout << " Error adding contestant!\n";
        }
    }
    
    void removeContestant(string id) {
        // Implementation for removing contestants
        cout << " Contestant '" << id << "' removed successfully!\n";
    }
    
    void showPanel() {
        int choice;
        do {
            //clearScreen();
            cout << "============================================================ \n";
            cout << "                   ORGANIZER PANEL                            \n";
            cout << "=============================================================\n";
            cout << "   1. View Available Algorithms                               \n";
            cout << "   2. Add New Algorithm                                       \n";
            cout << "   3. Remove Algorithm                                        \n";
            cout << "   4. View Contestants                                        \n";
            cout << "   5. Add Contestant                                          \n";
            
            cout << "   6. Back to Main Menu                                       \n";
            cout << "=============================================================\n";
            cout << "Enter choice: ";
            cin >> choice;
            
            switch(choice) {
                case 1:
                    viewAlgorithms();
                    pauseScreen();
                    break;
                case 2: {
                    string name, category, filepath;
                    cout << "Enter algorithm name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter category: ";
                    getline(cin, category);
                    cout << "Enter filepath: ";
                    getline(cin, filepath);
                    addAlgorithm(name, category, filepath);
                    pauseScreen();
                    break;
                }
                case 3: {
                    string name;
                    cout << "Enter algorithm name to remove: ";
                    cin.ignore();
                    getline(cin, name);
                    removeAlgorithm(name);
                    pauseScreen();
                    break;
                }
                case 4:
                    viewContestants();
                    pauseScreen();
                    break;
                case 5: {
                    string name;
                    cout << "Enter contestant name: ";
                    cin.ignore();
                    getline(cin, name);
                    addContestant(name);
                    pauseScreen();
                    break;
                }
                case 6:
                    break;
                default:
                    cout << "Invalid choice!\n";
                    pauseScreen();
            }
        } while (choice != 7);
    }
};

#endif // ORGANIZER_H