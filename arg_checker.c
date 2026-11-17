#include "ft_push_swap.h"
#include "stdio.h"

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
static int contain_prohibit_char(int argc,const char *argv[])
{
    int i_arg;
    int i_char;

    i_arg=1;
    i_char=0;
    while(i_arg<argc){
        while(argv[i_arg][i_char] != '\0')
        {
            if(argv[i_arg][i_char]!= ' ' 
                && !ft_isalnum(argv[i_arg][i_char]) 
                && (argv[i_arg][i_char]!= '+' 
                && argv[i_arg][i_char]!= '-'
            ))
                return 1;
        }
        i_char=0;
        i_arg++;
    }
    return 0;
}
/**
 * @return char*: when argv contain wrong numbers like: - -1231-2 - +21343 + +-21314 --1231 -+21343 ++-21314 + -
 * NULL: when argv contain good numbers like: -1234 or +1234 [no space and only one sign and before sign atleast one space firtst element is not included]
 */
static char * wrong_number_format(int argc,char *argv[])
{
    int i_arg;
    int i_char;
    int in_space;
    int in_number;
    unsigned int sign_amount;
    
    (i_arg=1, i_char=0, sign_amount=0, in_number=0);
    while(i_arg<argc){
        while(argv[i_arg][i_char] != '\0')
        {
            if(sign_amount<=1 && ft_isdigit(argv[i_arg][i_char]))
                (sign_amount=0,in_number=1,in_space=0);
            if(argv[i_arg][i_char]=='+'|| argv[i_arg][i_char]=='-')
                (sign_amount++,in_space=0);
            if(argv[i_arg][i_char]==' ')
                (in_space=1,in_number=0);
            if(i_arg > 0)
                if(sign_amount>1 || (sign_amount && in_space) || (in_number && sign_amount>0)
                    || (sign_amount==1 && !ft_isalnum(argv[i_arg][i_char+1])))
                    return (char *)argv[i_arg];
            i_char++;
        }
        (i_char=0, i_arg++);
    }
    return NULL;
}

int check_arg(int argc,char *argv[]){
    if(argc<=1)
        return 0;
    if(contain_prohibit_char(argc,argv)==1 
    || wrong_number_format(argc,argv) != NULL)
    {
        ft_putendl_fd("Error",2);
        return 0;
    }
    return 1;
}