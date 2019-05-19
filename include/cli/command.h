/**
 * @file command.h
 * @brief definition of the command structure and functions.
 */
#ifndef _CLI_COMMAND_H
#define _CLI_COMMAND_H

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
typedef void *(*cli_parser_callback)(char *arg);

/**
 * A callback function that defines what a command does.
 * The function should accept the command's arguments as an array,
 * and return 0 for success or non-zero for failure.
 */
typedef int (*cli_command_callback)(void **args);

/**
 * @struct cli_parameter
 * @brief represents a parameter for a CLI command.
 */
typedef struct cli_parameter
{
	cli_parser_callback parser; /**< a callback function that parses the parameter
	                                before passing it to the command function */
} cli_parameter;

/**
 * @struct cli_command
 * @brief represents a command that can be executed by the CLI.
 * 
 * Once obtained by a call to cli_add_command(),
 * the struct's attributes can be freely edited.
 */
typedef struct cli_command
{
	char name[CLI_COMMAND_NAME_MAX]; /**< the name that will be used to identify the command when parsing */
	char *help; /**< a description of what the command does */
	cli_parameter parameters[CLI_PARAMETER_NUM_MAX]; /**< the parameters the command accepts */
	unsigned nparameters; /**< the number of parameters */
	cli_command_callback func; /**< callback function to execute after parsing the command. */
} cli_command;

/**
 * @brief adds a new parameter to a defined command.
 * 
 * @param command the command to add a parameter to
 * @return a pointer to the newly added parameter, of a null pointer if the function failed
 */
cli_parameter *cli_add_parameter(cli_command *command, cli_parser_callback parser);

#endif // _CLI_COMMAND_H
