#include "pdfl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_type(const char *str,int len){

}
void parse_expand(const char *str,int len){

}

void parse_body(const char *str,int start,int end){

}
void parse_chunk(const char *str,int start,int end){

}

struct context{
    char *fp;
    char *cp;
    char *ep;
};

static inline int 
context_ended(const struct context *ctx){
    return(ctx->cp>=ctx->ep);
}
static inline struct context 
context_create(const char *stream){
    struct context ctx;
    ctx.fp=stream;
    ctx.cp=ctx.fp;
    ctx.ep=ctx.fp+strlen(stream);
    return ctx;
}

#define CH_DRAW(ch) ((ch)=='+')
#define CH_NOTE(ch) ((ch)=='#')
#define CH_MARK(ch) (CH_DRAW(ch)||CH_NOTE(ch))
#define CH_CHAR(ch) ((ch)>='a'&&(ch)<='z')
#define CH_DIGIT(ch) ((ch)>='0'&&(ch)<='9')
#define CH_HEXDIG(ch) (CH_DIGIT(ch)||((ch)>='A'&&(ch)<='F'))
#define CH_RULE(ch) ((ch)=='(')
#define CH_RULE_END(ch) ((ch)==')')
#define CH_ENDLINE(ch) ((ch)=='\n')
#define CH_SPLIT(ch) ((ch)==',')
#define CH_RANGE(ch) ((ch)=='~')

void digit(struct context *ctx){
    if(CH_DIGIT(*ctx->cp)){
        printf("digit:%c\n",*ctx->cp);
        ++ctx->cp;
    }
}
void hexdig(struct context *ctx){
    if(CH_HEXDIG(*ctx->cp)){
        printf("hexdig:%c\n",*ctx->cp);
        ++ctx->cp;
    }
}
void range(struct context *ctx){
    if(CH_RANGE(*ctx->cp)){
        printf("start range\n");
        ++ctx->cp;
        while(CH_HEXDIG(*ctx->cp)){
            hexdig(ctx);
        }
        printf("end range\n");
    }
}
void type(struct context *ctx){
    if(CH_CHAR(*ctx->cp)){
        printf("type:");
        while(CH_CHAR(*ctx->cp)){
            printf("%c",*ctx->cp);
            ++ctx->cp;
        }
        printf("\n");
    }
}

void rule(struct context *ctx){
    if(CH_RULE(*ctx->cp)){
        printf("start rule\n");
        ++ctx->cp;
        while(!CH_RULE_END(*ctx->cp)){
            hexdig(ctx);
            range(ctx);
            type(ctx);
            if(CH_SPLIT(*ctx->cp)){
                ++ctx->cp;
            }
        }
        printf("end rule\n");
        ++ctx->cp;
    }
}

void body(struct context *ctx){
    type(ctx);
    digit(ctx);
    rule(ctx);
}

void chunk(struct context *ctx){
    while(!context_ended(ctx)){
        body(ctx);
        ++ctx->cp;
    }
}

//filter
typedef struct filter Filter;

struct filter*
filter_create(){
    Filter *filter=(Filter*)malloc(sizeof(Filter));
    if(filter==NULL)return NULL;
    memset(filter,0,sizeof(Filter));
    return filter;
}

void filter_add_limit(struct filter *filter,u8 mark){filter->limit|=mark;}
void filter_add_expand(struct filter *filter,u8 mark){filter->expand|=mark;}