#ifndef yalvm_debug_h
#define yalvm_debug_h

#include "chunk.h"

void disassembleChunk(Chunk* chunk, const char* name);
size_t disassembleInstruction(Chunk* chunk, size_t offest);

#endif