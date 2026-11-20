#include "ft_push_swap.h"

// unsigned int amount_of_number(const char * str)
// {
//     unsigned int number_amount;
//     int in_space;
//     int sign;

//     sign=0;
//     in_space=0; 
//     number_amount=0;
//     while(*str){
//         if(((in_space==1 || sign==1)|| (number_amount==0)) && *str>='0' && *str<='9'){
//             if(sign)
//                 sign=0;
//             if(in_space)
//                 in_space=0;
//             number_amount++;
//         }
//         if(*str=='+'|| *str=='-')
//             sign=1;
//         if(*str==' ')
//             in_space=1;
//         str++;
//     }
//     return number_amount;
// }
// static int	*ft_atoim(const char *str)
// {
// 	int	*result;
// 	int	sign;

// 	result = malloc(sizeof(int));
// 	if (!result)
// 		return (NULL);
// 	sign = 1;
// 	*result = 0;
// 	while (*str == ' ' || (*str >= 9 && *str <= 13))
// 		str++;
// 	if (*str == '+' || *str == '-')
// 	{
// 		if (*str == '-')
// 			sign = -1;
// 		str++;
// 	}
// 	while (*str >= '0' && *str <= '9')
// 	{
// 		*result = *result * 10 + (*str - '0');
// 		str++;
// 	}
// 	*result *= sign;
// 	return (result);
// }
/**
 * argv contain other than - + 0 to 9 character
 */
/**
 * we do not evaluate the max and min because it doesnt care here the overflow
 */

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