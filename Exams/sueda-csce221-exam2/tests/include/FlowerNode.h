#pragma once

#include "Monitor.h"
#include "typegen.h"
#include <vector>

// Makes something like FlowerNode->next work as intended, (next is a pointer to function that returns a reference)

class FlowerNode {
    private:
        FlowerNode* _next;

    public:
        double color;

        // Parameterized Constructor
        FlowerNode(double c=-1, FlowerNode* n=nullptr) : _next{n}, color{c} {}

        // Copy Constructor (just steals the color value)
        FlowerNode(const FlowerNode& other, FlowerNode* n=nullptr) : _next{n}, color{other.color} {
            if (n) {
                Monitor::update_next();
            }
        }

        // Gives the pointer to the "next" node in the list.
        // This will return a reference, so you can modify it as ListNode->next = ...
        FlowerNode*& next() {
            Monitor::update_next();
            return _next;
        }
};