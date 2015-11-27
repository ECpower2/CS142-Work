#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    std::cout << "Testing default constructor\n";
    Queue<int> q;
    std::cout << "Size of default queue: " << q.size() << "\n";

    std::cout << "Is queue empty? ";
    if ( q.empty() ) std::cout << "Yes\n";
    else std::cout << "No\n";

    q.push(1);

    std::cout << q.front_of();

    return 0;
    }
