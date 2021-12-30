#include "../includes/minishell.h"

void	ft_sig_int_here(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
	}
}

int ft_heredoc(t_proc *process)
{
    //SIGNALS???
    char *keyword;
    int again;
    int fd;

    again = 1;
    fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    signal(SIGINT, SIG_IGN);
    signal(SIGINT, ft_sig_int_here);
    while (again)
    {
        keyword = readline("> ");
        if (ft_strcmp(keyword, process->input) == 0)
            again = 0;
        else
        {
            write(fd, keyword, ft_strlen(keyword));
            write(fd, "\n", 1);
        }
        free(keyword);
    }
    close (fd);
    return(0);
}
