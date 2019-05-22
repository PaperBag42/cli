#include "../include/cli/cli.h"
#include "parsing.h"
#include <string.h>
#include <stdio.h>

#define SEPERATORS " \t\r\n\v\f"

/**
 * Simply allocates the required memory.
 * Returns NULL if memory allocation failed.
 */
cli *cli_init(unsigned size)
{
	cli *handle = malloc(sizeof(cli));
	
	if (handle) {
		if ((handle->_commands = calloc(size, sizeof(cli_command)))) {
			handle->_size = size;
			handle->_ncommands = 0;
			handle->_history = NULL;
		} else {
			free(handle);
			handle = NULL;
		}
	}
	
	return handle;
}

/**
 * Finds an empty entry in the commands array,
 * and copies the command's details to there.
 * Returns NULL if the array is full, the callback function is a null pointer,
 * or the command's name contains whitespace.
 * 
 * TODO: perhaps use a binary tree instead.
 * It will be more efficient to find a command,
 * but we won't be able to utilize the maximum size.
 */
cli_command *cli_add_command(cli *cli, const char name[CLI_COMMAND_NAME_MAX], unsigned nparameters, cli_command_callback func)
{
	cli_command *p = NULL;
	
	if (func && cli->_ncommands < cli->_size && !name[strcspn(name, SEPERATORS)]) {
		p = cli->_commands + cli->_ncommands++;
		copy_lower(p->name, name, CLI_COMMAND_NAME_MAX - 1);
		p->func = func;
		p->nparameters = nparameters;
	}
	
	return p;
}

char *cli_get_command(void)
{
	fprintf(stderr, "Not yet implemented");
	abort();
	
	return NULL;
}
