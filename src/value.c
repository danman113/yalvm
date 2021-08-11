#include "value.h"
#include "memory.h"

void initValueArray(ValueArray* valueArray) {
  valueArray->capacity = 0;
  valueArray->count = 0;
  valueArray->values = NULL;
}
void writeValueArray(ValueArray* valueArray, Value value) {
  if (valueArray->capacity < valueArray->count + 1) {
    size_t oldCapacity = valueArray->capacity;
    valueArray->capacity = GROW_CAPACITY(valueArray->capacity);
    valueArray->values = GROW_ARRAY(Value, valueArray->values, oldCapacity, valueArray->capacity); 
    // Resize array
  }

  valueArray->values[valueArray->count] = value;
  valueArray->count++;
}
void freeValueArray(ValueArray* valueArray) {
  FREE_ARRAY(Value, valueArray->values, valueArray->capacity);
  initValueArray(valueArray);
}

void printValue(Value value) {
  printf("%g", value);
}