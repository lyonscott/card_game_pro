#ifndef __PARSER_H__
#define __PARSER_H__

/* Poker Draws Form Language(pdfl)
[TYPE_CODE_*]
abbr(name)=>hex

[syntax]
chunk=<mark>{<types><num>[<limit>]}
mark::='+'|'-'|'#'
types::=s|p|t|tc|tp|s|sp|st|stc|stp|b|r|q
num::= DIGIT
limit::='['<range>{','range}']'
range::=HEXDIG|{HEXDIG}|HEXDIG':'HEXDIGIT

[eg]
+b2[ABCD]t2[4:9]p1[12,6:A]c2[EF] #using
-b2[ABCD]t2[4:9]p1[12]c2[EF] #unusing
*/
#define PDFL_TYPE_CODE_C 0x630000 //Single card
#define PDFL_TYPE_CODE_P 0x700000 //Pair
#define PDFL_TYPE_CODE_T 0x740000 //Triplet
#define PDFL_TYPE_CODE_TAC 0x746300 //Triplet with an attached card
#define PDFL_TYPE_CODE_TAP 0x747000 //Triplet with an attached pair
#define PDFL_TYPE_CODE_S 0x730000 //Sequence
#define PDFL_TYPE_CODE_SP 0x737000 //Sequence of pairs
#define PDFL_TYPE_CODE_ST 0x737400 //Sequence of triplets
#define PDFL_TYPE_CODE_STC 0x737463 //Sequence of triplets with attached cards
#define PDFL_TYPE_CODE_STP 0x737470 //equence of triplets with attached pairs
#define PDFL_TYPE_CODE_B 0x620000 //Bomb
#define PDFL_TYPE_CODE_R 0x720000 //Rocket
#define PDFL_TYPE_CODE_Q 0x710000 //Quadplex set

void pdfl_parser(const char *str,int len);

#endif