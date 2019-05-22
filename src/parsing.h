/**
 * @file parsing.h
 * @brief Helper functions and macros for handling command text.
 */
#include <stdlib.h>

#define WHITESPACE " \t\r\n\v\f"

/**
 * Helper function that copies a string and converts its characters to lower case,
 * in order to maintain case insensitivity.
 */
void copy_lower(char *dest, const char *src, size_t len);
