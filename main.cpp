#include <iostream>
#include "Worker.h"

int main() {
    srand(time(0));
    Worker work(3);
    work.run(15);
    return 0;
}
