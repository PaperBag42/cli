#include "command.h"
#include <stdlib.h>
#include <string.h>

/**
 * Compares each command's name to the given name.
 * Returns NULL if the name is too long, or no name matched.
 */
cli_command *find_command(cli_command *commands, unsigned len, const char *name)
{
	cli_command *p = NULL;
	
	if (CLI_COMMAND_NAME_MAX > strlen(name)) {
		while (!p && len--) {
			if (!strncmp(name, commands->name, CLI_COMMAND_NAME_MAX)) {
				p = commands;
			}
			++commands;
		}
	}
	
	return p;
}
