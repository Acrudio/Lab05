//
// Created by ryans on 10/11/2023.
//
#include <iostream>
#include "StringData.h"
using std::vector;
using std::string;
using std::cout;

int linear_search(vector<string>* container, string element) {
    for(int i = 0; i < container->size(); i++){
        if (container->at(i) == element){
            return i;
        }
    }
    return -1;
}

int binary_search(vector<string>* container, string element) {
    int upper_bound = container->size();
    int lower_bound = -1;
    int current_pos = (upper_bound + lower_bound) / 2;
    while (true){
        if (container->at(current_pos) == element){
            return current_pos;
        }
        if (container->at(current_pos) > element){
            upper_bound = current_pos;
            current_pos = (upper_bound + lower_bound)/2;
        }
        if (container->at(current_pos) < element){
            lower_bound = current_pos;
            current_pos = (upper_bound + lower_bound)/2;
        }
        if (upper_bound-lower_bound < 2) {
            return -1;
        }
    }
}

int main(){
    vector<string> data = getStringData();
    long long t1 = systemTimeNanoseconds();
    int response = linear_search(&data, string("not_here"));
    long long t2 = systemTimeNanoseconds();
    cout << "Linear search for not_here returned: " << response << ", and took: " << (t2-t1) << " Nanoseconds\n";
    t1 = systemTimeNanoseconds();
    response = binary_search(&data, string("not_here"));
    t2 = systemTimeNanoseconds();
    cout << "Binary search for not_here returned: " << response << ", and took: " << (t2-t1) << " Nanoseconds\n";
    t1 = systemTimeNanoseconds();
    response = linear_search(&data, string("mzzzz"));
    t2 = systemTimeNanoseconds();
    cout << "Linear search for mzzzz returned: " << response << ", and took: " << (t2-t1) << " Nanoseconds\n";
    t1 = systemTimeNanoseconds();
    response = binary_search(&data, string("mzzzz"));
    t2 = systemTimeNanoseconds();
    cout << "Binary search for mzzzz returned: " << response << ", and took: " << (t2-t1) << " Nanoseconds\n";
    t1 = systemTimeNanoseconds();
    response = linear_search(&data, string("aaaaa"));
    t2 = systemTimeNanoseconds();
    cout << "Linear search for aaaaa returned: " << response << ", and took: " << (t2-t1) << " Nanoseconds\n";
    t1 = systemTimeNanoseconds();
    response = binary_search(&data, string("aaaaa"));
    t2 = systemTimeNanoseconds();
    cout << "Binary search for aaaaa returned: " << response << ", and took: " << (t2-t1) << " Nanoseconds\n";
    return 0;
}