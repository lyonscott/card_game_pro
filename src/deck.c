#include "deck.h"

const byte DECK[]={
    0x11,0x21,0x31,0x41,0x51,0x61,0x71,0x81,0x91,0xA1,0xB1,0xC1,0xD1,
    0x12,0x22,0x32,0x42,0x52,0x62,0x72,0x82,0x92,0xA2,0xB2,0xC2,0xD2,
    0x13,0x23,0x33,0x43,0x53,0x63,0x73,0x83,0x93,0xA3,0xB3,0xC3,0xD3,
    0x14,0x24,0x34,0x44,0x54,0x64,0x74,0x84,0x94,0xA4,0xB4,0xC4,0xD4,
    0xE1,0xF1,
};

//0xN0: card value
//0x0N: card number
const byte CARDS[CARD_TYPE_COUNT]={
  0x14,0x24,0x34,0x44,0x54,0x64,0x74,0x84,0x94,0xA4,0xB4,0xC4,0xD4,0xE1,0xF1,
};

int rrand(int len){
    return rand()%len;
}

void swap(byte *src,byte *to){
    if(*src==*to)return;
    *src^=*to;
    *to^=*src;
    *src^=*to;
}

void deck_init(Deck *deck){
    deck=(Deck*)malloc(sizeof(Deck)+sizeof(byte)*CARD_TYPE_COUNT);
    memcpy(deck->cards,CARDS,sizeof(CARDS));
    deck->len=CARD_TYPE_COUNT;
}

void deck_log(const Deck *deck){
    printf("(%d)[",deck_len(deck));
    for(int i=0;i<deck->len;++i){
        printf("%d ",deck->cards[i]);
    }
    printf("]\n");
}

int deck_len(const Deck *deck){
    int count=0;
    for(int i=0;i<CARD_TYPE_COUNT;++i){
        count+=deck->cards[i]&0x0F;
    }
    return count;
}

int deck_get_card(Deck *deck,byte *card,FILTER filter){
    int ok=0;
    return ok;
}

int deck_get_supply(Deck *deck,byte *arr,FILTER filter){
    int ok=0;
    return ok; 
}

int deck_get_single(Deck *deck,byte *arr,FILTER filter){
    int ok=0;
    if(deck->len>=1){
        
    }
    return ok;
}

int deck_get_pair(Deck *deck,byte *arr,FILTER filter){
    int ok=0;
    return ok;
}

int deck_get_three(Deck *deck,byte *arr,FILTER filter){
    int ok=0;
    return ok;
}

int deck_get_bomb(Deck *deck,byte *arr,FILTER filter){
    int ok=0;
    return ok;
}

int deck_get_rocket(Deck *deck,byte *arr,FILTER filter){
    int ok=0;
    return ok;
}