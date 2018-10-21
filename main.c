# include "lemin.h"

int     main(void)
{
    t_l tl;
    char *temp;

    if (read_data(&tl, temp, 1)) {
        process(&tl);
    }
    else
        ft_putstr("Error\n");
    free_lm(&tl);
    return (0);
}