#include "base.h"
#include "deck.h"

int main(int argc,char **argv){
  Deck deck;
  deck_init(&deck);
  deck_log(&deck);
  byte single[1];
  for(int i=0;i<16;++i){
    deck_get_single(&deck,&single[0],NULL);
    printf("deck: %d, card: %d\n",deck.len,single[0]);
  }
}
