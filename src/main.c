#include "base.h"
#include "deck.h"

int test_single(){
	struct buff *deck=deck_create();
	if(deck==NULL){
		printf("deck create failed!\n");
		return 0;
	}
	deck_log(deck);
	for(int i=0;i<10;++i){
		struct buff *buf=deck_get_single(deck,NULL);
		printf("deck: %d card: ",deck_len(deck));
		buff_log(buf);
		free(buf);
	}
	free(deck);
	return 1;
}

int test_pair(){
	struct buff *deck=deck_create();
	if(deck==NULL){
		printf("deck create failed!\n");
		return 0;
	}
	deck_log(deck);
	for(int i=0;i<10;++i){
		struct buff *buf=deck_get_pair(deck,NULL);
		printf("deck: %d card: ",deck_len(deck));
		buff_log(buf);
		free(buf);
	}
	free(deck);
	return 1;
}

int test_three(){
	struct buff *deck=deck_create();
	if(deck==NULL){
		printf("deck create failed!\n");
		return 0;
	}
	deck_log(deck);
	for(int i=0;i<10;++i){
		struct buff *buf=deck_get_three(deck,NULL);
		printf("deck: %d card: ",deck_len(deck));
		buff_log(buf);
		free(buf);
	}
	free(deck);
	return 1;
}

int test_bomb(){
	struct buff *deck=deck_create();
	if(deck==NULL){
		printf("deck create failed!\n");
		return 0;
	}
	deck_log(deck);
	for(int i=0;i<10;++i){
		struct buff *buf=deck_get_bomb(deck,NULL);
		printf("deck: %d card: ",deck_len(deck));
		buff_log(buf);
		free(buf);
	}
	free(deck);
	return 1;
}

int main(int argc,char **argv){
	if(!test_single())return 0;
	if(!test_pair())return 0;
	if(!test_three())return 0;
	if(!test_bomb())return 0;
	return 1;
}
