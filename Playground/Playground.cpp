#include <windows.h>
#include <iostream>
#include <exception>


int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    std::string s1("ABC"), s2("ABC"), s3("XY_");
    const char *c1 = "XYZ", *c3 = "XY_";
    //char c2[] = "XY?";
    //c2[2] = 'Z';
    const char *c2 = "XYZ";

    std::cout << "s1: " << s1 << "; s2: " << s2 << "; s3: " << s3 << std::endl;
    std::cout << "Str   ==: " << (s1 == s2) << "; !=: " << (s1 == s3) << std::endl;
    std::cout << "c1: " << c1 << "; c2: " << c2 << ";  c3: " << c3 << std::endl;
    std::cout << "Char* ==: " << (c1 == c2) << "; !=: " << (c1 == c3) << std::endl;
    std::cout << "c1: " << (unsigned int)c1 << "; c2: " << (unsigned int)c2 << ";  c3: " << (unsigned int)c3 << std::endl;
}