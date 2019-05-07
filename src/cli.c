#include "../include/cli.h"
#include <stdlib.h>
#include <string.h>

#define COMMAND_EXISTS(cmd) ((cmd).func)

/**
 * simply allocates the required memory.
 */
cli *CLI_Init(unsigned size)
{
	cli *handle = malloc(sizeof(cli));
	
	if (handle &&
		(handle->_commands = calloc(size, sizeof(CLI_command)))) {
		handle->_size = size;
	}
	
	return handle;
}

CLI_command *CLI_AddCommand(cli *cli, const char name[CLI_COMMAND_NAME_MAX], CLI_commandCallback func)
{
	CLI_command *p = cli->_commands;
	unsigned i = 0;
	
	while (i < cli->_size && COMMAND_EXISTS(*p)) {
		++p;
		++i;
	}
	
	if (i < cli->_size) {
		strncpy(p->name, name, CLI_COMMAND_NAME_MAX - 1);
		p->func = func;
		p->nParameters = 0;
	} else {
		p = NULL;
	}
	
	return p;
}
