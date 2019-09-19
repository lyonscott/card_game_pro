#include "base.h"

typedef struct buffer_ptr bufferPtr;

struct buffer* 
buffer_create(int len){
    return (struct buffer*)malloc(sizeof(struct buffer)+sizeof(u8)*len);
}
void buffer_delete(struct buffer *buf){
    free(buf);
    buf=NULL;
}
void buffer_log(struct buffer *buf){
    printf("(%d)[",buf->len);
    for(int i=0;i<buf->len;++i)
        printf("%02X ",buf->arr[i]);
    printf("]\n");
}

struct buffer_ptr* 
buffer_ptr_create(const struct buffer *buf){
    bufferPtr *ptr=(bufferPtr*)malloc(sizeof(bufferPtr)+sizeof(u8*)*buf->len);
    if(ptr==NULL)return NULL;
    ptr->len=0;
    ptr->_max=buf->len;
    return ptr;
}
void buffer_ptr_delete(struct buffer_ptr *ptr){
    free(ptr);
    ptr=NULL;
}
