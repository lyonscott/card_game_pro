#include "pdfl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct str_chunk{
    const char *ptr;
    int len;
}StrChunk;

StrChunk* chunk_match(const char *str,int len,const char start,const char end){
    StrChunk *chunk=(StrChunk*)malloc(sizeof(StrChunk));
    if(chunk==NULL)return NULL;
    chunk->ptr=str;
    while(len){
        char c=*(chunk->ptr);
        if(c==start)break;
        ++(chunk->ptr);
        --len;
    }
    if(chunk->ptr==NULL)goto ERR;
    chunk->len=0;
    while(len){
        char c=*(chunk->ptr+chunk->len);
        ++(chunk->len);
        --len;
        if(c==end)break;
    }
    goto OK;
    ERR:{
        free(chunk);
        return NULL;
    }
    OK:{
        return chunk;
    }
}
void parse_number(){

}
void parse_list(){

}
void parse_range(){

}
void parse_limit(){

}
void parse_type(const char *str,int len){
    int idx=0;
    while(idx<len){
        char ch=*(str+idx);
        if(ch<'a'||ch>'z')break;
        idx++;
    }
    char buf[4];memset(buf,'\0',sizeof(char)*4);
    strncpy(buf,str,idx);
    printf("%s\n",buf);
}
void parse_expand(const char *str,int len){
    int idx=0;
    while(idx<len){
        char c=*(str+idx);
        if(c=='('){
            break;
        }
        idx++;
    }
    while(idx<len){
        char c=*(str+idx);
        if(c==')'){
            break;
        }
        idx++;
    }
}

void parse_body(const char *str,int start,int end){

}
void parse_chunk(const char *str,int start,int end){

}
//TODO parser_fsm
enum{
    MARK_USING,
    MARK_UNUSING,
    MARK_NOTE,
    MARK_END_LINE,
    MARK_TYPE,
    MARK_NUMBER,
    MARK_START_LIMIT,
    MARK_END_LIMIT,
    MARK_START_EXPAND,
    MARK_END_EXPAND,
};
void parser_fsm(const char *str,int len){
    int idx=0;
    while(idx<len){
        char c=*(str+idx);
        
        idx++;
    }
}

void pdfl_parser(const char *str,int len){
    int idx=0;
    StrChunk *chunk=chunk_match(str,len,'+','#');
    parse_type(chunk->ptr,chunk->len);
    for(int i=0;i<chunk->len;++i){
        char c=*(chunk->ptr+i);
        printf("%c",c);
    }
    printf("\n");
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