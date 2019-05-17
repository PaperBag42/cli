#include "../include/cli.h"
#include <stdlib.h>
#include <string.h>

/**
 * Simply allocates the required memory.
 */
cli *cli_init(unsigned size)
{
	cli *handle = malloc(sizeof(cli));
	
	if (handle) {
		if (handle->_commands = calloc(size, sizeof(cli_command))) {
			handle->_size = size;
			handle->_ncommands = 0;
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
 * Returns NULL if the array is full.
 * 
 * TODO: perhaps use a binary tree instead.
 * It will be more efficient to find a command,
 * but we won't be able to utilize the maximum size.
 */
cli_command *cli_add_command(cli *cli, const char name[CLI_COMMAND_NAME_MAX], cli_command_callback func)
{
	cli_command *p = NULL;
	
	if (cli->_ncommands < cli->_size) {
		p = cli->_commands + cli->_ncommands++;
		strncpy(p->name, name, CLI_COMMAND_NAME_MAX - 1);
		p->func = func;
	}
	
	return p;
}
