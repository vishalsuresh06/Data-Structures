#pragma once

#include <iostream>
#include <utility>
#include "FlowerNode.h"

/*
    Given the head of a singly-linked list representing the bench of flowers (FlowerNodes), write a function
    that will traverse this bench starting inclusively at "benchHead". You should then construct a new singly
    linked list according to the order described below.

    "caterpillarHead" is a sentinel node; it does not store a meaningful value, and it exists so you can insert to
    the right of "caterpillarHead" as you traverse through the list suggested by "benchHead". The bench's head "benchHead", however,
    is not a sentinel node - you should include its color in your traversal.

    1) First flower found in the "bench" linked list
        - Construct a new FlowerNode containing the same color as the current (first) flower in bench.
        - Insert (connect) this node to the right of caterpillarHead.

    2) After the first flower has been added
        - Construct a new FlowerNode containing the "halfway" transitional color between the current flower at bench, and
          the previous flower consumed.
                -- The halfway color is the average of the two colors, calculated as
                   (prevFlower->color + currFlower->color) / 2

        - Insert (connect) this halfway node to the right of caterpillarHead.
        - Insert (connect) a new FlowerNode containing the same value as the current flower in bench.

    For example, if the benchHead is: "0.25 ➡ 0.75", the caterpillar should grow as follows:
    caterpillarHead
    caterpillarHead ➡ 0.25 // (first node in benchHead)
    caterpillarHead ➡ 0.75 ➡ 0.5 ➡ 0.25 // ((0.75 + 0.25) / 2) == 0.5

    PLEASE IMPLEMENT THIS ITERATIVELY, DO NOT USE RECURSION
    
    For the definition of FlowerNode, assume the following structure:

    class FlowerNode {
        private:
        FlowerNode* _next; // <- ACCESSIBLE WITH "next()"

        public:
        double color;

        // Parameterized constructor
        FlowerNode(double color=-1, FlowerNode* next=nullptr) : color{color}, next{next} {}

        // Copy constructor, creates a FlowerNode with the same color as another FlowerNode, i.e.) FlowerNode(6.3, prevFlower);
        FlowerNode(const FlowerNode& other, next=nullptr) : color{other.color}, next{next} {}
        
        // Next function, returns a reference to the pointer stored at _next member
        FlowerNode*& next() {
            return _next;
        }
    };
*/

FlowerNode* hungryCaterpillar(FlowerNode* benchHead) {
    // DO NOT MODIFY
    FlowerNode dummy = FlowerNode(-1, nullptr);
    FlowerNode* caterpillarHead = &dummy;

    // TODO: Implement (note: USE next(), next is a private member. i.e.) benchHead->next())

    caterpillarHead->next() = new FlowerNode(benchHead->color); //Create new head
    while (benchHead->next() != nullptr) {//While next is not available
        benchHead = benchHead->next(); //Set next color
        caterpillarHead->next() = new FlowerNode((caterpillarHead->next()->color + benchHead->color)/2, caterpillarHead->next()); //Create new node with old head node.next color + new color avg and point to old head.next
        caterpillarHead->next() = new FlowerNode(benchHead->color, caterpillarHead->next()); //make new node and point to old head.next;
    }
    // DO NOT MODIFY, RETURN THE FIRST ACTUAL ELEMENT
    return caterpillarHead->next();
}