#include "executable.h"

TEST(memory_management) {
    Typegen t;

    for (size_t i = 0; i < 20; i++) {
        // Create Monitor to observe program behavior
        Monitor m;

        size_t size = t.range<size_t>(0, 30);

        // Generate a linked list
        FlowerNode* bench_head = buildLinkedList(size, t);

        // Use later
        FlowerNode* caterpillar_head = nullptr; 

        // We should open a memhook that checks their allocations to creating a caterpillarHead list
        {
            Memhook mh;

            // Grab their hungry caterpillar list
            caterpillar_head = hungryCaterpillar(bench_head);

            // Disable memhook so it does not pick up any debug stream allocations
            mh.disable();

            // They should be creating 2 nodes for n - 1 nodes, and 1 for the nth node = (2 * n) - 1
            // The size check exists because if size = 0 we would underflow with - 1
            if (size) {
                ASSERT_EQ_(2 * size - 1, mh.n_allocs(),
                    "You did not allocate enough nodes in the construction of caterpillarHead!"
                );
            }
        }

        // Cleanup
        {
            Memhook mh;
            clearList(bench_head);
            mh.disable();
            ASSERT_EQ_(size, mh.n_frees(), // It would just be size here
                "The original \"bench\" list should not be changed (do not remove or add nodes to bench!)!"
            );
        }

        {
            Memhook mh;
            clearList(caterpillar_head);
            mh.disable();
            if (size) {
                ASSERT_EQ_(2 * size - 1, mh.n_frees(),
                "The list is not linked properly. There should be \"size\" connected nodes. Make sure you are returning caterpillarHead->next."
            );
            }
        }
    }
}
