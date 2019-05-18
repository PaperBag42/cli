/**
 * @file history.h
 * @brief definition of the history data structure.
 */
#ifndef _CLI_HISTORY_H
#define _CLI_HISTORY_H

typedef struct _history_entry
{
	char *command;
	struct _history_entry *next;
	struct _history_entry *prev;
} _history_entry;

#endif // _CLI_HISTORY_H
