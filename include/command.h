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
 * A callback function that defines what a command does.
 * The function should accept the command's arguments as an array,
 * and return 0 for success or non-zero for failure.
 */
typedef int (*CLI_commandCallback)(void **args);

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
	unsigned nParameters; /**< the number of parameters the command accepts */
	CLI_commandCallback func; /**< callback function to execute after parsing the command. */
}
CLI_command;

/**
 * @brief adds a new parameter to a defined command.
 * 
 * @param command the command to add a parameter to
 * @return non-zero if the function failed, otherwise zero
 */
int CLI_AddParameter(CLI_command *command);

#endif // _COMMAND_H
