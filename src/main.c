#include "common.h"
#include "chunk.h"
#include "debug.h"

int main (uint8_t argc, const char** argv) {
  printf("Args %d(%p)!\n", argc, argv);
  for (int i = 0; i < argc; i++) {
    printf("%s\n", argv[i]);
  }

  OpCode oplist[1] = {OP_CONSTANT};

  size_t list[3] = {(size_t)0UL, (size_t)1UL, (size_t)0UL};

  Chunk chunk;
  initChunk(&chunk);
  size_t sixtyNine = addConstant(&chunk, 69);
  writeChunk(&chunk, OP_CONSTANT, 3);
  writeChunk(&chunk, sixtyNine, 3);
  size_t fourTwenty = addConstant(&chunk, 420);
  writeChunk(&chunk, OP_CONSTANT, 4);
  writeChunk(&chunk, fourTwenty, 4);
  writeChunk(&chunk, OP_RETURN, 4);

  disassembleChunk(&chunk, "Return Chunk");
  freeChunk(&chunk);

  
  return 0;
}