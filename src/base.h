#ifndef __BASE_H__
#define __BASE_H__

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
typedef unsigned char u8;

struct buffer{
	int len;
	u8 arr[];
};

struct buffer *buffer_create(int len);
void buffer_delete(struct buffer *buf);
void buffer_log(struct buffer *buf);

struct buffer_ptr{
	int len;
	int _max;
	u8 *arr[];
};

struct buffer_ptr* buffer_ptr_create(const struct buffer *buf);
void buffer_ptr_delete(struct buffer_ptr *ptr);


#endif