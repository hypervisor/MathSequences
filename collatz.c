#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    uint64_t start_base = 3; // Base to start from
    uint64_t base_range = 1; // End at start_base + base_range

    if (argc == 2) {
        start_base = strtoull(argv[1], NULL, 0);
    } else if (argc == 3) {
        start_base = strtoull(argv[1], NULL, 0);
        base_range = strtoull(argv[2], NULL, 0);
    } else if (argc > 3) {
        printf("Invalid usage!\n");
        return 1;
    }

    uint64_t max_steps = 0, max_steps_base = 0;
    for (uint64_t base = start_base; base < start_base + base_range; ++base) {
        uint64_t num = base, steps = 0;
        while (num != 1) {
            steps++;
            if (num & 1)
                num = (num * 3) + 1;
            else
                num /= 2;
        }

        if (steps > max_steps) {
            max_steps = steps;
            max_steps_base = base;
        }
        printf("Base=%llu, steps=%llu\n", base, steps);
    }

    if (base_range > 1) {
        printf("Maximum steps=%llu, base=%llu\n", max_steps, max_steps_base);
    }
    
    return 0;
}