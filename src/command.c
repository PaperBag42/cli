#include "../include/command.h"
#include <stdlib.h>

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
