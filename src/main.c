#include "base.h"
#include "deck.h"
#include "pdfl.h"

#include <stdio.h>
void test_filter(){
	struct filter *filter=filter_create();
	filter_add_limit(filter,PDFL_CARD_2);
	if((filter->limit&PDFL_CARD_2)==PDFL_CARD_2)printf("filter_add_limit:ok\n");
	filter_add_expand(filter,PDFL_TYPE_C);
	if((filter->expand&PDFL_TYPE_C)==PDFL_TYPE_C)printf("filter_add_expand:ok\n");
}
void test_pdfl(const char *str,int len){
	pdfl_parser(str,len);
}
int test_same_card(int num){
	struct buff *deck=deck_create();
	deck_srand(time(NULL));
	if(deck==NULL){
		printf("deck create failed!\n");
		return 0;
	}
	deck_log(deck);
	for(int i=0;i<5;++i){
		struct buff *buf=deck_get_card(deck,num,NULL);
		printf("deck: %d card: ",deck_len(deck));
		buff_log(buf);
		buff_delete(buf);
	}
	buff_delete(deck);
	return 1;
}

int main(int argc,char **argv){
	test_filter();
	for(int i=1;i<=0;++i){
		if(!(test_same_card(i))){
			printf("%s\n","error!");
			return 0;
		}
	}
	test_pdfl("+tp2[123] #test",15);
	return 1;
}
