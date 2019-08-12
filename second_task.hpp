#ifndef SECOND_TASK_HPP
#define SECOND_TASK_HPP

#include <iostream>
#include <stdint.h>
#include <ctime>

void printArray(const uint32_t * array, const uint32_t & width, const uint32_t &  height);

void copyData(uint32_t * array, const uint32_t &  frame_height, const uint32_t &  pic_width, const uint32_t &  pic_height, const uint32_t &  pic_x, const uint32_t &  pic_y);

void fillArray(uint32_t * array, const uint32_t &  width, const uint32_t &  height);

void startSecondTast();

#endif // SECOND_TASK_HPP

