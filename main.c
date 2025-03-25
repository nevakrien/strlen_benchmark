#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_RUN 100
#define STRING_LENGTH 100
#define NUM_STRINGS 1000000

int my_strlen(const char* s);

int main() {
    // Allocate a large buffer of strings on the heap
    char (*buffer)[STRING_LENGTH] = malloc(NUM_STRINGS * STRING_LENGTH);
    if (!buffer) {
        perror("malloc failed");
        return 1;
    }

    // Initialize the buffer with some data
    for (int i = 0; i < NUM_STRINGS; i++) {
        snprintf(buffer[i], STRING_LENGTH, "This is string number %d", i);
    }

    // Benchmark loop
    for (int i = 0; i < NUM_RUN; i++) {
        for (int j = 0; j < NUM_STRINGS; j++) {
            int len = my_strlen(buffer[j]);
            (void)len;
        }
    }

    free(buffer);
    return 0;
}
