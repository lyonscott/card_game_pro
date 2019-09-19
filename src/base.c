#include "base.h"

typedef struct buff_ptr BuffPtr;

struct buff* 
buff_create(int len){
    return (struct buff*)malloc(sizeof(struct buff)+sizeof(byte)*len);
}
void buff_delete(struct buff *buf){
    free(buf);
    buf=NULL;
}
void buff_log(struct buff *buf){
    printf("(%d)[",buf->len);
    for(int i=0;i<buf->len;++i)
        printf("%02X ",buf->arr[i]);
    printf("]\n");
}

struct buff_ptr* 
buff_ptr_create(const struct buff *buf){
    BuffPtr *ptr=(BuffPtr*)malloc(sizeof(BuffPtr)+sizeof(byte*)*buf->len);
    if(ptr==NULL)return NULL;
    ptr->len=0;
    ptr->_max=buf->len;
    return ptr;
}
void buff_ptr_delete(struct buff_ptr *ptr){
    free(ptr);
    ptr=NULL;
}
