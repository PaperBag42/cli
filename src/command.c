#include "../include/command.h"
#include <stdlib.h>

/**
 * Finds an empty entry in the parameters array,
 * and copies the parameter's details to there.
 * Returns NULL if the array is full.
 */
CLI_parameter *CLI_AddParameter(CLI_command *command, CLI_parserCallback parser)
{
	CLI_parameter *p = NULL;
	
	if (command->nParameters < CLI_PARAMETER_NUM_MAX) {
		p = command->parameters + command->nParameters++;
		p->parser = parser;
	}
	
	return p;
}
