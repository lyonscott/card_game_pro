#ifndef __BASE_H__
#define __BASE_H__

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
#define byte unsigned char

struct buff{
	int len;
	byte arr[];
};
struct buff* buff_create(int len);
void buff_delete(struct buff *buf);
void buff_log(struct buff *buf);

struct buff_ptr{
	int len;
	int _max;
	byte *arr[];
};

struct buff_ptr* buff_ptr_create(const struct buff *buf);
void buff_ptr_delete(struct buff_ptr *ptr);

#endif