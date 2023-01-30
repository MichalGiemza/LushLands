#include "Playground.h"
#include <iostream>
#include <unordered_set>
#include <sstream>
#include <typeinfo>

using namespace std;

int main() {
    for (double i = 0; i < 100; i++) {
        printf("Val: %f\n", Random_::random(0.0f, 2*PI));
    }
    return 0;
}
