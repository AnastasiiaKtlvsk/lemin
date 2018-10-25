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

void	free_da(char **arr)
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

int		ch_dgts(char *s, int f)
{
	int i;

	i = -1;
	while (s[++i])
	{
		if ((s[i] > 57 || s[i] < 48) &&
		s[i] != ' ' && s[i] != '-' && s[i] != 13)
			return (0);
		if (s[i] == '-' && f == 0)
			return (0);
	}
	return (1);
}

t_r		*cr_r(t_l *tl, int t, char *n)
{
	t_r     *r;

	r = ft_memalloc(sizeof(t_r));
	(r->n) = ft_strdup(n);
	r->iS = (t == 0) ? 1 : 0;
	(t == 0) ? tl->st = ft_strdup(n) : 0;
	(t == 2) ? tl->ed = ft_strdup(n) : 0;
	r->iE = (t == 2) ? 1 : 0;
	r->f = (t == 0) ? tl->na : 0;
	r->st = 0;
	r->nx = NULL;
    r->pth = ft_memalloc(sizeof(char) * 100000);
	return (r);
}

int		check_room(t_l *tl, t_r *nr)
{
	t_r *tr;

	if (tl->r)
		tr = tl->r;
	if (nr && nr->n && nr->x > -2147483647
	&& nr->y > -2147483647)
	{
		while (tl->r && tr)
		{
			if ((nr->x == tr->x && nr->y == tr->y) || nr->n == tr->n){
				return (0);
			}
			tr = tr->nx;
		}
		 nr->rl = ft_memalloc(sizeof(char) * 2000000);
		 nr->nx = (tl->r) ? tl->r : NULL;
		 tl->r = nr;
		 return (1);
	}
	return (0);
}


void    pr_com(t_l *tl, char *temp)
{
    int cs;
    
    cs = ft_strlen(tl->c);
	if (cs < 2 || (cs > 300 && cs > tl->cs - 300))
		rell_c(tl);
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
		if (pms[0] && pms[1] && pms[2] && !pms[3])
		{
			r = (ft_strstr(temp, "start")) ? cr_r(tl, 0, pms[0]) : cr_r(tl, 2, pms[0]);
			(ft_strstr(temp, "start")) ? tl->sn++ : tl->en++;
			 r->x = (ch_dgts(pms[1], 1)) ? ft_atoi(pms[1]) : -2147483647;
			 r->y = (ch_dgts(pms[2], 1)) ? ft_atoi(pms[2]) : -2147483647;
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

	pms = ft_strsplit(temp, ' ');
	if (pms && pms[0] && ft_strlen(pms[0]) && pms[1] && ft_strlen(pms[1]) && pms[2] && !pms[3])
	{
		r = cr_r(tl, 1, pms[0]);
		tl->pr = ft_strcat(tl->pr, temp);
		tl->pr = ft_strcat(tl->pr,"\n");
		r->x = (ch_dgts(pms[1], 1)) ? ft_atoi(pms[1]) : -2147483647;
		r->y = (ch_dgts(pms[2], 1)) ? ft_atoi(pms[2]) : -2147483647;
		f = check_room(tl, r);
	} else
		f = -1;
	free_da(pms);
	return (f);
}

void     cr_rlt(t_l *tl, char *temp)
{
    int rl;

    rl = ft_strlen(tl->rl);
    if (rl < 2 || (rl > 300 && rl > tl->crl - 300))
        rell_rl(tl);
	tl->pr = ft_strcat(tl->pr, temp);
	tl->pr = ft_strcat(tl->pr,"\n");
	if (rl > 0)
        tl->rl = ft_strcat(tl->rl, "#");
	tl->rl = ft_strcat(tl->rl, temp);
}

t_r      *find_r_by_n(t_l *tl, char *n)
{
	t_r      *tr;

	tr = tl->r;
	t_r *yr = tl->r;
			  
	while (tr)
	{
		if (n && tr->n && !ft_strcmp(tr->n, n) && tr->iS > -5 && tr->iE > -5){
			return (tr);
		}
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
	tl->c = ft_memalloc(sizeof(char) * 50000);
    tl->cs = 50000;
	tl->rl = ft_memalloc(sizeof(char) * 50000);
    tl->crl = 50000;
    tl->pr = ft_memalloc(sizeof(char) * 50000);
    tl->cpr = 50000;
	tl->res = NULL;
	tl->sn = 0;
	tl->en = 0;
	tl->nl = NULL;
	tl->r = NULL;
	tl->st = NULL;
	tl->ed = NULL;
	if (get_next_line(fd, &temp) > 0)
	{
		tl->pr = ft_strcat(tl->pr, temp);
		tl->pr = ft_strcat(tl->pr,"\n");
		tl->na = ft_atoi(temp);
		if (!ch_dgts(temp, 0) || tl->na < 1)
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
	int fd = 0;
    int pr;

	if (!read_na(tl, temp, fd))
		return (0);
	while (get_next_line(fd, &temp) > 0)
	{
        pr = ft_strlen(tl->pr);
        if (pr > 300 && pr > tl->cpr - 300)
            rell_pr(tl);
		if (ft_strstr(temp, "#") && !ft_strstr(temp, "##"))
			pr_com(tl, temp);
		else
		if (ft_strstr(temp, "##start") || ft_strstr(temp, "##end"))
		{
			if (pr_sw(tl, temp, fd) != 1){
				free(temp);
				return (0);
			}
		} else if (ft_strstr(temp, "-")){
			cr_rlt(tl, temp);
        }
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
      
	if (!relations(tl, -1) || tl->sn != 1 || tl->en != 1)
		return (0);
	return (1);
}

