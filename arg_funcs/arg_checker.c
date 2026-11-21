#include "ft_push_swap.h"

int check_arg(int argc,char *argv[]){
    if(argc<=1 
    ||is_empty_arg(argc,argv)
    || contain_prohibit_char(argc,(const char **)argv)
    || wrong_number_format(argc,argv) != NULL ||
    !have_only_int_nums(argc,argv)
    ||number_duplicated(argc,argv)
    )
    {
        ft_putendl_fd("Error",2);
        return 0;
    }

    return 1;
}