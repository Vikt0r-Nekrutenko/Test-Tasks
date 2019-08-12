#include "second_task.hpp"

void printArray(const uint32_t * array, const uint32_t & width, const uint32_t &  height)
{
    for(uint32_t h = 0; h < height; h++){
        for(uint32_t w = 0; w < width; w++){
           std::cout << array[height * w + h] << " ";
        }
        std::cout<<std::endl;
    }
}

void copyData(uint32_t * array, const uint32_t &  frame_height, const uint32_t &  pic_width, const uint32_t &  pic_height, const uint32_t &  pic_x, const uint32_t &  pic_y)
{
    for(uint32_t h = 0U; h < pic_height; h++)
        for(uint32_t w = 0U; w < pic_width; w++){
            uint32_t temp = array[frame_height * w + h];
            array[frame_height * w + h] = array[frame_height * (w + pic_x) + h + pic_y]; // copy the independent data
            array[frame_height * (w + pic_x) + h + pic_y] = temp; // swap the data and trash
        }
}

void fillArray(uint32_t * array, const uint32_t &  width, const uint32_t &  height)
{
    for(uint32_t h = 0U; h < height; h++)
        for(uint32_t w = 0U; w < width; w++)
            array[height * w + h] = rand() % 9;
}


void startSecondTast()
{
    srand(time(0));
    uint32_t frame_width = 0U,  frame_height = 0U;
    uint32_t pic_width   = 0U,  pic_height   = 0U;
    uint32_t pic_x       = 0U,  pic_y        = 0U;

    std::cout << "Enter the frame width, frame height : ";
    std::cin >> frame_width >> frame_height;

    do{
        std::cout << "Enter the picture width, picture height : ";
        std::cin >> pic_width >> pic_height;
    }while(pic_width > frame_width && pic_height > frame_height);

    do{
        std::cout << "Enter the picture x, picture y : ";
        std::cin >> pic_x >> pic_y;
    }while(pic_x + pic_width > frame_width && pic_y + pic_height > frame_height);

    uint32_t array[frame_width][frame_height];

    fillArray(*array, frame_width, frame_height);

    std::cout << "\nSOURCE ARRAY" << std::endl;
    printArray(*array, frame_width, frame_height);

    copyData(*array, frame_height, pic_width, pic_height, pic_x, pic_y);

    std::cout << "\nDESTINATION ARRAY" << std::endl;
    printArray(*array, frame_width, frame_height);
}
