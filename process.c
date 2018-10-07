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

t_r     *ret_start(t_l *tl)
{
    t_r      *tr;

    printf("RETURN START\n");
    tr = tl->r;
    while (tr)
    {
        if (tr->iS == 1){
            printf("START NAME = %s\n", tr->n);
            return (tr);
        }
        tr = tr->nx;
    }
    printf("return 0\n");
    return (NULL);
}

void    f_p(t_l *tl, char ***q, t_r *tr)
{
    char    **ch;
    char    **res;
    int     i;
    int     k;
    t_r     *cr;
printf("FP FP FPF FPF FPPPF FPF PF   FF PF FP FPF pF\n");
    k = -1;
    while ((*q)[++k])
    {
        if ((*q)[k + 1])
            (*q)[k] = (*q)[k + 1];
    }
    ch = ft_strsplit(tr->rl, '#');
    i = -1;
    while (ch[++i])
    {
        cr = find_r_by_n(tl, ch[i]);
        if (cr->f == 0)
        {
            if (ft_strlen(tr->pth) > 0)
            {  
                cr->pth = ft_strcat(cr->pth, tr->pth);
            }
            cr->pth = ft_strcat(cr->pth, tr->n);
            cr->pth = ft_strcat(cr->pth, "L");
            cr->f = 1;
            (*q)[k++] = cr->n;
            printf("write to queue\n");
        }
    }
}

void    find_paths(t_l *tl) // s - step
{
    char    **q; //que
    int     flag;
    t_r     *tr;
    int i;
    int p;

    flag = 0;
    tr = ret_start(tl);
    q = (char **)ft_memalloc(sizeof(char*) * 1000);
    q[0] = tr->n;
    while (!flag)
    {
        if (q[0]){
            tr = find_r_by_n(tl, q[0]);
             if (tr->iE == 1)
            flag = 1;
        f_p(tl, &q, tr);
        }else { flag = 1;}
       
    }
    
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
            if (tr->iS == 0)
            {
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

void     result(t_l *tl)
{
    t_r      *er;
    t_r      *sr;
    t_r        *nr;
    char    **nl;

    er = ret_end(tl);
    er->pth = ft_strcat(er->pth, er->n);
    printf("er->pth %s\n", er->pth);
    nl = ft_strsplit(er->pth, 'L');
    int i = -1;
    printf("before  before cycle\n");
    while (nl[++i])
    {
        printf("nl[++i] |%s|\n", nl[i]);
        nr = find_r_by_n(tl, nl[i]);
        nr->f = 0;
        if (nr->iS)
            nr->f = tl->na;
		nr->nx = (tl->nl) ? tl->nl : NULL;
		tl->nl = nr;
	}
printf("before cycle\n");
int l = -1;
    while(tl->en != tl->na)
    {
        nr = tl->nl;
        
        while(nr && ++l < 10)
        {
           sr = nr->nx;

            if (sr && sr->f > 0 && (nr->f == 0 || nr->iE == 1))
            {
                
                tl->res = ft_strcat(tl->res, "L");
                if (sr->iS == 1)
                {
                    tl->res = ft_strcat(tl->res, ft_itoa(tl->na - sr->f + 1));
                    nr->f = tl->na - sr->f + 1;
                    sr->f -= sr->f;
                }
                else{
                    tl->res = ft_strcat(tl->res, ft_itoa(sr->f));
                    nr->f = sr->f;
                    sr->f = 0;
                }
                tl->res = ft_strcat(tl->res, "-");
                tl->res = ft_strcat(tl->res, nr->n);
                tl->res = ft_strcat(tl->res, " ");
               if(nr->iE)
                tl->en++;
            }
            printf("cycle name = %s sr->f %i nr->f %i nr->ie %i\n", nr->n, sr->f, nr->f, nr->iE);
            nr = (nr->nx->n) ? nr->nx : NULL;
        }
        tl->res = ft_strcat(tl->res, "\n");

    }
    printf("RESRESRESRES: %s\n", tl->res);
}

int      process(t_l *tl)
{
    int i;
    t_r      *er;

    tl->en = 0;
    if (tl->na < 4)
    {
     char    *cr;//current resulr

        i = 0;
         tl->en = 0;
          tl->res = ft_memalloc(sizeof(char) * 2048);
          cr = ft_memalloc(sizeof(char) * 2048);
        find_paths(tl);
        er = ret_end(tl);
        printf("Result : %s\n", er->pth);
        result(tl);
        return (0);
    }

    i = 0;
   
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