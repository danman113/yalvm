#ifndef yalvm_chunk_h
#define yalvm_chunk_h

#include "common.h"
#include "value.h"

typedef enum {
  OP_RETURN,
  OP_CONSTANT,
} OpCode;

typedef struct {
  int count;
  int capacity; 
  uint8_t* code;
  size_t* lines;
  ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, u_int8_t byte, size_t line);
size_t addConstant(Chunk* chunk, Value value);

#endif