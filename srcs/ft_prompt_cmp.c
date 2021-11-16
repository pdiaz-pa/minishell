#include "../includes/minishell.h"

void ft_prompt_cmp(char *prompt, t_env *env, t_env *exp, char **envp)
{
	extern char **environ;
	int i;

	// Array temporal
	char	**argv;
	argv = malloc(sizeof(char *) * 3);
	argv[0] = ft_strdup("Hello ");
	argv[1] = ft_strdup("Hello");
	argv[2] = ft_strdup("-n");
	// Fin array temporal


	i = 0;
	if (ft_strncmp("pwd", prompt, 3) == 0) //compara este string con lo que está en prompt (lo que metemos)
				printf("%s\n", getcwd(NULL, 0));
	else if (ft_strncmp("exit", prompt, 4) == 0)
	{
		write(1, "exit\n", 5);
		exit(1);
	}
	else if (ft_strncmp("echo", prompt, 4) == 0)
	{
		ft_echo(argv);
	}
	else if (ft_strncmp("cd", prompt, 2) == 0)
	{
		ft_cd(&prompt[2], env);
	}
	else if (ft_strncmp("export", prompt, 6) == 0)
	{
		ft_print_export(exp);
	}
	else if (ft_strncmp("unset", prompt, 5) == 0)
	{
		printf("función unset\n");
	}
	else if (ft_strncmp("env", prompt, 3) == 0)
		ft_print_env(env);
	else
	{
		ft_exe(prompt, env, envp);
	}
}