#include "debug.h"

void disassembleChunk(Chunk* chunk, const char* name) {
  printf("== %s(%d) ==\n", name, chunk->count);
  for (size_t i = 0; i < chunk->count;) {
    i = disassembleInstruction(chunk, i);
  }
}

static size_t simpleInstruction(char* name, size_t offset) {
  printf("%s\n", name);
  return offset + 1;
}

static size_t constantInstruction(const char* name, Chunk* chunk, size_t offset) {
  u_int8_t constantOffset = chunk->code[offset + 1];
  printf("%-16s %4d '", name, constantOffset);
  printValue(chunk->constants.values[constantOffset]);
  printf("'\n");
  return offset + 2;
}

size_t disassembleInstruction(Chunk* chunk, size_t offset) {
  printf("%04ld ", offset);
  if (offset > 0 && chunk->lines[offset] == chunk->lines[offset - 1]) {
    printf("   | ");
  } else {
    printf("%4ld ", chunk->lines[offset]);
  }

  uint8_t instruction = chunk->code[offset];

  switch(instruction) {
    case OP_RETURN:
      return simpleInstruction("OP_RETURN", offset);
    case OP_CONSTANT:
      return constantInstruction("OP_CONSTANT", chunk, offset);
    default:
      printf("Unknown Opcode \"%d\"\n", instruction);
      return offset + 1;
  }
}

