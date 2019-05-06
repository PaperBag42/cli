/**
 * @file cli.h
 * @brief functions and structures for dynamic management of a CLI.
 */
#ifndef _CLI_H
#define _CLI_H

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
 * @enum CLI_errorCode
 * @brief codes for possible errors that the CLI parser can encounter
 */
typedef enum CLI_errorCode
{
	CLI_ERROR_OK, /**< parsed successfully, no error */
	CLI_ERROR_CALLBACK_FAILED, /**< the callback function submitted by the application returned a non-zero value */
}
CLI_errorCode;

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
	unsigned numberOfParameters; /**< the number of parameters the command accepts */
	CLI_commandCallback func; /**< callback function to execute after parsing the command. */
}
CLI_command;

/**
 * @brief initiates the CLI parser and history queue.
 * 
 * @param size maximum number of different commands to parse
 * @return non-zero if the function failed, otherwise zero
 */
int CLI_Init(unsigned size);

/**
 * @brief defines a new command that the CLI can execute.
 * 
 * @param name the command's name as a null-terminated string
 * @param callback a callback function to execute when the command is executed
 * @return a pointer to the newly defined command's data structure, or a null pointer of the function failed
 * @see CLI_command
 */
CLI_command *CLI_AddCommand(const char name[CLI_COMMAND_NAME_MAX], CLI_commandCallback callback);

/**
 * @brief adds a new parameter to a defined command.
 * 
 * TODO: add parsing callback
 * 
 * @param command the command to add a parameter to
 * @return non-zero if the function failed, otherwise zero
 */
int CLI_AddParameter(CLI_command *command);

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
CLI_errorCode CLI_Parse(const char *command);

#endif // _CLI_H
