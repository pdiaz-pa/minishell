#include "../includes/minishell.h"


int ft_heredoc(t_proc *process)
{
    //SIGNALS???
    char *keyword;
    int again;
    int fd;

    again = 1;
    fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
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
    return(0);
}
