# include "lemin.h"

int     main(void)
{
    t_l tl;
    char *temp;

    tl.sn = 0;
    tl.en = 0;
    if (read_data(&tl, temp))
        process(&tl);
    else
        ft_putstr("Error\n");
    free_lm(&tl);
    return (0);
}