#include "../includes/minishell.h"

static int	ft_char_dance(char *c);

int	ft_prompt_cmp(t_env *env, t_cont *command, char mode)
{
	int	ret;
	int	dance;

	ret = 4242;
	dance = ft_char_dance(command->content);
	if (dance == 1)
		ret = ft_pwd();
	else if (dance == 2)
		ret = ft_print_env(env);
	else if (dance == 3)
		ret = ft_echo(command->next);
	else if (ft_strcmp("cd", command->content) == 0)
		ret = ft_cd(&env, command->next);
	else if (ft_strcmp("export", command->content) == 0)
		ret = ft_export(&env, command->next);
	else if (ft_strcmp("unset", command->content) == 0)
		ret = ft_unset(&env, command->next);
	else
		ret = ft_exe(env, command, mode);
	if (mode == 'b')
		ft_exit (&env);
	return (ret);
}

static int	ft_char_dance(char *c)
{
	int	len;

	len = ft_strlen(c);
	if (len == 3)
	{
		if ((c[0] == 'p' || c[0] == 'P') && (c[1] == 'w' || c[1] == 'W')
			&& (c[2] == 'd' || c[2] == 'D'))
			return (1);
		else if ((c[0] == 'e' || c[0] == 'E') && (c[1] == 'n' || c[1] == 'N')
			&& (c[2] == 'v' || c[2] == 'V'))
			return (2);
	}
	else if (len == 4)
	{
		if ((c[0] == 'e' || c[0] == 'E') && (c[1] == 'c' || c[1] == 'C')
			&& (c[2] == 'h' || c[2] == 'H') && (c[3] == 'o' || c[3] == 'O'))
			return (3);
	}
	return (0);
}
