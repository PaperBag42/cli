#include "../include/cli.h"
#include <stdlib.h>
#include <string.h>

#define COMMAND_EXISTS(cmd) ((cmd).func)

/**
 * Simply allocates the required memory.
 */
cli *CLI_Init(unsigned size)
{
	cli *handle = malloc(sizeof(cli));
	
	if (handle &&
		(handle->_commands = calloc(size, sizeof(CLI_command)))) {
		handle->_size = size;
		handle->_nCommands = 0;
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
CLI_command *CLI_AddCommand(cli *cli, const char name[CLI_COMMAND_NAME_MAX], CLI_commandCallback func)
{
	CLI_command *p = NULL;
	
	if (cli->_nCommands < cli->_size) {
		p = cli->_commands + cli->_nCommands++;
		strncpy(p->name, name, CLI_COMMAND_NAME_MAX - 1);
		p->func = func;
	}
	
	return p;
}
