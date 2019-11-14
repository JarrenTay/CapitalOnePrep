// Given
class Node {
public:
    int value;
    Node* next;
};

// My thought process was:
// I need to loop through these digits, both at a time. What will my loop condition look like.
// Once I get the numbers from the nodes, how do I add them together and put them into a linked list.
// How do I account for the carry for the addition.
// How do I account for running out of numbers in one list.
// What happens if I run out of numbers for both lists.
// What happens if I run out of numbers for lists and still have a carry.
// Am I done?
// I don't know if the code works lol.

// The code below was not written in the order that you see it. It was wriiten in the order

// Comments are only for you to understand code. 
// Don't need to comment in interview. Talk about it instead.
Node* addTwoLinkedList(Node* num1, Node* num2) {
    // num1 and num2 are reversed.
    // for example:
    // num1 -> 5 -> 3 -> 7. num1 represents 735
    // num2 -> 2 -> 5 -> 1. num2 represents 152
    // function should return 7 -> 8 -> 8

    Node * num1Pointer = num1; // Our pointer for traversing num1
    Node * num2Pointer = num2; // Our pointer for traversing num2
    Node * retNode = NULL;
    Node * tempPtr;
    int addedDigit = 0; // The sum of a digit from num1 and digit from num2
    int num1Dig;
    int num2Dig;
    while (num1Pointer != NULL && num2Pointer != NULL) {

        // Only check for digits if pointer is not null.
        if (num1Pointer != NULL) {
            num1Dig = num1Pointer->value;
            num1Pointer = num1Pointer->next;
        } else {
            num1Dig = 0;
        }

        if (num2Pointer != NULL) {
            num2Dig = num2Pointer->value;
            num2Pointer = num2Pointer->next;
        } else {
            num2Dig = 0;
        }

        // addedDigit is the carry from last time. Initially, its zero.
        addedDigit = addedDigit + num1Dig + num2Dig;
        if (retNode == NULL) {
            tempPtr = new Node;
            tempPtr->next = NULL;
            retNode = tempPtr;
        } else {
            tempPtr->next = new Node;
            tempPtr = tempPtr->next;
            tempPtr->next = NULL;
        }
        tempPtr->value = addedDigit % 10;        

        // Do carry
        // Remove units digit from addedDigit. Left with tens place.
        // Integer divide by ten to move tens digit to ones digit.
        addedDigit = (addedDigit - tempPtr->value) / 10;
    }
    // Check if there's a carry we need to account for
    if (addedDigit != 0) {
        tempPtr->next = new Node;
        tempPtr = tempPtr->next;
        tempPtr->next = NULL;
        tempPtr->value = addedDigit;
    }
    return retNode;
}