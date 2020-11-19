#include "pack.h"

Pack::Pack()
{

}

void Pack::onGame() {
    timer = 6;
    int test;
    counter= clock() + 1*CLOCKS_PER_SEC;
    while (timer != 0) {
        if (clock() > counter) {
            timer--;
            cout << timer << endl;
            counter = clock() + 1*CLOCKS_PER_SEC;
        }
        test = rand() % 2;
        if (timer < 3) {
            if (test == 0) {
                return;
            }
        }
    }
}
