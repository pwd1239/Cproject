#include "push_swap.h"

int check_num(char *av)
{
    int i;

    i = 0;
    if(ft_issign(av[i]) && av[i + 1] != '\0')
        i++;
    while(av[i] == '\0' && ft_isdigit(av[i]))
        i++;
    if(av[i] != '\0' && !ft_isdigit(av[i]))
    {
        write(1, "Error, is not a number", 23);
        return (0);
    }
    return (1);
}

int check_zero(char *av){
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

int  ft_checkDuplicate(char *av){
    int i;
    int j;

    i = 0;
    while(av[i])
    {
        j = i + 1;
        while(av[i])
        {
            if(av[i] == av[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int ft_isCorrectInput(char **av){
    int i;
    int nbZero;

    i = 1;
    nbZero = 0;
    while(av[i])
    {
        if(!check_num(av[i]))
            return (0);
        nbZero += check_zero(av[i]);
        i++;
    }
    if(nbZero > 1)
        return (0);
    if(ft_checkDuplicate(av[i]))
        return(0);
    return(1);
}