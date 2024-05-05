#ifndef _datastruct_h
#define _datastruct_h
typedef struct {
	char* word;
	unsigned long long total;/* total size of buf */
	unsigned long long ahead;/*size of content before cursor*/
	unsigned long long gap;/* size of the gap */
}space;
void GB_init(space* buffer, unsigned long long init);
void GB_free(space* buffer);
void* GB_expand(space* buffer);
void GB_insert(space* buffer, char value);
void GB_move(space* buffer, long long inr);
void GB_backward(space* buffer);
void GB_forward(space* buffer);
void GB_delete(space* buffer, char value);
void GB_backspace(space* buffer);
char* GB_array(space* buffer);
void GB_read(space* buffer, FILE* p);
void GB_write(space* buffer, FILE* p);
#endif
