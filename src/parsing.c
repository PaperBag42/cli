#include "../include/cli/cli.h"
#include "parsing.h"
#include "history.h"
#include "command.h"
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define TOK_INIT(buf) strtok((buf), WHITESPACE)
#define TOK_NEXT()    TOK_INIT(NULL)

/* An error handling macro that checks a condition,
   and frees resources and returns an error code on failure. */
#define ASSERT_OR(cond, code) do { \
	if (!(cond)) {                 \
		free(buf);                 \
		return (code);             \
	}                              \
} while (false);

/**
 * First, tokenizes the command string using strtok.
 * Finds the command's data by the first token,
 * then loads the arguments to an array from the rest of the tokens.
 * Finally, calls the command's callback function with the arguments.
 * Stops if any error occures along the way.
 */
cli_error_code cli_parse(cli *cli, const char *command)
{
	char *buf = NULL;
	const size_t len = strlen(command) + 1;
	char *token = NULL;
	cli_command *cmd_data = NULL;
	
	char *args[CLI_PARAMETER_NUM_MAX + 1] = { NULL }; // extra cell for null terminator
	char **arg = args;
	
	ASSERT_OR(
		add_history_entry(&cli->_history, command) &&
		(buf = malloc(len * sizeof(char))),
		CLI_ERROR_OUT_OF_MEMORY)
	
	copy_lower(buf, command, len);
	
	ASSERT_OR(token = TOK_INIT(buf), CLI_ERROR_NO_COMMAND)
	
	ASSERT_OR(
		cmd_data = find_command(cli->_commands, cli->_ncommands, token),
		CLI_ERROR_UNKNOWN_COMMAND)
	
	for (unsigned i = cmd_data->nparameters; i; --i, ++arg) {
		ASSERT_OR(*arg = TOK_NEXT(), CLI_ERROR_TOO_FEW_ARGUMENTS)
	}
	ASSERT_OR(!TOK_NEXT(), CLI_ERROR_TOO_MANY_ARGUMENTS)
	
	ASSERT_OR(!cmd_data->func(args), CLI_ERROR_CALLBACK_FAILED)
	
	free(buf);
	return CLI_ERROR_OK;
}

void copy_lower(char *dest, const char *src, size_t len)
{
	for (; *src && len; ++dest, ++src, --len) {
		*dest = tolower(*src);
	}
}
