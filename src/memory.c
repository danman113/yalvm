#include "common.h"

void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
  if (newSize == 0) {
    free(pointer);
    return NULL;
  }

  void* handle = realloc(pointer, newSize);
  if (handle == NULL) exit(1);
  return handle;
}
