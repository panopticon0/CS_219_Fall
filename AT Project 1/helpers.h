#ifndef HELPER_H
#define HELPER_H
#include <cstdint>
#include <string>
using namespace std;

uint32_t add(uint32_t, uint32_t);
uint32_t sub(uint32_t, uint32_t);
uint32_t bitAnd(uint32_t, uint32_t);
uint32_t bitOr(uint32_t, uint32_t);
uint32_t bitXor(uint32_t, uint32_t);
uint32_t bitNot(uint32_t);
uint32_t logicalLeftShift(uint32_t, uint32_t);
uint32_t logicalRightShift(uint32_t, uint32_t);
bool equalTo(uint32_t, uint32_t);
bool lessThan(uint32_t, uint32_t);
bool greaterThan(uint32_t, uint32_t);

string printOpResult(string, uint32_t, uint32_t);

#endif

