#pragma once

#include "FlowerNode.h"
#include "assertions.h"

#define COLOR_RED "\033[31m"
#define COLOR_DEFAULT "\033[0m"

std::ostream & _print_list(
    std::ostream & o,
    FlowerNode* head,
    const std::vector<double>& expected,
    size_t wrong_idx
) {
    o << "  Expected List: ";

    size_t curr_idx = 0;

    for (const double& expected_color : expected) {
        if (curr_idx == wrong_idx) {
            o << COLOR_RED;
        }

        if (expected_color < 10) {
            o << " ";
        }
        if (expected_color < 100) {
            o << " ";
        }
            
        o << expected_color << "" << COLOR_DEFAULT << " ";

        curr_idx++;
    }

    o << std::endl;

    curr_idx = 0;

    o << "    Actual List: ";

    while (head != nullptr) {
        if (curr_idx == wrong_idx) {
            o << "\033[31m";
        }

        if (head->color < 10) {
            o << " ";
        }
        if (head->color < 100) {
            o << " ";
        }
            
        o << head->color  << "" << COLOR_DEFAULT << " ";

        curr_idx++;
        head = head->next();
    }

    return o << std::endl;
}

std::ostream & _assert_correct_list(
    std::ostream & o,
    FlowerNode* head,
    const std::vector<double>& expected
) {
    FlowerNode* curr = head;
    size_t count = 0;
    auto curr_expected = expected.begin();

    while (curr != nullptr && curr_expected != expected.end()) {
        if (curr->color != *curr_expected) {
            o << "Color Mismatch" << std::endl 
              << "  Expected: " << *curr_expected << std::endl 
              << "    Actual: " << curr->color << std::endl << std::endl;
            return _print_list(o, head, expected, count);
        }

        curr = curr->next();
        ++curr_expected;
        ++count;
    }

    // At this point curr should be at nullptr
    if (curr != nullptr) {
        o << "Returned list has too many nodes" << std::endl
          << "  Expected: " << expected.size() << std::endl
          << "    Actual: " << count << std::endl << std::endl;
        return _print_list(o, head, expected, count);
    }

    // And curr_expected should be at expected.end()
    if (curr_expected != expected.end()) {
        o << "Returned list has too few nodes" << std::endl
          << "  Expected: " << expected.size() << std::endl
          << "    Actual: " << count << std::endl << std::endl;
        return _print_list(o, head, expected, count);
    }

    return o;
}

#define ASSERT_CORRECT_LIST(list_head, expected_vector) \
    MK_ASSERT(_assert_correct_list, list_head, expected_vector)
