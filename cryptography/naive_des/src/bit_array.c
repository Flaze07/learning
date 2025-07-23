#include <stdlib.h>
#include <bit_array.h>

struct BitArray *createBitArray(int size) {
  struct BitArray *self;
  self = malloc(sizeof(struct BitArray));

  self->size = size;
  self->bits = malloc(sizeof(uint32_t) * self->size);

  for (int i = 0; i < self->size; ++i) {
    bitArrayClearBit(self, i);
  }

  return self;
}

void freeBitArray(struct BitArray *self) {
  free(self->bits);
  free(self);
}

struct BitArray *cloneBitArray(struct BitArray* self) {
  struct BitArray *result;
  result = malloc(sizeof(struct BitArray));

  result->size = self->size;
  result->bits = malloc(sizeof(uint32_t) * result->size);

  for (int i = 0; i < result->size; ++i) {
    uint32_t currentBit = bitArrayGetBit(self, i);
    if (currentBit == 0) {
      bitArrayClearBit(result, i);
    } else if (currentBit == 1) {
      bitArraySetBit(result, i);
    }
  }

  return result;
}

int bitArrayGetBit(struct BitArray* self, int index) {
  return self->bits[index];
}
void bitArraySetBit(struct BitArray* self, int index) {
  self->bits[index] = 1;
}

void bitArrayClearBit(struct BitArray* self, int index) {
  self->bits[index] = 0;
}


void bitArrayAnd(struct BitArray* result, struct BitArray* a, struct BitArray* b) {
  size_t size = a->size;

  for (int i = 0; i < size; ++i) {
    uint32_t aBit = bitArrayGetBit(a, i);
    uint32_t bBit = bitArrayGetBit(b, i);

    if (aBit == 1 && bBit == 1) {
      bitArraySetBit(result, i);
    } else {
      bitArrayClearBit(result, i);
    }
  }
}
void bitArrayOr(struct BitArray* result, struct BitArray* a, struct BitArray* b) {
  size_t size = a->size;

  for (int i = 0; i < size; ++i) {
    uint32_t aBit = bitArrayGetBit(a, i);
    uint32_t bBit = bitArrayGetBit(b, i);

    if (aBit == 0 && bBit == 0) {
      bitArrayClearBit(result, i);
    } else {
      bitArraySetBit(result, i);
    }
  }
}
void bitArrayXor(struct BitArray* result, struct BitArray* a, struct BitArray* b) {
  size_t size = a->size;

  for (int i = 0; i < size; ++i) {
    uint32_t aBit = bitArrayGetBit(a, i);
    uint32_t bBit = bitArrayGetBit(b, i);

    if (aBit == bBit) {
      bitArrayClearBit(result, i);
    } else {
      bitArraySetBit(result, i);
    }
  }
}

void bitArrayShiftLeft(struct BitArray* self, int amount) {
  int startIdx = amount;

  for (int i = startIdx; i < self->size; ++i) {
    self->bits[i] = self->bits[i - amount];
  }

  for (int i = 0; i < startIdx; ++i) {
    self->bits[i] = 0;
  }
}

void bitArrayShiftRight(struct BitArray* self, int amount) {
  int finalIdx = self->size - 1;
  int startIdx = finalIdx - amount;

  for (int i = startIdx; i >= 0; --i) {
    self->bits[i] = self->bits[i + amount];
  }

  for (int i = finalIdx; i > startIdx; ++i) {
    self->bits[i] = 0;
  }
}

