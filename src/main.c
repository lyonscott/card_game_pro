#include "base.h"
#include "deck.h"

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
	for(int i=1;i<=4;++i){
		if(!(test_same_card(i))){
			printf("%s\n","error!");
			return 0;
		}
	}
	return 1;
}
