#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
#include <algorithm>
#include "utils.h"

using namespace std;
using namespace chrono;

class Controller {
private:
    struct AlgorithmResult {
        string name;
        double executionTime;
        int score;
        bool success;
    };
vector<AlgorithmResult> results;
    
    int calculateScore(double executionTime, int maxTime = 1000) {
        // DSA Application: Linear scoring formula
        // Faster execution = higher score
        if (executionTime >= maxTime) return 10;
        
        int score = 100 - static_cast<int>((executionTime / maxTime) * 90);
        return max(10, min(100, score));
    }

    double measureExecutionTime(string category, int algorithmChoice) {
        // Simulate algorithm execution with random runtime
        // In real implementation, this would compile and run C++ files
        
        // Different base times for different algorithm complexities
        double baseTime = 0.0;
        
        if (category == "sorting") {
            // QuickSort: O(n log n), MergeSort: O(n log n), BubbleSort: O(n²)
            vector<double> sortingTimes = {50.0, 55.0, 200.0};  // ms
            baseTime = sortingTimes[algorithmChoice % 3];
        }
        else if (category == "graph") {
            // BFS: O(V+E), DFS: O(V+E)
            vector<double> graphTimes = {80.0, 75.0};
            baseTime = graphTimes[algorithmChoice % 2];
        }
        else if (category == "linkedlist") {
            // Reverse, Cycle Detection, Middle Element
            vector<double> listTimes = {40.0, 60.0, 45.0};
            baseTime = listTimes[algorithmChoice % 3];
        }
        else if (category == "hashing") {
            // Frequency Count, Unique Elements
            vector<double> hashTimes = {30.0, 35.0};
            baseTime = hashTimes[algorithmChoice % 2];
        }
        else if (category == "stack_queue") {
            // Balanced Parentheses, Queue Ops
            vector<double> stackTimes = {25.0, 30.0};
            baseTime = stackTimes[algorithmChoice % 2];
        }
        
        // Add randomness to simulate real execution variance
        double variance = (rand() % 40 - 20) / 100.0;  // ±20%
        return baseTime * (1.0 + variance);
    }
public:
    Controller() {
        srand(time(nullptr));
    }
    
    void runQuickBattle(int category) {
        clearScreen();
        cout << "============================================================\n";
        cout << "                   QUICK BATTLE ARENA                       \n";
        cout << "============================================================\n";
        
        string categoryName;
        vector<string> algorithms;
        
        switch(category) {
            case 1:
                categoryName = "sorting";
                algorithms = {"QuickSort", "MergeSort", "BubbleSort"};
                break;
            case 2:
                categoryName = "graph";
                algorithms = {"BFS Traversal", "DFS Traversal"};
                break;
            case 3:
                categoryName = "linkedlist";
                algorithms = {"Reverse (Iterative)", "Reverse (Recursive)", "Cycle Detection"};
                break;
            case 4:
                categoryName = "hashing";
                algorithms = {"Frequency Counter", "Unique Elements Finder"};
                break;
            case 5:
                categoryName = "stack_queue";
                algorithms = {"Balanced Parentheses", "Queue Operations"};
                break;
            default:
                cout << "Invalid category!\n";
                return;
        }
        
        cout << "\nCategory: " << categoryName << "\n";
        cout << "Algorithms competing:\n";
        for (size_t i = 0; i < algorithms.size(); i++) {
            cout << "  " << (i+1) << ". " << algorithms[i] << "\n";
        }
        cout << "\n";
        
        cout << "Generating test cases...\n";
        sleep_ms(500);
        cout << "Test size: 10,000 elements\n";
        cout << "\nStarting battle...\n";
        cout << "============================================================\n";
        
        results.clear();
        
        for (size_t i = 0; i < algorithms.size(); i++) {
            cout << "\n-> Running " << algorithms[i] << "...\n";
            sleep_ms(300);
            
            double execTime = measureExecutionTime(categoryName, i);
            int score = calculateScore(execTime);
            
            AlgorithmResult result = {algorithms[i], execTime, score, true};
            results.push_back(result);
            
            cout << "  Execution Time: " << execTime << " ms\n";
            cout << "  Score: " << score << " / 100\n";
        }
cout << "\n============================================================\n";
        cout << "                    BATTLE RESULTS\n";
        cout << "============================================================\n";
        
        // DSA Application: Finding maximum score
        auto winner = max_element(results.begin(), results.end(),
            [](const AlgorithmResult& a, const AlgorithmResult& b) {
                return a.score < b.score;
            });
        
        cout << "\n*** WINNER: " << winner->name << " ***\n";
        cout << "   Score: " << winner->score << " / 100\n";
        cout << "   Time: " << winner->executionTime << " ms\n";
        
        cout << "\nComplete Rankings:\n";
        // Sort by score descending
        sort(results.begin(), results.end(),
            [](const AlgorithmResult& a, const AlgorithmResult& b) {
                return a.score > b.score;
            });
        
        for (size_t i = 0; i < results.size(); i++) {
            cout << "  " << (i+1) << ". " << results[i].name 
                 << " - " << results[i].score << " pts (" 
                 << results[i].executionTime << " ms)\n";
        }
        
        cout << "============================================================\n";
        
        // Save to leaderboard
        saveToLeaderboard(winner->name, winner->score);
    }
    
    int runAlgorithmForContestant(string category, int contestantNum) {
        // Simulate running an algorithm for a contestant
        double execTime = measureExecutionTime(category, contestantNum);
        return calculateScore(execTime);
    }
    
    void saveToLeaderboard(string algorithm, int score) {
        ofstream file("data/leaderboard.txt", ios::app);
        if (file.is_open()) {
            time_t now = time(nullptr);
            file << algorithm << "," << score << "," << ctime(&now);
            file.close();
        }
    }
};

#endif // CONTROLLER_H
