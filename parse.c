/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:12:48 by akotilie          #+#    #+#             */
/*   Updated: 2018/09/30 17:12:50 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

void    free_da(char **arr)
{
    int i;
    int k;

    i = 0;
    while (arr[i])
        i++;
    k = -1;
    while (++k < i)
        free(arr[k]);
    free(arr);
}

int     ch_dgts(char *s)
{
    int i;

    i = -1;
    while (s[++i])
    {
        if ((s[i] > 57 || s[i] < 48) &&
        s[i] != ' ' && s[i] != '-' && s[i] != 13)
            return (0);
    }
    return (1);
}

t_r     *cr_r(t_l *tl, int t)
{
    t_r     *r;

    r = ft_memalloc(sizeof(t_r));
    r->iS = (t == 0) ? 1 : 0;
    r->iE = (t == 2) ? 1 : 0;
    r->f = (t == 0) ? tl->na : 0;
    r->st = 0;
    r->rl = ft_memalloc(sizeof(char) * 100000);
    r->pth = ft_memalloc(sizeof(char) * 100000);
    r->nx = NULL;
    return (r);
}

int     check_room(t_l *tl, t_r *nr)
{
    t_r *tr;

    if (tl->r)
	    tr = tl->r;
	if (nr && nr->n && nr->x > -2147483647
    && nr->y > -2147483647)
	{
        while (tl->r && tr)
        {
            if ((nr->x == tr->x && nr->y == tr->y) || nr->n == tr->n)
                return (0);
            tr = tr->nx;
        }
		 nr->nx = (tl->r) ? tl->r : NULL;
		 tl->r = nr;
         return (1);
	}
    return (0);
}


void    pr_com(t_l *tl, char *temp)
{
    if (!tl->c || ft_strlen(tl->c) == 0)
        tl->c = ft_memalloc(sizeof(char) * 100000);
    tl->c = ft_strcat(tl->c, ft_strchr(temp, '#') + 1); 
    tl->c = ft_strcat(tl->c, "\n");
}


int     pr_sw(t_l *tl, char *temp, int fd)
{
    char    *line;
    t_r     *r;
    char    **pms;

    tl->pr = ft_strcat(tl->pr, temp);
    tl->pr = ft_strcat(tl->pr,"\n");
    if (get_next_line(fd, &line) > 0)
    {
        tl->pr = ft_strcat(tl->pr, line);
        tl->pr = ft_strcat(tl->pr,"\n");
        pms = ft_strsplit(line, ' ');
        if (pms[0] && pms[1] && pms[2])
        {
              r = (ft_strstr(temp, "start")) ? cr_r(tl, 0) : cr_r(tl, 2);
              (ft_strstr(temp, "start")) ? tl->sn++ : tl->en++;
              r->n = ft_strdup(pms[0]);
              r->x = (ch_dgts(pms[1])) ? ft_atoi(pms[1]) : -2147483647;
              r->y = (ch_dgts(pms[2])) ? ft_atoi(pms[2]) : -2147483647;
              free_da(pms);
              free(line);
              if (check_room(tl, r))
              {
                 return (1);
              }
        }
    }
    return (0);   
}

int     cr_room(t_l *tl, char *temp)
{
    char    **pms;
    t_r     *r;
    int     f;

    r = cr_r(tl, 1);
    pms = ft_strsplit(temp, ' ');
    if (pms && pms[0] && ft_strlen(pms[0]) && pms[1] && ft_strlen(pms[1]) && pms[2])
    {
        tl->pr = ft_strcat(tl->pr, temp);
        tl->pr = ft_strcat(tl->pr,"\n");
        r->n = ft_strdup(pms[0]);
        r->x = (ch_dgts(pms[1])) ? ft_atoi(pms[1]) : -2147483647;
        r->y = (ch_dgts(pms[2])) ? ft_atoi(pms[2]) : -2147483647;
        f = check_room(tl, r);       
    } else
        f = -1;
    free_da(pms);
    return (f);
}

void     cr_rlt(t_l *tl, char *temp)
{
    tl->pr = ft_strcat(tl->pr, temp);
    tl->pr = ft_strcat(tl->pr,"\n");
    if (!tl->rl || ft_strlen(tl->rl) == 0)
        tl->rl = ft_memalloc(sizeof(char) * 100000);
    else
        tl->rl = ft_strcat(tl->rl, "#");
    tl->rl = ft_strcat(tl->rl, temp);
}

t_r      *find_r_by_n(t_l *tl, char *n)
{
    t_r      *tr;

    tr = tl->r;
    while (tr)
    {
        if (n && tr->n && !ft_strcmp(tr->n, n))
            return (tr);
        tr = tr->nx;
    }
    return (NULL);
}

int     relations(t_l *tl, int i)
{
    t_r      *tr1;
    t_r      *tr2;
    char    **pms;
    char    **rel;

    pms = ft_strsplit(tl->rl, '#');
    while (pms[++i])
    {
        rel = ft_strsplit(pms[i], '-');
        if (rel[0] && rel[1])
        {tr1 = find_r_by_n(tl, rel[0]);
        tr2 = find_r_by_n(tl, rel[1]);
        if (rel[0] && rel[1] && (tr1) && (tr2))
        {
            tr1->rl = ft_strcat(tr1->rl, rel[1]);
            tr2->rl = ft_strcat(tr2->rl, rel[0]);  
            tr1->rl = ft_strcat(tr1->rl, "#");
            tr2->rl = ft_strcat(tr2->rl, "#");
        }
        else{
                free_da(rel);
                free_da(pms);
                return (0);
            }
        }
        free_da(rel);
    }
    free_da(pms);
    return (1);
}


int    read_na(t_l *tl, char  *temp, int fd)
{
    tl->c = NULL;
    tl->rl = NULL;
    tl->res = NULL;
    tl->sn = 0;
    tl->en = 0;
    tl->nl = NULL;
    tl->pr = ft_memalloc(sizeof(char) * 200000);
    if (get_next_line(fd, &temp) > 0)
    {
        tl->pr = ft_strcat(tl->pr, temp);
        tl->pr = ft_strcat(tl->pr,"\n");
        tl->na = ft_atoi(temp);
        if (!ch_dgts(temp) || tl->na < 1)
        {
            free(temp);
            return (0);
        }
        free(temp);
        return (1);
    }
    return (0);
}

int     read_data(t_l *tl, char  *temp, int f)
{
    int fd = 0;//open("C:\\Users\\1\\CLionProjects\\lemin2\\test5", O_RDONLY);
    if (!read_na(tl, temp, fd))
        return (0);
    while (get_next_line(fd, &temp) > 0)
    {
        if (ft_strstr(temp, "#") && !ft_strstr(temp, "##"))
            pr_com(tl, temp);
        else
        if (ft_strstr(temp, "##start") || ft_strstr(temp, "##end"))
        {
            if (pr_sw(tl, temp, fd) != 1){
                free(temp);
                return (0);
            }
        } else if (ft_strstr(temp, "-"))
            cr_rlt(tl, temp);
        else if (ft_strstr(temp, "##go"))
        {
            tl->pr = ft_strcat(tl->pr, temp);
            tl->pr = ft_strcat(tl->pr,"\n");
            free(temp);
            break;
        }
        else
        {
            f = cr_room(tl, temp);
            if (f == 0)
            {
                free(temp);
                return (0);
            }
            if (f == -1){
                 free(temp);
                break;
            }
        }
        free(temp);  
    }

    t_r *tr;
    int i = 0;
     /*       if (tl->r){

        tr = tl->r;}
        while (tr)
        {
            ++i;
            if (i > 995 && i < 1100)
                printf("name %s, x = %i,y = %i, iS = %i, isE = %i, f = %i\n", tr->n, tr->x, tr->y, tr->iS, tr->iE, tr->f);
            tr = tr->nx;
        }*/
printf("relations: %s\n", tl->rl);
        if (!relations(tl, -1) || tl->sn != 1 || tl->en != 1)
             return (0);



        printf("tr %p\n", tr);
      printf("tl->r %p  name %s |\n", tl->r, tl->r->n);
    //    printf("trrrrrrrrrrrrrr %p name %s |\n", tr, tr->n);
    //    printf("herehejhfh\n");
     //   } else {
     //       printf("BLYAAAAAAA\n");
     //   }

        write(1,"ar\n", 3);

//_________________________________________________________________________________________________
      printf("\n\nConclusion >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        printf("lemin stucture: na = %i\n", tl->na);
        printf("rooms : \n");

         if (tl->r){

        tr = tl->r;
        }
      //  printf("tr %p\n", tr);
    //  printf("tl->r %p  name %s |\n", tl->r, tl->r->n);
    //    printf("trrrrrrrrrrrrrr %p name %s |\n", tr, tr->n);
    //    printf("herehejhfh\n");
     //   } else {
     //       printf("BLYAAAAAAA\n");
     //   }
      i = 0;
        while (tr)
        {
            ++i;
            if (i > 998 && i < 1100)
                printf("name %s, x = %i,y = %i, iS = %i, isE = %i, f = %i, rl = %s\n", tr->n, tr->x, tr->y, tr->iS, tr->iE, tr->f, tr->rl);
            tr = tr->nx;
        }
        printf("comments: %s\n", tl->c);
      printf("relations: %s\n", tl->rl);
     //  close(fd);
    return (1);
}

