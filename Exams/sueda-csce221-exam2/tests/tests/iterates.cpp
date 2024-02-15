#include "executable.h"
#include <unordered_set>

TEST(iterates) {
    Typegen t;

    for (size_t i = 0; i < 20; i++) {
        // Create Monitor to observe program behavior
        Monitor m;

        size_t size = t.range<size_t>(0, 30);

        // Generate a linked list (nullptr passed in)
        FlowerNode* bench_head = buildLinkedList(size, t);

        // We don't need to store the result, just call so monitor increments
        hungryCaterpillar(bench_head);

        // Check if the bench_head was iterated through properly (they must traverse at least size times)
        ASSERT_LE_(size, m.iterations(),
            "Make sure you are iterating fully through the bench linked list!"
        );

        // No cleanup to allow points even if the lists are improperly setup
    }

}
