# include "lemin.h"

t_r     *ret_end(t_l *tl)
{
    t_r      *tr;

    printf("RETURN END\n");
    tr = tl->r;
    while (tr)
    {
        if (tr->iE == 1){
            printf("END NAME = %s\n", tr->n);
            return (tr);
        }
        tr = tr->nx;
    }
    printf("return 0\n");
    return (NULL);
}

void    check_next(t_l *tl, t_r *cr, int s) // s - step
{
    char    **ch;
    int i;
    t_r      *tr;

   // printf("SSSSSSSSSSSSSSSS = %i\n", s);
    printf("check_next name = %s, s = %i\n", cr->n, cr->st);

    ch = ft_strsplit(cr->rl, '#');
    i = -1;
    while(ch[++i])
    {
        tr = find_r_by_n(tl, ch[i]);
        printf("WHILE NAME -- %s, s = %i\n", tr->n, tr->st);
        if (tr->f != 0 && tr->st < s && tr->iE == 0 && (cr->f == 0 || cr->iE == 1))
        {
          //   printf("find ant in name = %s\n", tr->n);
            tl->res = ft_strcat(tl->res, "L");
            if (tr->iS == 0){
                cr->f = tr->f;
                tr->f = 0;
                tl->res = ft_strcat(tl->res, ft_itoa(cr->f));
            }
            else if (tr->f > 0){
                cr->f = tl->na - tr->f + 1;
            //    printf("tl->na = %i, tr->f = %i, tl->na - tl->sn + 1 = %i\n", tl->na,tr->f,(tl->na - tr->f + 1));
                tl->res = ft_strcat(tl->res, ft_itoa(tl->na - tr->f + 1));
                tr->f -= 1;
            }
            tl->res = ft_strcat(tl->res, "-");
            tl->res = ft_strcat(tl->res, cr->n);
            tl->res = ft_strcat(tl->res, " ");

           // printf("CURRENT      Result : %s\n", tl->res);
            if (cr->iE == 1)
            {
                tl->en++;
            //    printf("tl->en+++++++++++++++++++++++++++++++++++++++++\n");
            }
        }
        if (tr->st < s)
        {   
            if (tr->iS == 0)
            {
                tr->st = s;
                check_next(tl, tr, s);
            }
        }
    }
    cr->st = s;
}


int      process(t_l *tl)
{
    int i;
    t_r      *er;

    i = 0;
    tl->en = 0;
    tl->res = ft_memalloc(sizeof(char) * 2048);
    while (tl->en != tl->na && ++i && tl->en > -1)
    {
        er =  ret_end(tl);
        er->st = i;
        check_next(tl, er, i);
        if (!ft_strlen(tl->res))
        {
            tl->en = -5;
        }
        else 
         tl->res = ft_strcat(tl->res, "\n");
    }
    printf("Result : %s\n", tl->res);
    if (tl->en < 0)
        printf("Error");
    return (0);
}