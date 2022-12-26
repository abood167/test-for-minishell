#include "minishell.h"

void ctrl_c()
{
    t_mini *m;
    
    m = get_mini();
	//Maybe do wait here and then apply m.status?
	if(m->here_doc) 
		exit(130);
		// kill(m->pid, SIGTERM); //could cause leaks? // free stuff and do exit instead?
	if(m->pid && ft_lstlast(m->pid)->content != 0)
		return;
	m->status = 130;
	rl_replace_line("", 0);
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
}

void ft_int_signal()
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ctrl_c );
}