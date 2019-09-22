#include "base.c"
#include "pdfl.c"
#include "deck.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST_OK(msg,info) printf("\033[32m[OK]\033[0m %s %s\n",#msg,#info);
#define TEST_ERR(msg,info) printf("\033[31m[ERR]\033[0m %s %s\n",#msg,#info);

#define TEST_TOKEN_CH(test,ch) if(test(ch)){TEST_OK(test,ch)}else{TEST_ERR(test,ch)}
void test_lexer_get_token(){
    printf("\n");
    TEST_TOKEN_CH(CH_DRAW,'+');
    TEST_TOKEN_CH(CH_NOTE,'#');
    TEST_TOKEN_CH(CH_DIGIT,'0');
    TEST_TOKEN_CH(CH_DIGIT,'9');
    TEST_TOKEN_CH(CH_HEXDIG,'0');
    TEST_TOKEN_CH(CH_HEXDIG,'A');
    TEST_TOKEN_CH(CH_RULE,'(');
}

void test_chunk(){
    //+b2(12,~35)t3(~16,b)
    struct context ctx=context_create("+b2(12,~35)t3(b,1,~12,sp)\n+t2(123)");
    printf("%s\n",ctx.fp);
    chunk(&ctx);
}

int main(int argc,char **argv){
    test_chunk();
    test_lexer_get_token();
	return(1);
}