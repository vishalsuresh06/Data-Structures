#pragma once

#include "executable.h"

#include <vector>
#include <algorithm>

////////////////////////////////////////////////////////////////////////////////
// THESE ARE USED FOR THE TEST CASES AND ARE NOT MEANT TO BE USED BY STUDENTS //
////////////////////////////////////////////////////////////////////////////////

// Tail recursion utility function for creating randomized linked lists
FlowerNode* buildLinkedList(size_t size, Typegen& t, std::vector<double>* output = nullptr) {
    if (size == 0) {
        return nullptr;
    } else {
        double r_color = t.range<double>(0, 100);

        // Although we want to generate a proper linked list for them to traverse, the output and expected list values
        // will be different - we should account for this
        if (output && size != 1) {
            output->push_back(r_color);
            output->push_back(-1); // to be calculated later on in expected
        }
        else if (output) {
            output->push_back(r_color);
        }

        FlowerNode* head = new FlowerNode(r_color, buildLinkedList(size - 1, t, output));

        return head;
    }
}

// Reverses a given vector
void reverseVector(std::vector<double>& v) {
    std::reverse(v.begin(), v.end());
}

// Utility function for clearing a linked list (cleanup)
void clearList(FlowerNode* head) {
    FlowerNode* toDelete = head;

    while (head != nullptr) {
        head = head->next();
        delete toDelete;
        toDelete = head;
    }
}
