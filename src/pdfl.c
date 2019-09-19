#include "pdfl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct str_chunk{
    const char *ptr;
    int len;
}StrChunk;

typedef struct str_pattern{
    struct str_chunk start;
    struct str_chunk end;
}StrPattern;

StrChunk* chunk_match(const char *str,int len,const char start,const char end){
    StrChunk *chunk=(StrChunk*)malloc(sizeof(StrChunk));
    if(chunk==NULL)return NULL;
    int idx=0;
    while(idx<len){
        char c=*(str+idx);
        if(c==start){
            idx++;
            chunk->ptr=(str+idx);
            chunk->len=0;
            break;
        }
        idx++;
    }
    if(chunk->ptr==NULL)goto ERR;
    while(idx<len){
        char c=*(str+idx);
        if(c==end)break;
        idx++;
        chunk->len++;
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
void parser_number(){

}
void parser_list(){

}
void parser_range(){

}
void parser_limit(){

}
void parser_types(const char *str,int len){
    int idx=0;
    while(idx<len){
        char c=*(str+idx);
        if(c<'a'||c>'z')break;
        idx++;
    }
    char buf[4];memset(buf,'\0',sizeof(char)*4);
    strncpy(buf,str,idx);
    printf("%s\n",buf);
}
void parser_expand(const char *str,int len){
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

void parser_body(const char *str,int start,int end){

}
void parser_chunk(const char *str,int start,int end){

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
    parser_types(chunk->ptr,chunk->len);
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

void filter_add_limit(struct filter *filter,byte mark){filter->limit|=mark;}
void filter_add_expand(struct filter *filter,byte mark){filter->expand|=mark;}