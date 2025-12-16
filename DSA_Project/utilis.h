#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>

#ifdef _WIN32
#include <windows.h>
#define CLEAR_COMMAND "cls"
#else
#include <unistd.h>
#define CLEAR_COMMAND "clear"
#endif

using namespace std;

void clearScreen() {
    system(CLEAR_COMMAND);
}

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore(10000, '\n');
    cin.get();
}

void sleep_ms(int milliseconds) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

bool initializeSystem() {
    #ifdef _WIN32
    system("if not exist data mkdir data");
    #else
    system("mkdir -p data");
    #endif
    
    ofstream leaderboard("data/leaderboard.txt", ios::app);
    ofstream contestants("data/contestants.txt", ios::app);
    ofstream tournament("data/tournament_results.txt", ios::app);
    
    leaderboard.close();
    contestants.close();
    tournament.close();
    
    return true;
}


#endif 
