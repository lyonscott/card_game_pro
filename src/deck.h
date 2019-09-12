#ifndef __DECK_H__
#define __DECK_H__
#include "base.h"

#define CARDS_VAL_COUNT	15
extern const byte CARDS[];

struct buff{
	int len;
	byte arr[];
};
struct buff* buff_create(int len);
void buff_log(struct buff *buf);

typedef byte* (*FILTER)(const struct buff*);
struct buff* deck_create();
void deck_srand(unsigned int seed);
void deck_log(const struct buff *deck);
int deck_len(const struct buff *deck);
struct buff* deck_get_card(struct buff *in,int num,FILTER filter);
#endif
