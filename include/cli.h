/**
 * @file cli.h
 * @brief functions and structures for dynamic management of a CLI.
 */
#ifndef _CLI_H
#define _CLI_H

#include "command.h"

/**
 * @enum CLI_errorCode
 * @brief codes for possible errors that the CLI parser can encounter
 */
typedef enum CLI_errorCode
{
	CLI_ERROR_OK, /**< parsed successfully, no error */
	CLI_ERROR_CALLBACK_FAILED, /**< the callback function submitted by the application returned a non-zero value */
}
CLI_errorCode;

typedef struct cli
{
	unsigned _size;
	unsigned _nCommands;
	CLI_command *_commands;
	// TODO: history queue
}
cli;

/**
 * @brief initiates the CLI parser and history queue.
 * 
 * @param size maximum number of different commands to parse
 * @return a pointer to the CLI's handle, or a null pointer if the function failed
 */
cli *CLI_Init(unsigned size);

/**
 * @brief defines a new command that the CLI can execute.
 * 
 * @param cli the CLI's handle
 * @param name the command's name as a null-terminated string
 * @param func a callback function to execute when the command is executed
 * @return a pointer to the newly defined command's data structure, or a null pointer if the function failed
 * @see CLI_command
 */
CLI_command *CLI_AddCommand(cli *cli, const char name[CLI_COMMAND_NAME_MAX], CLI_commandCallback func);

/**
 * @brief Reads a command line from standard input.
 * 
 * The user can navigate previously entered commands using the arrow keys.
 * 
 * @return the entered command, saved in a malloc'ed string
 */
char *CLI_GetCommand(void);

/**
 * @brief parses and executes a command line
 * 
 * Current command line syntax:
 * @code
 * cmd_name arg1 arg2 arg3 ...
 * @endcode
 * 
 * @param command the command line string to parse
 * @return a relevant error code if an error occurred, of CLI_ERROR_OK if the function succeeded.
 * @see CLI_errorCode
 */
CLI_errorCode CLI_Parse(cli *cli, const char *command);

#endif // _CLI_H
