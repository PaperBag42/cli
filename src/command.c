#include "command.h"
#include <stdlib.h>
#include <string.h>

/**
 * Finds an empty entry in the parameters array,
 * and copies the parameter's details to there.
 * Returns NULL if the array is full.
 */
cli_parameter *cli_add_parameter(cli_command *command, cli_parser_callback parser)
{
	cli_parameter *p = NULL;
	
	if (command->nparameters < CLI_PARAMETER_NUM_MAX) {
		p = command->parameters + command->nparameters++;
		p->parser = parser;
	}
	
	return p;
}

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
