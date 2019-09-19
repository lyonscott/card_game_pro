#ifndef __DECK_H__
#define __DECK_H__
#include "base.h"

#define CARDS_VAL_COUNT	15
extern const byte CARDS[];

;

typedef struct buff* (*FILTER)(const struct buff *buf);
struct buff* deck_create();
void deck_srand(unsigned int seed);
void deck_log(const struct buff *deck);
int deck_len(const struct buff *deck);
struct buff* deck_get_card(struct buff *in,int num,FILTER filter);


struct dealer{
	struct buff *flag_cache;

};

struct dealer* dealer_create();
void dealer_delete(struct dealer* dealer);

#endif
