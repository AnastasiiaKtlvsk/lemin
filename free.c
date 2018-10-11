# include "lemin.h"

void    free_rooms(t_l *tl)
{
    t_r      *tr;
    t_r      *cr;

    tr = tl->r;
    while (tr)
    {
       free(tr->n);
       free(tr->rl);
       free(tr->pth);
       cr = tr;
       tr = tr->nx;
       free(cr);
    }
}
void    free_lm(t_l *tl)
{
    if (tl->c && ft_strlen(tl->c) > 0)
        free(tl->c);
    if (tl->res && ft_strlen(tl->res) > 0)
        free(tl->res);
    if (tl->rl && ft_strlen(tl->rl) > 0)
        free(tl->rl);
    free_rooms(tl);
}

