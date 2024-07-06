
// THIS FILE IS TO CONTAIN DIFFRENT APPROUCHES IN C++ PROGRAMMING TO EFFICIENTLY HANDLE DIFFRENT PROBLEMS 





/*---------------------EXAMPLE CODE FOR MULTIPLE ARGUMENTS IN C++ -----------------------*/


/*<-------- FIRST METHOD -------->*/
//  The  method  uses  variadic  templates  and  fold  expressions  to  check if multiple values
//  are all equal. Variadic templates allow functions to accept an arbitrary number of arguments. 
//  Fold expressions, introduced in C++17, provide a way to apply a binary operator to a parameter pack.

// Base Case Function:
// This function handles the case when there is only one argument left.
template<typename T>
    bool allEqual(const T&) {
        return true;
    }

// Recursive Function:
// This function handles multiple arguments by comparing the first argument with all others.
template<typename T, typename ...Args>
bool allEqual(const T& first, const Args&... args) {
    return ((first == args) && ...);
}


/*<-------- SECOND METHOD -------->*/

// std::all_of is a standard algorithm in the C++ Standard Library, defined in the <algorithm> header. 
// It is used to check if all elements in a range satisfy a given predicate(boolean function).

template<typename T>
bool allEqual(std::initializer_list<T> values) {
    if (values.size() < 2) return true; // All values are trivially equal if the list is empty or has one element
    auto first = *values.begin();
    return std::all_of(values.begin(), values.end(), [first](const T& value) { return value == first; });
}




/*---------------------EXAMPLE OF SIMILAR FUNCTION AS map() in JS FOR C++ -----------------------*/

// std::transform is used to apply a function to a range of elements and store the result in another range. 
// It comes in two variants: one for applying a unary operation and one for a binary operation.

#include <algorithm>
#include <iostream>
#include <vector>

// Function to double a number
int doubleNumber(int n) {
    return n * 2;
}

int main() {
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> output(input.size());

    // Apply the doubleNumber function to each element in the input vector
    std::transform(input.begin(), input.end(), output.begin(), doubleNumber);

    // Print the transformed elements
    for (int n : output) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
