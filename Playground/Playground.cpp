#include <stdio.h>
#include <functional>
#include <vector>


typedef int keycode;
typedef std::function<void()> eventfn;


struct KeySubscribtion {
    keycode code;
    eventfn func;
};

void t_f() {
    printf("test");
}


class Events {
    static std::vector<KeySubscribtion> subscribersKeyDown;
    static std::vector<KeySubscribtion> subscribersKeyUp;
public:
    static void f() {
        Events::subscribersKeyDown.push_back(KeySubscribtion(12, t_f));

        for (auto ev = subscribersKeyDown.begin(); ev != subscribersKeyDown.end(); ++ev) {
            printf("Num: %d", (*ev).code);
            (*ev).func();
        }
    }
};

std::vector<KeySubscribtion> Events::subscribersKeyDown = std::vector<KeySubscribtion>();
std::vector<KeySubscribtion> Events::subscribersKeyUp = std::vector<KeySubscribtion>();

int main() {
    Events::f();
}