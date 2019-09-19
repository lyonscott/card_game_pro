#ifndef __PARSER_H__
#define __PARSER_H__

#include "base.h"

/* Poker Draws Form Language(pdfl)
[syntax]
chunk::='#'{VCHAR}|('+'|'-'){body}
body::=<types><DIGIT>[limit][expand]
expand::='('types {','types}')'
types::=s|p|t|tc|tp|s|sp|st|stc|stp|b|r|q
limit::='['(list|range) {','(list|range)}']'
list::={HEXDIG}
range::=HEXDIG':'HEXDIG

[eg]
#using
+b2[ABCD] 
 t2[4:9]
 p1[12,6:A](b,t)
 c2[AF](p)

-b2[ABCD]t2[4:9]p1[12]c2[AF] #unusing
*/
enum PDFL_TYPES{
    PDFL_TYPE_C=1<<1, //Single card
    PDFL_TYPE_P=1<<2, //Pair
    PDFL_TYPE_T=1<<3, //Triplet
    PDFL_TYPE_TC=1<<4, //Triplet with an attached card
    PDFL_TYPE_TP=1<<5, //Triplet with an attached pair
    PDFL_TYPE_B=1<<6, //Bomb
    PDFL_TYPE_Q=1<<7, //Quadplex set
    PDFL_TYPE_S=1<<8, //Sequence
    PDFL_TYPE_SP=1<<9, //Sequence of pairs
    PDFL_TYPE_ST=1<<10, //Sequence of triplets
    PDFL_TYPE_STC=1<<11, //Sequence of triplets with attached cards
    PDFL_TYPE_STP=1<<12, //Sequence of triplets with attached pairs
    PDFL_TYPE_R=1<<13, //Rocket
};

enum PDFL_TYPE_CODES{
    PDFL_TYPE_CODE_C=0x630000,
    PDFL_TYPE_CODE_P=0x700000,
    PDFL_TYPE_CODE_T=0x740000,
    PDFL_TYPE_CODE_TC=0x746300,
    PDFL_TYPE_CODE_TP=0x747000,
    PDFL_TYPE_CODE_B=0x620000,
    PDFL_TYPE_CODE_Q=0x710000,
    PDFL_TYPE_CODE_S=0x730000,
    PDFL_TYPE_CODE_SP=0x737000,
    PDFL_TYPE_CODE_ST=0x737470,
    PDFL_TYPE_CODE_STC=0x737463,
    PDFL_TYPE_CODE_STP=0x737470,
    PDFL_TYPE_CODE_R=0x710000,
};

enum PDFL_CARDS{
    PDFL_CARD_A=1<<1,
    PDFL_CARD_2=1<<2,
    PDFL_CARD_3=1<<3,
    PDFL_CARD_4=1<<4,
    PDFL_CARD_5=1<<5,
    PDFL_CARD_6=1<<6,
    PDFL_CARD_7=1<<7,
    PDFL_CARD_8=1<<8,
    PDFL_CARD_9=1<<9,
    PDFL_CARD_10=1<<10,
    PDFL_CARD_J=1<<11,
    PDFL_CARD_Q=1<<12,
    PDFL_CARD_K=1<<13,
    PDFL_CARD_N=1<<14,
    PDFL_CARD_M=1<<15,
};

#define PDFL_OK 1
#define PDFL_TYPE 100
#define PDFL_DIGIT 101
#define PDFL_HEXDIG 102
#define PDFL_RANGE 103
#define PDFL_LIST 104
#define PDFL_LIMIT 105
#define PDFL_EXPAND 106

struct filter{
    int type_code;
    int count;
    u8 limit;
    u8 expand;
};
struct filter* filter_create();
void filter_add_limit(struct filter *filter,u8 mark);
void filter_add_expand(struct filter *filter,u8 mark);
void pdfl_parser(const char *str,int len);

#endif