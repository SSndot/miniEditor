#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "datastruct.h"
void GB_init(space* buffer, unsigned long long init)
{
	buffer->total = init;
	buffer->gap = init;
	buffer->ahead = 0;
	buffer->word = (char*)malloc(init * sizeof(char));
}

void GB_free(space* buffer)
{
	free(buffer->word);
	((space*)buffer)->word = NULL;
}

void* GB_expand(space* buffer)
{
	unsigned long long back = buffer->total - buffer->ahead;
	buffer->gap = buffer->total;
	buffer->total *= 2;
	if ((buffer->word = (char*)realloc(buffer->word, buffer->total)) == NULL)
		exit(0);
	memmove(buffer->word + buffer->ahead + buffer->gap, buffer->word + buffer->ahead, back);
	return buffer;
}

void GB_insert(space* buffer, char value)
{
	if (buffer->gap == 0)
		buffer = GB_expand(buffer);
	(buffer->word)[buffer->ahead] = value;
	buffer->ahead++;
	buffer->gap--;
}

void GB_move(space* buffer, long long inr)
{
	unsigned long long len;
	char* dest, * src;
	if (inr < 0) {
		len = -inr;
		if (len > buffer->ahead)
			len = buffer->ahead;
		dest = buffer->word + buffer->ahead + buffer->gap - len;
		src = buffer->word + buffer->ahead - len;
		buffer->ahead -= len;
	}
	else {
		unsigned long long back = buffer->total - buffer->ahead - buffer->gap;
		len = inr;
		if (len > back)
			len = back;
		dest = buffer->word + buffer->ahead;
		src = buffer->word + buffer->ahead + buffer->gap;
		buffer->ahead += len;
	}
	memmove(dest, src, len);
}

void GB_backward(space* buffer)
{
	if (buffer->ahead > 0) {
		buffer->word[buffer->ahead + buffer->gap - 1] = buffer->word[buffer->ahead - 1];
		buffer->ahead--;
	}
}

void GB_forward(space* buffer)
{
	unsigned long long back = buffer->total - buffer->ahead - buffer->gap;
	if (back > 0) {
		buffer->word[buffer->ahead] = buffer->word[buffer->ahead + buffer->gap];
		buffer->ahead++;
	}
}

void GB_delete(space* buffer, char value)
{
	if (buffer->total > buffer->ahead + buffer->gap)
		buffer->gap++;
}

void GB_backspace(space* buffer)
{
	if (buffer->ahead) {
		buffer->ahead--;
		buffer->gap++;
	}
}

char* GB_array(space* buffer)
{
	char* array = (char*)malloc(buffer->total - buffer->gap + 1);
	memmove(array, buffer->word, buffer->ahead);
	unsigned long long back = buffer->total - buffer->ahead - buffer->gap;
	memmove(array + buffer->ahead, buffer->word + buffer->ahead + buffer->gap, back);
	array[buffer->total - buffer->gap] = '\0';
	return array;
}

void GB_read(space* buffer, FILE* p)
{
	fread(buffer->word, 1, buffer->ahead, p);
	char* start = buffer->word + buffer->ahead + buffer->gap;
	unsigned long long len = buffer->total - buffer->ahead - buffer->gap;
	fread(start, 1, len, p);
}

void GB_write(space* buffer, FILE* p)
{
	fwrite(buffer->word, 1, buffer->ahead, p);
	char* start = buffer->word + buffer->ahead + buffer->gap;
	unsigned long long len = buffer->total - buffer->ahead - buffer->gap;
	fwrite(start, 1, len, p);
}
