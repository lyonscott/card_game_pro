#ifndef __DECK_H__
#define __DECK_H__
#include "base.h"

#define CARDS_VAL_COUNT	15
extern const u8 CARDS[];

typedef struct buffer* (*FILTER)(const struct buffer *buf);
struct buffer* deck_create();
void deck_srand(unsigned int seed);
void deck_log(const struct buffer *deck);
int deck_len(const struct buffer *deck);
struct buffer* deck_get_card(struct buffer *in,int num,FILTER filter);


struct dealer{
	struct buffer *flag_cache;

};

struct dealer* dealer_create();
void dealer_delete(struct dealer* dealer);

#endif
