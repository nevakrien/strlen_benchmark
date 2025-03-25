#include <stdio.h>
#include <string.h>

#define NUM_RUN 100000000
#define STRING_LENGTH 100  // Length of each string
#define NUM_STRINGS 100000  // Number of strings to store in the buffer

// Declare the function you're benchmarking
int my_strlen(const char* s);

int main() {
    // Allocate a large buffer of strings packed together
    char buffer[NUM_STRINGS][STRING_LENGTH];

    // Initialize the buffer with some data
    for (int i = 0; i < NUM_STRINGS; i++) {
        snprintf(buffer[i], STRING_LENGTH, "This is string number %d", i);
    }

    // Benchmark loop: call my_strlen(NUM_RUN) times
    for (int i = 0; i < NUM_RUN; i++) {
        // Loop over the strings in the buffer and call my_strlen on each one
        for (int j = 0; j < NUM_STRINGS; j++) {
            int len = my_strlen(buffer[j]);  // This is where you're benchmarking
            (void)len; // To avoid unused variable warning
        }
    }

    return 0;
}