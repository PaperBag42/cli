/**
 * @file command.h
 * @brief definition of the command structure and functions.
 */
#ifndef _COMMAND_H
#define _COMMAND_H

/** Maximum length of command names, including a null terminator */
#define CLI_COMMAND_NAME_MAX 11

/** Maximum number of parameters for each command */
#define CLI_PARAMETER_NUM_MAX 5

/**
 * A callback function that parses an argument
 * before it is passed to the command callback.
 * The function should accept the argument string,
 * and can return a parsed argument of any type.
 */
typedef void *(*CLI_parserCallback)(char *arg);

/**
 * A callback function that defines what a command does.
 * The function should accept the command's arguments as an array,
 * and return 0 for success or non-zero for failure.
 */
typedef int (*CLI_commandCallback)(void **args);

/**
 * @struct CLI_parameter
 * @brief represents a parameter for a CLI command.
 */
typedef struct CLI_parameter
{
	CLI_parserCallback parser; /**< a callback function that parses the parameter
	                                before passing it to the command function */
} CLI_parameter;

/**
 * @struct CLI_command
 * @brief represents a command that can be executed by the CLI.
 * 
 * Once obtained by a call to CLI_AddCommand(),
 * the struct's attributes can be freely edited.
 */
typedef struct CLI_command
{
	char name[CLI_COMMAND_NAME_MAX]; /**< the name that will be used to identify the command when parsing */
	char *help; /**< a description of what the command does */
	CLI_parameter parameters[CLI_PARAMETER_NUM_MAX]; /**< the parameters the command accepts */
	unsigned nParameters; /**< the number of parameters */
	CLI_commandCallback func; /**< callback function to execute after parsing the command. */
}
CLI_command;

/**
 * @brief adds a new parameter to a defined command.
 * 
 * @param command the command to add a parameter to
 * @return a pointer to the newly added parameter, of a null pointer if the function failed
 */
CLI_parameter *CLI_AddParameter(CLI_command *command, CLI_parserCallback parser);

#endif // _COMMAND_H
