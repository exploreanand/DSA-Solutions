THIS REPOSITORY IS WHERE I PUSH MY LEETCODE DSA SOLUTIONS, WHILE FOLLOWING STRIVER A2Z DSA SHEET<br>
AUTHOR "ABHINAV ANAND"

Revise:
Questions: 987, 653


STL syntax:
1.

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};

    // Erase the 3rd element (index 2, which is 30)
    // vec.begin() points to the first element
    vec.erase(vec.begin() + 2); 

    // Resulting vector: {10, 20, 40, 50}
}


2.

#include <iostream>
#include <utility> // Required for std::pair

int main() {
    std::pair<int, int> p = {45, 78};

    std::cout << p.first;  // Prints 45
    std::cout << p.second; // Prints 78
}

3.
