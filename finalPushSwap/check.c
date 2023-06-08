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
static int check_zero(char *av){
    int i;

    i = 0;
    if(ft_issign(av[i]))
        i++;
    while(av[i] && av[i] == '0')
        i++;
    if(av[i] != '\0')
        return (0);
    return(1);
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

int ft_isCorrectInput(char *av){
    int i;
    int nbZero;

    i = 1;
    nbZero = 0;
    while(av[i])
    {
        if(!ft_isdigit(av[i]))
            return (0);
        nbZero += check_zero(av[i]);
        i++;
    }
    if(ft_checkDuplicate(av[i]))
        return(0);
    return(1);
}