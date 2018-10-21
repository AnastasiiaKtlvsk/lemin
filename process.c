# include "lemin.h"

t_r     *ret_end(t_l *tl)
{
    t_r      *tr;

    tr = tl->r;
    while (tr)
    {
        if (tr->iE == 1)
            return (tr);
        tr = tr->nx;
    }
    return (NULL);
}

t_r     *ret_start(t_l *tl)
{
    t_r      *tr;

    tr = tl->r;
    while (tr)
    {
        if (tr->iS == 1)
            return (tr);
        tr = tr->nx;
    }
    return (NULL);
}

void    f_p(t_l *tl, char ***q, t_r *tr, int k)
{
    char    **ch;
    int     i;
    t_r     *cr;

    while ((*q)[++k])
        if ((*q)[k + 1])
            (*q)[k] = (*q)[k + 1];
    ch = ft_strsplit(tr->rl, '#');
    i = -1;
    k -= 1;
    (*q)[k] = NULL;
    while (ch[++i])
    {
        cr = find_r_by_n(tl, ch[i]);
        if (cr && cr->f == 0)
        {
            if (ft_strlen(tr->pth) > 0)
                cr->pth = ft_strcat(cr->pth, tr->pth);
            cr->pth = ft_strcat(cr->pth, tr->n);
            cr->pth = ft_strcat(cr->pth, "L");
            cr->f = 1;
            (*q)[k++] = cr->n;
        }
    }
    free_da(ch);
}

int    find_paths(t_l *tl)
{
    char    **q;
    int     flag;
    t_r     *tr;

    flag = 0;
    tr = ret_start(tl);
    q = (char **)ft_memalloc(sizeof(char*) * 5000);
    q[0] = tr->n;
    while (!flag)
    { 
        if (q[0] && ft_strlen(q[0]) > 0)
        {
            tr = find_r_by_n(tl, q[0]);
            if (tr->iE == 1)
                flag = 1;
            f_p(tl, &q, tr, -1);
        } else
            flag = 5;
    }
    if (q)
        free_da(q);
    if (flag == 1)
        return 1;
    return 0;
}

void    ch_n_c(t_l *tl, t_r  *tr, t_r *cr, int s)
{
    char    *t;
 
   if (tr->f != 0 && tr->st < s && tr->iE == 0 &&
        (cr->f == 0 || cr->iE == 1))
    {
       tl->res = ft_strcat(tl->res, "L");
        if (tr->iS == 0)
        {
            cr->f = tr->f;
            tr->f = 0;
            t = ft_itoa(cr->f);
        }
        else if (tr->f > 0)
        {
            cr->f = tl->na - tr->f + 1;
            t = ft_itoa(tl->na - tr->f + 1);
            tr->f -= 1;
        }
        tl->res = ft_strcat(tl->res, t);
        free(t);
        tl->res = ft_strcat(tl->res, "-");
        tl->res = ft_strcat(tl->res, cr->n);
        tl->res = ft_strcat(tl->res, " ");
        if (cr->iE == 1)
            tl->en++; 
    } 
}

void    check_next(t_l *tl, t_r *cr, int s, char  ***ch)
{
    int     i;
    t_r     *tr;
    char    **dh;

    i = -1;
    while((*ch)[++i])
    {
        tr = find_r_by_n(tl, (*ch)[i]);
        if (tr)
        {
            ch_n_c(tl, tr, cr, s);
            if (tr->st < s)
            {
                if (tr->iS == 0)
                {
                    tr->st = s;
                    dh = ft_strsplit(tr->rl, '#');
                    check_next(tl, tr, s, &dh);
                   // free_da(dh);
                }
            }
        }
    }
   // if (s > 2)
   if (*ch && *ch[0])
   free_da(*ch);
    cr->st = s;
}


void     pr_res(t_l *tl, t_r *nr)
{
    t_r *sr;
    char    *t;

    sr = (nr->nx) ? nr->nx : 0;
    if (sr && sr->f > 0 && (nr->f == 0 || nr->iE == 1))
    {
        tl->res = ft_strcat(tl->res, "L");
        if (sr->iS == 1)
        {
            t = ft_itoa(tl->na - sr->f + 1);

            nr->f = tl->na - sr->f + 1;
            sr->f -= 1;
        }
        else
        {
            t = ft_itoa(sr->f);
            nr->f = sr->f;
            sr->f = 0;
        }
        tl->res = ft_strcat(tl->res, t);
        free(t);
        tl->res = ft_strcat(tl->res, "-");
        tl->res = ft_strcat(tl->res, nr->n);
        tl->res = ft_strcat(tl->res, " ");
        if(nr->iE)
            tl->en++;
    }
}

void     result(t_l *tl, int i, char **nl)
{
    t_r     *nr;
    t_r     *tr;

    while (nl[++i])
    {
        nr = cr_r(tl, 1);
        tr = find_r_by_n(tl, nl[i]);
        if (tr){
        nr->n = ft_strdup(tr->n);
        nr->pth = ft_strcat(nr->pth, tr->pth);
        nr->iS = tr->iS;
        nr->f = (nr->iS == 1) ? tl->na : 0;
        nr->iE = tr->iE;
        nr->nx = (tl->nl) ? tl->nl : NULL;
        }
        tl->nl = nr;
    }

    while(tl->en != tl->na)
    {
        nr = tl->nl;
        while(nr && ft_strlen(nr->n) > 0)
        {
            //write(1, "r222\n", 5);
            pr_res(tl, nr);
            nr = (nr && nr->nx != NULL) ? nr->nx : NULL;
          //  write(1, "r333\n", 5);
        }
         tl->res = ft_strcat(tl->res, "\n");
        // write(1, "r444\n", 5);
    }
    free_da(nl);
}

int    one_way(t_l *tl)
{
    t_r      *er;

    tl->en = 0;
    tl->res = ft_memalloc(sizeof(char) * 8056);
    
    if (!find_paths(tl))
    {
        ft_putstr("Error\n");
        return (0);
    }

write(1, "fp\n", 3);
    er = ret_end(tl);
    write(1, "re\n", 3);
    er->pth = ft_strcat(er->pth, er->n);
    printf("path = %s\n", er->pth);
    return (1); //___________________________________
    result(tl, -1, ft_strsplit(er->pth, 'L'));
    write(1, "r2\n", 3);
    print_res(tl);
    return (1);
}

int      process(t_l *tl)
{
    int i;
    t_r      *er;
    char    **tc;

    tl->en = 0;
    if (tl->na < 4)
        return(one_way(tl));

    i = 0;
    tl->res = ft_memalloc(sizeof(char) * 4056);
    while (tl->en != tl->na && ++i && tl->en > -1)
    {
         
        er =  ret_end(tl);
        er->st = i;
        tc = ft_strsplit(er->rl, '#');
        check_next(tl, er, i, &tc);
       // free(tc); 
        if (!ft_strlen(tl->res))
        {
            tl->en = -5;
        }
        else
            tl->res = ft_strcat(tl->res, "\n");
    }
    print_res(tl);
    if (tl->en < 0)
        ft_putstr("Error\n");
    return (0);
}