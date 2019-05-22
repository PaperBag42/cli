#include <cli/cli.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int ret_cb(char **args)
{
	printf("Callback received \"%s\"\n", *args);
	
	return **args - '0';
}

int main()
{
	cli *cli = cli_init(1);
	cli_command *ret = cli_add_command(cli, "ret", 1, ret_cb);
	
	assert(ret);
	assert(!cli_add_command(cli, "too_many", 0, ret_cb));
	
	assert(CLI_ERROR_OK                 == cli_parse(cli, "Ret 0  "));
	assert(CLI_ERROR_NO_COMMAND         == cli_parse(cli, "       "));
	assert(CLI_ERROR_UNKNOWN_COMMAND    == cli_parse(cli, "lol 0  "));
	assert(CLI_ERROR_TOO_FEW_ARGUMENTS  == cli_parse(cli, "ret    "));
	assert(CLI_ERROR_TOO_MANY_ARGUMENTS == cli_parse(cli, "ret 0 1"));
	assert(CLI_ERROR_CALLBACK_FAILED    == cli_parse(cli, "ret 1  "));
	
	return 0;
}
