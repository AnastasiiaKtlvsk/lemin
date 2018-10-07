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

int     ch_dgts(char *s)
{
    int i;

    i = -1;
    while (s[++i])
    {
        if ((s[i] > 57 || s[i] < 48) &&
        s[i] != ' ' && s[i] != '-' && s[i] != 13) {
            return (0);
        }
    }
    return (1);
}

int     check_room(t_l *tl, t_r *nr)
{
    t_r *tr;

    printf("add_r\n");

    printf("check_room\n");
    if (tl->r){
	    tr = tl->r;
    }
	if (nr && nr->n && nr->x > -2147483648
    && nr->y > -2147483648)
	{
        nr->st = 0;
        nr->rl = ft_memalloc(sizeof(char) * 2048);
         printf("check_room 2\n"); 
        while (tl->r && tr)
        {
            if ((nr->x == tr->x && nr->y == tr->y) || nr->n == tr->n){
             printf("check_room return 0 1\n"); 
                return (0);
            }
            tr = tr->nx;
        }
         printf("<<<<<<<<<<<<<   name %s, x = %i,y = %i, iS = %i, isE = %i, f = %i\n", nr->n, nr->x, nr->y, nr->iS, nr->iE, nr->f);
		 nr->nx = (tl->r) ? tl->r : NULL;
		 tl->r = nr;
        return (1);
	}
     printf("check_room return 0 2\n"); 
    return (0);
}


void    pr_com(t_l *tl, char *temp)
{
    printf("pr_sw temp = %s\n", temp);
    if (!tl->c)
        tl->c = ft_memalloc(sizeof(char) * 2048);
    tl->c = ft_strcat(tl->c, ft_strdup(ft_strchr(temp, '#') + 1)); 
    tl->c = ft_strcat(tl->c, ft_strdup("\n"));
}

int     pr_sw(t_l *tl, char *temp, int i)
{
    char    *line;
    t_r     *r;
    char    **pms;

    r = ft_memalloc(sizeof(t_r));
    if (get_next_line(0, &line) > 0)
    {
        pms = ft_strsplit(line, ' ');
        if (pms[0] && pms[1] && pms[2]){
             r->n = ft_strdup(pms[0]);
             r->x = (ch_dgts(pms[1])) ? ft_atoi(pms[1]) : -2147483648;
              r->y = (ch_dgts(pms[2])) ? ft_atoi(pms[2]) : -2147483648;
              printf("r:  name = %s  x = %i  y = %i \n",  r->n, r->x, r->y);
              if (ft_strstr(temp, "start"))
               {
                   tl->sn++;
                    r->iS = 1;
                   r->iE = 0;
                     r->f = tl->na;
                }
                if (ft_strstr(temp, "end"))
                {
                    tl->en++;
                    r->iS = 0;
                      r->f = 0;
                   r->iE = 1;
               }
               while (++i < 3)
                  free(pms[i]);
                free(line);
             if (check_room(tl, r)){
                 printf("tl->r  check_room check_room check_room check_room %s\n",(tl->r->n));
                 return (1);
           }
      }
    }
    printf("pr_sw return 0\n");
    return (0);   
}

int     cr_room(t_l *tl, char *temp)
{
    char    **pms;
    t_r     *r;
    int i;

    r = ft_memalloc(sizeof(t_r));
    pms = ft_strsplit(temp, ' ');
    r->n = (pms[0]) ? ft_strdup(pms[0]) : NULL;
    r->x = (pms[1] && ch_dgts(pms[1])) ? ft_atoi(pms[1]) : -2147483648;
    r->y = (pms[2] && ch_dgts(pms[2])) ? ft_atoi(pms[2]) : -2147483648;
    printf("r:  name = %s  x = %i  y = %i \n",  r->n, r->x, r->y);
    r->iS = 0;
    r->iE = 0;
    r->f = 0;
    i = -1;
    while (++i < 3)
        free(pms[i]);
    if (check_room(tl, r)){
        printf("tl->r  check_room check_room check_room check_room %p\n",(tl->r));
        printf("tl->r  check_room check_room check_room check_room %s\n",(tl->r->n));
        return (1);
    }
    return (0);
}

void     cr_rlt(t_l *tl, char *temp)
{
    printf("cr_rlt temp = %s\n", temp);
    
     if (!tl->rl)
        tl->rl = ft_memalloc(sizeof(char) * 2048);
    tl->rl = ft_strcat(tl->rl, ft_strdup(temp)); 
    tl->rl = ft_strcat(tl->rl, "#");
}

t_r      *find_r_by_n(t_l *tl, char *n)
{
    t_r      *tr;
 //   printf("FIND BY NAME --- name = %s\n", n);
    tr = tl->r;
    while (tr)
    {
      //  printf("cycle\n");
        if (!ft_strcmp(tr->n, n)){
  //          printf("find r by n 1\n");
            return (tr);
        }
        tr = tr->nx;
    }
    printf("return 0\n");
    return (NULL);
}

int     relations(t_l *tl)
{
    int i;
    t_r      *tr1;
    t_r      *tr2;
    char    **pms;
    char    **rel;

    printf("RELATIONS RELATIONS RELATIONS !!!!!!!!!!!!!!!!\n");
    i = -1;
    pms = ft_strsplit(tl->rl, '#');
    while (pms[++i])
    {
        printf("RELATIONS RELATIONS RELATIONS wwwwhhhhhiiiilllleee\n");
        rel = ft_strsplit(pms[i], '-');
        printf("r00000000 %s 1 %s 2 %s\n",rel[0], rel[1], rel[2]);
        if (rel[0] && rel[1] && (tr1 = find_r_by_n(tl, rel[0])) && (tr2 = find_r_by_n(tl, rel[1]))){
            printf("RELATIONS RELATIONS RELATIONS iiiiiiiiiiifffffffff\n");
            tr1->rl = ft_strcat(tr1->rl, ft_strdup(rel[1]));
            tr2->rl = ft_strcat(tr2->rl, ft_strdup(rel[0]));
            ft_strcat(tr1->rl, "#");
            ft_strcat(tr2->rl, "#");
        }
        else {
            printf("ret 0 -------- 000000 relations");
            return (0);
        }
    }
    printf("ret 1 -------- relations");
    return (1);
}



int     read_data(t_l *tl)
{
    char    *temp;

    tl->sn = 0;
    tl->en = 0;
    write(1, "read\n", 6);
   // int fd = open("test", O_RDONLY);

    if (get_next_line(0, &temp) > 0)
    {
        tl->na = ft_atoi(temp);
        if (!ch_dgts(temp) || tl->na < 1)
            return (0);
        free(temp);
        printf("tl->na %i\n", tl->na);
    }
    while (get_next_line(0, &temp) > 0)
    {
        printf("while\n");
        if (temp[0] == '#' && temp[1] != '#')
            pr_com(tl, temp);
        else if (ft_strstr(temp, "##start") || ft_strstr(temp, "##end"))
        {
            if (pr_sw(tl, temp, -1) != 1)
                return (0);
        }         //   printf("\n\nRRRRRRRRRRRRRRREEEEEEEEESSSSUUUULLLLTTTTTTTTT %i\n\n", );
        else if (ft_strstr(temp, "-") && !ft_strchr(temp, ' '))
            cr_rlt(tl, temp);
        else 
            cr_room(tl, temp);
        free(temp);
    } 
   
    if (!relations(tl) || tl->sn != 1 || tl->en != 1)
        return (0);


    printf("\n\nConclusion >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("lemin stucture: na = %i\n", tl->na);
    printf("rooms : \n");
    t_r *tr;
      if (tl->r){
    tr = tl->r;
    printf("tr %p\n", tr);
  printf("tl->r %p  name %s |\n", tl->r, tl->r->n);
    printf("trrrrrrrrrrrrrr %p name %s |\n", tr, tr->n);
    printf("herehejhfh\n");
    } else {
        printf("BLYAAAAAAA\n");
    }
    while (tr)
    {
        printf("name %s, x = %i,y = %i, iS = %i, isE = %i, f = %i, rl = %s\n", tr->n, tr->x, tr->y, tr->iS, tr->iE, tr->f, tr->rl);
        tr = tr->nx;
    }
    printf("comments: %s\n", tl->c);
  printf("relations: %s\n", tl->rl);
  //  close(fd);*/
    return (1);
}

