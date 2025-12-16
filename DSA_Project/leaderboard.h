#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "utils.h"

using namespace std;

struct LeaderboardEntry {
    string name;
    int score;
    string date;
};

void showTournamentLeaderboard() {
    clearScreen();
    cout << "\n";
    cout << "           TOURNAMENT LEADERBOARD - ALL TIME               \n";
    cout << "\n\n";
    
    ifstream file("data/tournament_results.txt");
    if (!file.is_open()) {
        cout << "No tournament data available yet.\n";
        cout << "Complete a tournament to see results here!\n";
        return;
    }
    
    string line;
    int count = 0;
    cout << "Recent Tournament Champions:\n";
    cout << "\n";
    
    while (getline(file, line)) {
        if (line.find("CHAMPION:") != string::npos) {
            count++;
            cout << count << ". " << line << "\n";
            if (count >= 10) break;  // Show top 10
        }
    }
    
    file.close();
    
    if (count == 0) {
        cout << "No champions recorded yet!\n";
    }
}
void showAlgorithmStats() {
    clearScreen();
    ;
    cout << "          ALGORITHM PERFORMANCE STATISTICS                  \n";
    cout << "\n\n";
    
    vector<LeaderboardEntry> entries;
    
    ifstream file("data/leaderboard.txt");
    if (!file.is_open()) {
        cout << "No algorithm performance data available yet.\n";
        return;
    }
    
    string line;
    while (getline(file, line)) {
        // Parse CSV: algorithm,score,date
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        
        if (pos1 != string::npos && pos2 != string::npos) {
            LeaderboardEntry entry;
            entry.name = line.substr(0, pos1);
            entry.score = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
            entry.date = line.substr(pos2 + 1);
            entries.push_back(entry);
        }
    }
    file.close();
// DSA Application: Sort by score (descending)
    sort(entries.begin(), entries.end(),
        [](const LeaderboardEntry& a, const LeaderboardEntry& b) {
            return a.score > b.score;
        });
    if (entries.empty()) {
        cout << "No performance records found!\n";
        return;
    }
    cout << left << setw(6) << "Rank" << setw(30) << "Algorithm" 
         << setw(10) << "Score" << "Date\n";
    cout << "------------------------------------------------------------\n";
    
    for (size_t i = 0; i < min(entries.size(), size_t(15)); i++) {
        cout << left << setw(6) << (i+1)
             << setw(30) << entries[i].name
             << setw(10) << entries[i].score
             << entries[i].date;
    }
    
    cout << "\nTotal Battles: " << entries.size() << "\n";
}

#endif // LEADERBOARD_H
    
    if (entries.empty()) {
        cout << "No performance records found!\n";
        return;
    }
