#include "executable.h"
#include <unordered_set>
#include <vector>
#include <functional>
#include <numeric>

TEST(answer) {
    Typegen t;

    // 20 tests
    for (size_t i = 0; i < 20; i++) {
        // Use Monitor as necessary
        Monitor m;

        size_t size = t.range<size_t>(1, 15); // Grab random size in range [1, 15]
        Planet* plts_arr = new Planet[size];
        std::vector<double> cont(size);

        // We need random volumes and densities to construct Planets with, ideally unique
        std::unordered_set<double> volumes;
        std::unordered_set<double> densities;

        // Start filling planet array
        for (size_t j = 0; j < size; j++) {
            double v = t.range<double>(1, 100);
            double d = t.range<double>(1, 100);

            // Repeat generation of volumes and densities if duplicate exists
            while (volumes.count(v)) {
                v = t.range<double>(1, 100);
            }

            volumes.insert(v);

            while (densities.count(d)) {
                d = t.range<double>(1, 100);
            }

            densities.insert(d);
            plts_arr[j] = Planet(v, d);

            cont[j] = (d * v);
        }

        double s = find_planets_mass(Pointer<Planet>(plts_arr), size);
        double a = std::accumulate(cont.begin(), cont.end(), 0.0);

        double tolerance = 0.5;
        bool eqAnswer = a - tolerance < s && s < a + tolerance;

        ASSERT_TRUE_(eqAnswer, "Incorrect calculation of the total mass");

        ASSERT_EQ_(a, s,
            "Incorrect calculation of the total mass"
        );

        delete[] plts_arr;
    }
}