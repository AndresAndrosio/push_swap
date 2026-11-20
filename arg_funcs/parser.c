#include "ft_push_swap.h"
/**
 * pass from str to int, str have to be checked its a int before of use it 
 * @param begin_at: pointer of the begging number (a sign or number)
 * @param end_at: char pointer after the last number, its a space or a null byte
 * @return the number
 */
static int strtoint(char *begin_at,char *end_at)
{
    long result;
    int sign;
    result=0;

    sign=1;
    if(*begin_at=='-')
        sign=-1;
    if(*begin_at=='-' || *begin_at=='+')
        begin_at++;
    while(begin_at!=end_at){
        result=result*10+(*begin_at-'0');
        begin_at++;
    }
    return (int)(result*sign);
}

t_stack **parser(int argc,char *argv[],t_stack **a)
{
    int i_arg;
    int i_char;
    char *num_start_at;
    char *num_end_at;

    (i_arg=1,i_char=0,num_start_at=NULL,num_end_at=NULL);
    while(i_arg<argc){
        while(argv[i_arg][i_char] != '\0')
        {
            if(num_start_at==NULL 
                && (ft_isdigit(argv[i_arg][i_char])
                    || argv[i_arg][i_char]=='+' || argv[i_arg][i_char]=='-'))
                    num_start_at=&argv[i_arg][i_char];
            if(num_start_at != NULL 
                && (argv[i_arg][i_char+1]==' ' || argv[i_arg][i_char+1]=='\0'))
                {
                    num_end_at=&argv[i_arg][i_char+1];
                    add_node(a,strtoint(num_start_at,num_end_at));
                    num_start_at=NULL;
                }
            i_char++;
        }
        (i_char=0, i_arg++);
    }
    return a;
}
