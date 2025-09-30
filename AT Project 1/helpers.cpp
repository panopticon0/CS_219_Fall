#include "helpers.h"
#include <iostream>

uint32_t add(uint32_t a, uint32_t b) {
    return a + b;
}

uint32_t sub(uint32_t a, uint32_t b) {
    return a - b;
}

uint32_t bitAnd(uint32_t a, uint32_t b) {
    return a & b;
}

uint32_t bitOr(uint32_t a, uint32_t b) {
    return a | b;
}

uint32_t bitXor(uint32_t a, uint32_t b) {
    return a ^ b;
}

uint32_t bitNot(uint32_t a) {
    return ~a;
}

uint32_t logicalLeftShift(uint32_t a, uint32_t b) {
    return a << b;
}

uint32_t logicalRightShift(uint32_t a, uint32_t b) {
    return a >> b;
}

bool equalTo(uint32_t a, uint32_t b) {
    return a == b;
}

bool lessThan(uint32_t a, uint32_t b) {
    return a < b;
}

bool greaterThan(uint32_t a, uint32_t b) {
    return a > b;
}

string printOpResult(string opName, uint32_t first, uint32_t second) {
    if (opName == "ADD") {
        uint32_t result;
        result = add(first, second);
        return to_string(result);
    }
    else if (opName == "SUB") {
        uint32_t result;
        result = sub(first, second);
        return to_string(result);
    }
    else if (opName == "AND") {
        uint32_t result;
        result = bitAnd(first, second);
        return to_string(result);
    }
    else if (opName == "OR") {
        uint32_t result;
        result = bitOr(first, second);
        return to_string(result);
    }
    else if (opName == "XOR") {
        uint32_t result;
        result = bitXor(first, second);
        return to_string(result);
    }
    else if (opName == "NOT") {
        uint32_t result;
        result = bitNot(first);
        return to_string(result);
    }
    else if (opName == "LSL") {
        uint32_t result;
        if (second > 31 or second < 0) {
            return "Error: Shift amount must be between 0 and 31.";
        } else {
            result = logicalLeftShift(first, second);
            return to_string(result);
        }
    }
    else if (opName == "LSR") {
        uint32_t result;
        if (second > 31 or second < 0) {
            return "Error: Shift amount must be between 0 and 31.";
        } else {
            result = logicalRightShift(first, second);
            return to_string(result);
        }
    }
    else if (opName == "EQ") {
        bool result;
        result = equalTo(first, second);
        if (result) {
            return "true";
        } else {
            return "false";
        }
    }
    else if (opName == "LT") {
        bool result;
        result = lessThan(first, second);
        if (result) {
            return "true";
        } else {
            return "false";
        }
    }
    else if (opName == "GT") {
        bool result;
        result = greaterThan(first, second);
        if (result) {
            return "true";
        } else {
            return "false";
        }
    }
    else {
        return "Invalid Operation";
    }
}
