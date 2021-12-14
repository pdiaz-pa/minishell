#include "../includes/minishell.h"


int ft_heredoc(t_proc *process)
{
    //SIGNALS???
    char *keyword;
    int again;
    again = 1;
    dup2(process->out_fd, STDOUT_FILENO);
		close(process->out_fd);
    while (again)
    {
        keyword = readline("> ");
        if (ft_strcmp(keyword, process->input) == 0)
            again = 0;
        else
        {
            write(process->in_fd, keyword, ft_strlen(keyword));
            write(process->in_fd, "\n", 1);
        }
    }
    close(process->in_fd);
    free(keyword);

    return(0);
}
