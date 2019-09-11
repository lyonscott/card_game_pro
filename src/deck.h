#ifndef __DECK_H__
#define __DECK_H__
#include "base.h"

#define CARD_TYPE_COUNT 16
extern const byte CARDS[];

typedef struct{
    int len;
    byte cards[]
}Deck;

typedef byte* (*FILTER)(const Deck*);
void deck_init(Deck *deck);
void deck_log(const Deck *deck);
int deck_len(const Deck *deck);
int deck_get_supply(Deck *deck,byte *arr,FILTER filter);
int deck_get_single(Deck *deck,byte *arr,FILTER filter);
int deck_get_pair(Deck *deck,byte *arr,FILTER filter);
int deck_get_three(Deck *deck,byte *arr,FILTER filter);
int deck_get_bomb(Deck *deck,byte *arr,FILTER filter);
int deck_get_rocket(Deck *deck,byte *arr,FILTER filter);
int deck_get_card(Deck *deck,byte *card,FILTER filter);
#endif
