#include "executable.h"
#include <vector>

TEST(answer) {
    Typegen t;

    for (size_t i = 0; i < 20; i++) {
        // Generated data points
        std::vector<double> expected;

        size_t size = t.range<size_t>(0, 30);

        // Generate the "bench" linked list for the student's code to traverse
        FlowerNode* bench_head = buildLinkedList(size, t, &expected);

        // Our answer is effectively performing push_front, so expected should be reversed
        reverseVector(expected);

        // Update -1's in expected
        for (size_t i = 1; i < expected.size(); i += 2) {
            expected[i] = (expected[i - 1] + expected[i + 1]) / 2;
        }

        // Generate the "caterpillar" linked list for the validation to traverse
        FlowerNode* caterpillar_head = hungryCaterpillar(bench_head);
        
        // Verify the list they returned is correct, for both the values and the ordering
        ASSERT_CORRECT_LIST(caterpillar_head, expected);

        // Cleanup
        clearList(bench_head);
        clearList(caterpillar_head);
    }
}
