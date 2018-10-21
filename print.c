# include "lemin.h"

void    print_res(t_l *tl)
{
    tl->pr = ft_strcat(tl->pr,"\n");
    ft_putstr(tl->pr);
    if (tl->c && ft_strlen(tl->c))
    {
        ft_putstr("Comments: \n");
        ft_putstr(tl->c);
        ft_putstr("\n");
    }
    ft_putstr(tl->res);
}

