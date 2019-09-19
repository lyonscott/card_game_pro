#include "deck.h"

typedef struct buffer buffer;
typedef struct buffer_ptr bufferPtr;

//random
static unsigned long _deck_hold_seed=1;
void deck_srand(unsigned int num){_deck_hold_seed=num;}
static inline unsigned int _rand(){
    _deck_hold_seed=((_deck_hold_seed*214013+2531011)>>16)&0x7FFF;
    return (unsigned int)_deck_hold_seed;
}
static inline int _rrand(int len){return _rand()%len;}

//0xN0: card value
//0x0N: card count
const u8 CARDS[CARDS_VAL_COUNT]={
  0x14,0x24,0x34,0x44,0x54,0x64,0x74,0x84,0x94,0xA4,0xB4,0xC4,0xD4,0xE1,0xF1,
};

static inline int value_of(const u8 num){return num&0xF0;}
static inline int count_of(const u8 num){return num&0x0F;}
static inline void swap(u8 *src,u8 *to){if(*src==*to)return;*src^=*to;*to^=*src;*src^=*to;}

buffer* deck_create(){
    buffer *deck=buffer_create(CARDS_VAL_COUNT);
    if(deck==NULL)return deck;
    for(int i=0;i<CARDS_VAL_COUNT;++i)
        deck->arr[i]=CARDS[i];
    deck->len=CARDS_VAL_COUNT;
    return deck;
}

void deck_log(const buffer *deck){
    printf("(%d)[",deck_len(deck));
    for(int i=0;i<deck->len;++i){
        printf("%02X ",deck->arr[i]);
    }
    printf("]\n");
}

int deck_len(const buffer *deck){
    int count=0;
    for(int i=0;i<deck->len;++i){
        count+=count_of(deck->arr[i]);
    }
    return count;
}

static inline bufferPtr* 
collect_by_count(buffer *buf,int count){
    bufferPtr *ptr=buffer_ptr_create(buf);
    if(ptr==NULL)return ptr;
    for(int i=0;i<buf->len;++i){
        if(count_of(buf->arr[i])>=count){
            ptr->arr[ptr->len]=&buf->arr[i];
            ptr->len++;
        }
    }
    return ptr;
}

static inline void
move_to(bufferPtr *src,buffer *to,int idx,int count){
    for(int i=0;i<count;++i){
        to->arr[i]=*(src->arr[idx]);
        to->len++;
        (*src->arr[idx])--;
    }
}

static inline buffer*
get_same_by_count(buffer *in,int count,FILTER filter){
    buffer *out=buffer_create(count);
    while(out!=NULL){
        out->len=0;
        bufferPtr *bp=collect_by_count(in,count);
        if(bp==NULL)break;
        int idx=_rrand(bp->len);
        move_to(bp,out,idx,count);
        buffer_ptr_delete(bp);
        break;
    }
    return out;
}

buffer* deck_get_card(buffer *in,int num,FILTER filter){
    return get_same_by_count(in,num,filter);
}