#include "base.c"
#include "pdfl.c"
#include "deck.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#define TEST_GET_TOKEN(test,ch) \
if(test(ch)){\
    printf("%s test '%c' : ok!\n",#test,ch);\
}else{\
    printf("%s test '%c' : err!\n",#test,ch);\
}
void test_lexer_get_token(){
    TEST_GET_TOKEN(CH_BUFF,'+');
    TEST_GET_TOKEN(CH_NEFF,'-');
    TEST_GET_TOKEN(CH_NOTE,'#');
    TEST_GET_TOKEN(CH_DIGIT,'1');
    TEST_GET_TOKEN(CH_DIGIT,'9');
    TEST_GET_TOKEN(CH_HEXDIG,'1');
    TEST_GET_TOKEN(CH_HEXDIG,'A');
    TEST_GET_TOKEN(CH_LIMIT,'[');
    TEST_GET_TOKEN(CH_EXPAND,'(');
}

int main(int argc,char **argv){
	test_parse_type();
    test_lexer_get_token();
	return(1);
}