// Given
class Node {
public:
    int value;
    Node* next;
};

// Sort an array of linked lists into a single linked list

// Clarification question: Is each linked list sorted?
// My implementation assumes so, but if not how would that changed the implementation?
// In my opinion, the easiest way is to loop through all linked lists and insert all numbers
// into a vector. Then, sort the vector. It's a lot faster to sort a vector rather than a linked list (Why?)
// After the vector is sorted, add all numbers into a linked list.

// My thought process:
// Since we have an array of linked lists, we need a vector to store our position in each linked list.
// I will loop until all linked list pointers are null.
// I need to loop through all pointers to linked lists to figure out which one had the smallest number.
// I will need to add the value to my linked list and iterate the pointer at linked list that I pulled from.
// I will need to check if all linked list pointers are null.
// I will need to return the head of my linked list.

// Unless you include <array>, you can't call .size() on arrays.
#include <vector>
Node* sortArrayLinkedList (Node* sortedLists[], int numLists) {

    // Copy all pointers of the lists to a vector. 
    // This vector will hold the pointers to our progress in each linked list.
    // At the same time, make sure all linked lists are not empty
    std::vector<Node*> listPointers;
    bool allNull = true;
    for (int i = 0; i < numLists; i++) {
        listPointers[i] = sortedLists[i];
        if (listPointers[i] != NULL) {
            allNull = false;
        }
    }

    int minNumber = INT_MAX;
    int minIndex = 0;
    Node* retNode;
    Node* tempNode = NULL;

    // Repeat until all pointers are null.
    while (allNull != true) {
        // Check for the smallest number and remember which index it was
        minNumber = INT_MAX;
        minIndex = 0;
        for (int i = 0; i < numLists; i++) {
            if (listPointers[i] != NULL) {
                if (minNumber > listPointers[i]->value) {
                    // IMPORTANT, do not iterate the linked list until you are sure its the smallest one.
                    minNumber = listPointers[i]->value;
                    minIndex = i;
                }
            }
        }

        // Create the node. tempNode is null if we are in the first iteration of our loop
        if (tempNode == NULL) {
            tempNode = new Node;
            tempNode->value = minNumber;
            tempNode->next = NULL;
            retNode = tempNode;
        } else {
            tempNode->next = new Node;
            tempNode = tempNode->next;
            tempNode->value = minNumber;
            tempNode->next = NULL;
        }
        // After we have added the number, we can iterate that linked list.
        listPointers[minIndex] = listPointers[minIndex]->next;

        // After iterating the linked list, we check to see if all linked lists are null so we can leave the loop.
        allNull = true;
        for (int i = 0; i < numLists; i++) {
            if (listPointers[i] != NULL) {
                allNull = false;
            }
        }
    }

    return retNode;
}