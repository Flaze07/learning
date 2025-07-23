#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

#include <stddef.h>
#include <stdint.h>

struct BitArray {
  size_t size;
  uint32_t *bits;
};

struct BitArray *createBitArray(int size);
void freeBitArray(struct BitArray* self);
struct BitArray *cloneBitArray(struct BitArray* self);

int bitArrayGetBit(struct BitArray* self, int index);
void bitArraySetBit(struct BitArray* self, int index);
void bitArrayClearBit(struct BitArray* self, int index);

void bitArrayAnd(struct BitArray* result, struct BitArray* a, struct BitArray* b);
void bitArrayOr(struct BitArray* result, struct BitArray* a, struct BitArray* b);
void bitArrayXor(struct BitArray* result, struct BitArray* a, struct BitArray* b);

void bitArrayShiftLeft(struct BitArray* self, int amount);
void bitArrayShiftRight(struct BitArray* self, int amount);

void bitArrayRotateLeft(struct BitArray* self, int amount);
void bitArrayRotateRight(struct BitArray* self, int amount);

void numberToBitArray(struct BitArray* self, uint64_t number);

#endif
