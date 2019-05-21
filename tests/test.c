#include <cli/cli.h>
#include <assert.h>
#include <stdlib.h>

int ret_cb(void **args)
{
	return **(char **)args - '0';
}

int main()
{
	cli *cli = cli_init(1);
	cli_command *ret = cli_add_command(cli, "ret", ret_cb);
	
	assert(ret);
	cli_add_parameter(ret, NULL);
	
	assert(!cli_add_command(cli, "too_many", NULL));
	
	assert(CLI_ERROR_OK                 == cli_parse(cli, "ret 0  "));
	assert(CLI_ERROR_NO_COMMAND         == cli_parse(cli, "       "));
	assert(CLI_ERROR_UNKNOWN_COMMAND    == cli_parse(cli, "lol 0  "));
	assert(CLI_ERROR_TOO_FEW_ARGUMENTS  == cli_parse(cli, "ret    "));
	assert(CLI_ERROR_TOO_MANY_ARGUMENTS == cli_parse(cli, "ret 0 1"));
	assert(CLI_ERROR_CALLBACK_FAILED    == cli_parse(cli, "ret 1  "));
	
	return 0;
}