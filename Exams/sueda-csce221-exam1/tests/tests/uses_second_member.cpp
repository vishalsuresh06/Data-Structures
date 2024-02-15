#include "executable.h"
#include <unordered_set>

TEST(uses_second_member) {
    Typegen t;

    // 20 tests
    for (size_t i = 0; i < 20; i++) {
        // Use Monitor as necessary
        Monitor m;

        size_t size = t.range<size_t>(1, 15); // Grab random size in range [1, 15]
        Planet* plts_arr = new Planet[size];

        // We need random volumes and densities to construct Planets with, ideally unique
        std::unordered_set<double> volumes;
        std::unordered_set<double> densities;

        // Start filling planet array
        for (size_t j = 0; j < size; j++) {
            double volume = t.range<double>(1, 100);
            double density = t.range<double>(1, 100);

            // Repeat generation of volumes and densities if duplicate exists
            while (volumes.count(volume)) {
                volume = t.range<double>(1, 100);
            }

            volumes.insert(volume);

            while (densities.count(density)) {
                density = t.range<double>(1, 100);
            }

            densities.insert(density);
            plts_arr[j] = Planet(volume, density);
        }

        // Call the function to update Monitor
        find_planets_mass(Pointer<Planet>(plts_arr), size);

        ASSERT_LE_(true, m.second(), 
            "You did not access the private density member of an element(s) in the array!"
        );

        ASSERT_EQ_(false, m.brackets(),
            "You should not be using brackets to access the array!"
        );

        delete[] plts_arr;
    }
}