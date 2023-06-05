#include "push_swap.h"

static int check_num(char *av)
{
    int i;

    i = 0;
    if(ft_issign(av[i]))
        i++;
    while(av[i] == '\0' && ft_isdigit(av[i]))
        i++;
    if(av[i] != '\0' && !ft_isdigit(av[i])){
        ft_putchar("Error, is not a number");
        return (0);
    }
    return (1);
}

bool ft_checkDuplicate(char *av){
    int i;
    int j;

    i = 0;
    while(av[i])
    {
        j = i + 1;
        while(av[i])
        {
            if(av[i] == av[j])
                return true;
            j++;
        }
        i++;
    }
    return false;
}