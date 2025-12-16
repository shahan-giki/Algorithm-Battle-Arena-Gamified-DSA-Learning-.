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
