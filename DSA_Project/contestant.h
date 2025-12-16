// contestant.h - Contestant Class
// Demonstrates: Object-Oriented Design, Data Encapsulation

#ifndef CONTESTANT_H
#define CONTESTANT_H

#include <string>
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

class Contestant {
private:
    string id;
    string name;
    int totalScore;
    int finaleScore;
    int finalScore;
    vector<int> roundScores;  // DSA: Dynamic array for score tracking
    
public:
    Contestant(string contestantID, string contestantName) {
        id = contestantID;
        name = contestantName;
        totalScore = 0;
        finaleScore = 0;
        finalScore = 0;
    }
    
    // Getters
    string getID() const { return id; }
    string getName() const { return name; }
    int getTotalScore() const { return totalScore; }
    int getFinaleScore() const { return finaleScore; }
    int getFinalScore() const { return finalScore; }
    
    double getAverageScore() const {
        if (roundScores.empty()) return 0.0;
        // DSA: Accumulation algorithm
        return static_cast<double>(totalScore) / roundScores.size();
    }
    
    // Setters
    void addRoundScore(int score) {
        roundScores.push_back(score);  // DSA: Vector push_back O(1) amortized
        totalScore += score;
    }
    
    void addFinaleScore(int score) {
        finaleScore += score;
    }
    
    void calculateFinalScore() {
        finalScore = totalScore + finaleScore;
    }
    
    // Display contestant info
    void displayInfo() const {
        cout << "ID: " << id << "\n";
        cout << "Name: " << name << "\n";
        cout << "Total Score: " << totalScore << "\n";
        cout << "Rounds Played: " << roundScores.size() << "\n";
        cout << "Average Score: " << getAverageScore() << "\n";
    }
};

#endif // CONTESTANT_H