//
// Created by acrud on 10/11/2023.
//
// Partner is Ryan Spaker

#include <iostream>
#include "StringData.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Linear Search
int LinearSearch(vector<string> container, string element){
    long long time_start = systemTimeNanoseconds(); // start time
    int found_index = -1;

    // Search
    for (int i = 0; i < container.size(); i++){
        if(container.at(i) == element){
            found_index = i;
            break;
        }
    }

    long long timeTaken = systemTimeNanoseconds() - time_start;// record time
    cout << "Linear Search of \"" << element << "\" took " << timeTaken << " nanoseconds ";

    return found_index;
}

// Binary Search
int BinarySearch(vector<string> container, string element){
    long long timeStart = systemTimeNanoseconds(); // start time
    int found_index = -1;

    sort(container.begin(), container.end());

    int botBound = 0;
    int topBound = int(container.size()) - 1;
    int i = 0;

    while (topBound - botBound >= 0){
        i = (topBound + botBound) / 2;

        if (container.at(i) == element){
            found_index = i;
            break;
        }
        // if element in upper half
        else if (element > container.at(i)){
            botBound = i + 1;
        }
        // if element in lower half
        else {
            topBound = i - 1;
        }
    }

    int timeTaken = systemTimeNanoseconds() - timeStart; // record time
    cout << "Binary Search of \"" << element << "\" took " << timeTaken << " nanoseconds " ;
    return found_index;
}

int main(){
    vector<string> data = getStringData();
    cout << "Start\n\n";

    cout << BinarySearch(data, "not_here") << "\n";
    cout << LinearSearch(data, "not_here") << "\n";
    cout << BinarySearch(data, "mzzzz") << "\n";
    cout << LinearSearch(data, "mzzzz") << "\n";
    cout << BinarySearch(data, "aaaaa") << "\n";
    cout << LinearSearch(data, "aaaaa") << "\n";

    return 0;
}