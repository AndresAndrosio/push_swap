#include "ft_push_swap.h"

long strtolong(char *begin_at,char *end_at)
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
    return (result*sign);
}

int find_num_in_argv(char *argv[],long num,int i_arg,int i_char)
{
    char * num_begin_at;
    long num2;

    (num_begin_at=NULL);
     while(argv[i_arg]!=NULL){
        while(argv[i_arg][i_char] != '\0')
        {
           if(num_begin_at==NULL && (ft_isdigit(argv[i_arg][i_char])
                    || argv[i_arg][i_char]=='+' || argv[i_arg][i_char]=='-'))
                num_begin_at=&argv[i_arg][i_char];
           if(num_begin_at != NULL 
                && (argv[i_arg][i_char+1]==' ' || argv[i_arg][i_char+1]=='\0'))
                {
                    num2=strtolong(num_begin_at,&argv[i_arg][i_char+1]);
                    if(num==num2)
                        return 1;
                    num_begin_at=NULL;
                }
            i_char++;
        }
        (i_char=0, i_arg++);
    }
    return 0;
}