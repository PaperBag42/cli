#include "history.h"
#include <string.h>
#include <stdlib.h>

/**
 * Duplicates the command string and assigns it to a new entry,
 * then pushes the entry to the head of the queue.
 * Returns NULL if memory allocation failed.
 */
_history_entry *add_history_entry(_history_entry **q, const char *command)
{
	_history_entry *new = malloc(sizeof(_history_entry));
	
	if (new) {
		if ((new->command = strdup(command))) {
			new->next = NULL;
			new->prev = *q;
			
			*q = new;
			
		} else {
			free(new);
			new = NULL;
		}
	}
	
	return new;
}
