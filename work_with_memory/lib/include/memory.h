#ifndef __MEMORY___
#define __MEMORY___

void put(char *id, int value);
void putarr(char *id, int cell, int value);
int get(char *id);
int getarr(char *id, int cell);
void delete(char *id);
void clear_memory();

#endif
