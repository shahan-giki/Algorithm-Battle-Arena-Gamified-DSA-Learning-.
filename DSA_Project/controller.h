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
