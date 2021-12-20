#include "../includes/minishell.h"

void	ft_sig_int_here(int signal)
{
	if (signal == SIGINT)
	{
		printf("entra\n");
		rl_on_new_line(); // indica a las siguientes funciones que estamos en la siguiente línea
		rl_replace_line("", 1); // reemplaza la línea con lo que le indiques
		rl_redisplay(); // muestra de nuevo lo que tenemos en prompt
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

    while (again)
    {
        signal(SIGINT, &ft_sig_int_here); // cambia el funcionamiento de ctrl + "C"  
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
