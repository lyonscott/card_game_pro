#include "deck.h"

typedef struct buff Buff;
typedef struct buff_ptr BuffPtr;

struct buff_ptr{
	int len;
	int _max;
	byte *arr[];
};

BuffPtr* buff_ptr_create(const Buff *buf){
    BuffPtr *ptr=(BuffPtr*)malloc(sizeof(BuffPtr)+sizeof(byte*)*buf->len);
    if(ptr==NULL)return NULL;
    ptr->len=0;
    ptr->_max=buf->len;
    return ptr;
}

//0xN0: card value
//0x0N: card count
const byte CARDS[CARDS_VAL_COUNT]={
  0x14,0x24,0x34,0x44,0x54,0x64,0x74,0x84,0x94,0xA4,0xB4,0xC4,0xD4,0xE1,0xF1,
};

static inline int value_of(const byte num){return num&0xF0;}
static inline int count_of(const byte num){return num&0x0F;}
static inline int rrand(int len){return rand()%len;}
static inline void swap(byte *src,byte *to){if(*src==*to)return;*src^=*to;*to^=*src;*src^=*to;}

Buff* buff_create(int len){
    return (Buff*)malloc(sizeof(Buff)+sizeof(byte)*len);
}
void buff_log(Buff *buf){
    printf("(%d)[",buf->len);
    for(int i=0;i<buf->len;++i)
        printf("%02X ",buf->arr[i]);
    printf("]\n");
}

Buff* deck_create(){
    Buff *deck=buff_create(CARDS_VAL_COUNT);
    if(deck==NULL)return deck;
    for(int i=0;i<CARDS_VAL_COUNT;++i)
        deck->arr[i]=CARDS[i];
    deck->len=CARDS_VAL_COUNT;
    return deck;
}

void deck_log(const Buff *deck){
    printf("(%d)[",deck_len(deck));
    for(int i=0;i<deck->len;++i){
        printf("%02X ",deck->arr[i]);
    }
    printf("]\n");
}

int deck_len(const Buff *deck){
    int count=0;
    for(int i=0;i<deck->len;++i){
        count+=count_of(deck->arr[i]);
    }
    return count;
}

static inline BuffPtr* 
collect_by_count(Buff *buf,int count){
    BuffPtr *ptr=buff_ptr_create(buf);
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
move_to(BuffPtr *src,Buff *to,int idx,int count){
    for(int i=0;i<count;++i){
        to->arr[i]=*(src->arr[idx]);
        to->len++;
        (*src->arr[idx])--;
    }
}

static inline Buff*
get_same_by_count(Buff *in,int count,FILTER filter){
    Buff *out=buff_create(count);
    while(out!=NULL){
        out->len=0;
        BuffPtr *bp=collect_by_count(in,count);
        if(bp==NULL)break;
        int idx=rrand(bp->len);
        move_to(bp,out,idx,count);
        break;
    }
    return out;
}

Buff* deck_get_card(Buff *in,int num,FILTER filter){
    return get_same_by_count(in,num,filter);
}