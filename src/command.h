/**
 * Private functions for managing the commands list.
 */
#ifndef _COMMAND_H
#define _COMMAND_H

#include "../include/command.h"

/**
 * Finds a command in the array by name
 * Returns the command structure, or a null pointer if the command was not found.
 */
cli_command *find_command(cli_command *commands, unsigned len, const char *name);

#endif // _COMMAND_H
