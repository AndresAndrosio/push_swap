#include "ft_push_swap.h"

int contain_prohibit_char(int argc,const char *argv[])
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
            i_char++;
        }
        i_char=0;
        i_arg++;
    }
    return 0;
}

char * wrong_number_format(int argc,char *argv[])
{
    int i_arg;
    int i_char;
    int in_space;
    int in_number;
    unsigned int sign_amount;
    
    (i_arg=1, i_char=0, sign_amount=0,in_space=0, in_number=0);
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

int have_only_int_nums(int argc,char *argv[])
{
    int i_arg;
    int i_char;
    char * num_begin_at;
    long num;

    (i_arg=1, i_char=0,num_begin_at=NULL);
     while(i_arg<argc){
        while(argv[i_arg][i_char] != '\0')
        {
           if(num_begin_at==NULL && (ft_isdigit(argv[i_arg][i_char])
                    || argv[i_arg][i_char]=='+' || argv[i_arg][i_char]=='-'))
                num_begin_at=&argv[i_arg][i_char];
           if(num_begin_at != NULL 
                && (argv[i_arg][i_char+1]==' ' || argv[i_arg][i_char+1]=='\0'))
                {
                    num=strtolong(num_begin_at,&argv[i_arg][i_char+1]);
                    if(num<INT_MIN || num>INT_MAX)
                        return 0;
                    num_begin_at=NULL;
                }
            i_char++;
        }
        (i_char=0, i_arg++);
    }
    return 1;
}

int number_duplicated(int argc,char *argv[])
{
    int i_arg;
    int i_char;
    char * num_begin_at;
    long num;

    (i_arg=1, i_char=0,num_begin_at=NULL);
     while(i_arg<argc){
        while(argv[i_arg][i_char] != '\0')
        {
           if(num_begin_at==NULL && (ft_isdigit(argv[i_arg][i_char])
                    || argv[i_arg][i_char]=='+' || argv[i_arg][i_char]=='-'))
                num_begin_at=&argv[i_arg][i_char];
           if(num_begin_at != NULL 
                && (argv[i_arg][i_char+1]==' ' || argv[i_arg][i_char+1]=='\0'))
                {
                    num=strtolong(num_begin_at,&argv[i_arg][i_char+1]);
                    if(find_num_in_argv(argv,num,i_arg,i_char+1))
                        return 1;
                    num_begin_at=NULL;
                }
            i_char++;
        }
        (i_char=0, i_arg++);
    }
    return 0;
}

int is_empty_arg(int argc,char *argv[])
{
    int i_arg;
    int i_char;

    (i_arg=1, i_char=0);
    while(i_arg<argc){
        while(argv[i_arg][i_char] != '\0')
        {
            if(argv[i_arg][i_char]!=' ')
                return 0;
            i_char++;
        }
        (i_char=0, i_arg++);
    }
    return 1;
}