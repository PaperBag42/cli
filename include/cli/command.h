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
 * A callback function that defines what a command does.
 * The function should accept the command's arguments as an array,
 * and return 0 for success or non-zero for failure.
 */
typedef int (*cli_command_callback)(char **args);

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
	unsigned nparameters; /**< the number of parameters the command accepts */
	cli_command_callback func; /**< callback function to execute after parsing the command. */
} cli_command;

#endif // _CLI_COMMAND_H
