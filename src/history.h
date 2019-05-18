/**
 * Private functions and macros for managing the history queue.
 */
#ifndef _HISTORY_H
#define _HISTORY_H

#include "../include/history.h"

/**
 * Adds the given command to the history queue.
 * Returns the newly added entry, or a null pointer if the function failed.
 */
_history_entry *add_history_entry(_history_entry **q, const char *command);

#endif // _HISTORY_H
