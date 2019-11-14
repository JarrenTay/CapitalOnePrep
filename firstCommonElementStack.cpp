// Given
class Stack {
public:
    void push(int input);
    int pop();
};

/* Example Stack
-Top-
3
4
6
4
7
7
2
-Bottom-
*/

// Clarification questions
// Can you pop an empty stack? No, the stack is infinite.
// If we use the example stack, should it return 4 or 7? (First common element from top) vs (First common element from bottom?)
//   It should return 4.

// Thought process
// We need to find duplicates of numbers, so we need to keep track of what numbers we have seen before
// Which data structure is good at storing unique numbers and fast lookup?
// Its a map or a set.
// How will I use the map or set, and which one is better for this case?
// What happens when I find the duplicate?

#include <map>
#include <set>
int firstCommonElementStack(Stack inStack) {
    // We are going to use a map or set to store the occurrence of each number.
    // This is better than storing each occurrence in a vector and searching because a map and set will have faster lookup times.
    // O(1) for map and set lookup vs O(N) for searching through a vector.
    // This is important because we will be doing lookups in our data structure a lot.

    // You can use either a map or a set in this case. Set is the better answer, but if you can't remember it, you can use a map.
    // If we use map
    // the first int will be for numbers we have found.
    // the second is not necessary. For a slightly different problem, this second value may be useful. For example, if the question was to count the occurrences of each number, the second value could store that.
    std::map<int, int> foundNumsMap;
    int nextNum;

    while (true) {
        nextNum = inStack.pop();
        if (foundNumsMap.find(nextNum) == foundNumsMap.end()) {
            // We did not find the number
            foundNumsMap[nextNum] = 0;
        } else {
            return nextNum;
        }
    }

    // If we use set
    // We don't have to worry about the second number. We will just check to see if a new number is in the set.
    std::set<int> foundNumsSet;
    int nextNum2;

    while (true) {
        nextNum2 = inStack.pop();
        if (foundNumsSet.find(nextNum2) == foundNumsSet.end()) {
            // We did not find the number
            foundNumsSet.insert(nextNum2);
        } else {
            return nextNum2;
        }
    }
}