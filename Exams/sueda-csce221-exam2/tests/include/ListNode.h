// #pragma once

// #include "Monitor.h"
// #include "typegen.h"
// #include <vector>

// // Makes something like ListNode->next work as intended, (next is a pointer to function that returns a reference)
// #define next next_()

// class ListNode {
//     private:
//         // Not truly "private", 
//         ListNode* _next;
//     public:
//         double color;
//         bool isFlower;

//         // Parameterized Constructor
//         ListNode(double c, bool f=true, ListNode* n=nullptr) : color{c}, isFlower{f}, _next{n} {}

//         // Copy Constructor (provides deep copy)
//         ListNode(const ListNode& other) : color{other.color}, isFlower{other.isFlower}, _next{other._next} {
//             // We must update_next as it is technically called here. And we want a copy, not a reference
//             Monitor::update_next();
//         }

//         // Gives the pointer to the "next" node in the list.
//         // This will return a reference, so you can modify it as ListNode->next = ...
//         ListNode*& next_() {
//             Monitor::update_next();
//             return _next;
//         }
// };