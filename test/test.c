#include "base.c"
#include "pdfl.c"
#include "deck.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EQ_BASE(eq,exp,act,fmt)\
do{\
	if(!eq)\
		fprintf(stderr,"" fmt:"" fmt:"\n",exp,act);\
}while(0)

#define EQ_TYPE(exp,act) EQ_BASE((exp)==(act),exp,act,"%d")

#define TEST_TYPE(exp,pdfl)\
do{\
	EQ_BASE(PDFL_OK, pdfl_parser())\
}

void test_parse_type(){
    char *str="b3[123]t3[456]p2[789](t)c2[ABC](t,p)";
	StrChunk *chunk=chunk_match(str,strlen(str),'[',']');
	for(int i=0;i<chunk->len;++i){
        char c=*(chunk->ptr+i);
        printf("%c",c);
    }
    printf("\n");
	parse_type("tap4",5);

}

int main(int argc,char **argv){
	test_parse_type();
	return(1);
}