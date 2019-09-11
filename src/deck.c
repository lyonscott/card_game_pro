#include "deck.h"

typedef struct buff Buff;
typedef struct buff_ptr BuffPtr;

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
    for(int i=0;i<buf->len;++i){
        printf("%02X ",buf->arr[i]);
    }
    printf("]\n");
}

BuffPtr* buff_ptr_create(const Buff *buf){
    BuffPtr *ptr=(BuffPtr*)malloc(sizeof(BuffPtr)+sizeof(byte*)*buf->len);
    if(ptr==NULL)return NULL;
    ptr->len=0;
    ptr->_max=buf->len;
    return ptr;
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
get_card(Buff *in,int count,FILTER filter){
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

int deck_get_supply(Buff *deck,byte *arr,FILTER filter){
    int stat=deck_len(deck)>=3;
    if(stat==DECK_STAT_OK){

    }
    return stat;
}

Buff* deck_get_card(int type,Buff *in,FILTER filter){
    Buff *out=NULL;
    switch(type){
        case CARD_TYPE_SINGLE:
            out=deck_get_single(in,filter);
        break;
        case CARD_TYPE_PAIR:
            out=deck_get_pair(in,filter);
        break;
        case CARD_TYPE_THREE:
            out=deck_get_three(in,filter);
        break;
        case CARD_TYPE_BOMB:
            out=deck_get_bomb(in,filter);
        break;
        case CARD_TYPE_ROCKET:
            out=deck_get_rocket(in,filter);
        break;
    }
    return out;
}

Buff* deck_get_single(Buff *in,FILTER filter){return get_card(in,1,filter);}
Buff* deck_get_pair(Buff *in,FILTER filter){return get_card(in,2,filter);}
Buff* deck_get_three(Buff *in,FILTER filter){return get_card(in,3,filter);}
Buff* deck_get_bomb(Buff *in,FILTER filter){return get_card(in,4,filter);}
Buff* deck_get_rocket(Buff *in,FILTER filter){
    Buff *out=buff_create(0);
    return out;
}
