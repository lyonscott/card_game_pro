#ifndef __DECK_H__
#define __DECK_H__
#include "base.h"

#define CARD_TYPE_COUNT 16
extern const byte CARDS[];

struct deck{
    byte cards[CARD_TYPE_COUNT];
    int len;
};
typedef byte* (*FILTER)(const struct deck*);
void deck_init(struct deck *deck);
void deck_log(const struct deck *deck);
int deck_len(const struct deck *deck);
int deck_get_supply(struct deck *deck,byte *arr,FILTER filter);
int deck_get_single(struct deck *deck,byte *arr,FILTER filter);
int deck_get_pair(struct deck *deck,byte *arr,FILTER filter);
int deck_get_three(struct deck *deck,byte *arr,FILTER filter);
int deck_get_bomb(struct deck *deck,byte *arr,FILTER filter);
int deck_get_rocket(struct deck *deck,byte *arr,FILTER filter);
int deck_get_card(struct deck *deck,byte *card,FILTER filter);
#endif
