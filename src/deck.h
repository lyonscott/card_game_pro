#ifndef __DECK_H__
#define __DECK_H__
#include "base.h"

//deck status code
#define DECK_STAT_OK 	1
#define DECK_STAT_ERR 	0
//types
#define CARD_TYPE_SINGLE	1
#define CARD_TYPE_PAIR		2
#define CARD_TYPE_THREE		3
#define CARD_TYPE_BOMB		4
#define CARD_TYPE_ROCKET	5

#define CARDS_VAL_COUNT	15
extern const byte CARDS[];

struct buff{
	int len;
	byte arr[];
};
struct buff* buff_create(int len);
void buff_log(struct buff *buf);

struct buff_ptr{
	int len;
	int _max;
	byte *arr[];
};
struct buff_ptr* buff_ptr_create(const struct buff *buf);


typedef byte* (*FILTER)(const struct buff*);
struct buff* deck_create();
void deck_log(const struct buff *deck);
int deck_len(const struct buff *deck);
int deck_get_supply(struct buff *deck,byte *arr,FILTER filter);
struct buff* deck_get_card(int type,struct buff *in,FILTER filter);
struct buff* deck_get_single(struct buff *in,FILTER filter);
struct buff* deck_get_pair(struct buff *in,FILTER filter);
struct buff* deck_get_three(struct buff *in,FILTER filter);
struct buff* deck_get_bomb(struct buff *in,FILTER filter);
struct buff* deck_get_rocket(struct buff *in,FILTER filter);
int filte_by_count(struct buff *bf,byte *arr,int count);

#endif
