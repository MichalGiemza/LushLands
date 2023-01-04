#include "Playground.h"
#include <iostream>
#include <unordered_set>


int main() {
    std::unordered_set<int> us = {1, 2, 3, 4, 5, 6, 7, 8};
    
    for (auto i = us.begin(); i != us.end(); ++i++) {
        printf("%i, ", *i);
    }
}
