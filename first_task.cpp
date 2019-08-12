#include "first_task.hpp"
#include "second_task.hpp"

void startFirstTask()
{
    uint32_t N = 5U;

    std::cout << "Enter N : ";
    std::cin >> N;

    uint32_t array[N][N];

    fillArray(*array, N, N);

    std::cout << "\nSOURCE ARRAY" << std::endl;
    printArray(*array, N, N);

    for(uint32_t j = 0; j < N / 2; j++)
    {
        for(uint32_t i = j; i < N-j-1; i++)
        {
            uint32_t tmp = array[j][j];

            for(uint32_t y = j; y < N-(j+1); y++){
                array[j][y] = array[j][y+1];
            }
            for(uint32_t x = j; x < N-(j+1); x++){
                array[x][N-j-1] = array[x+1][N-j-1];
            }
            for(uint32_t y = j; y < N-(j+1); y++){
                array[N-j-1][N-y-1] = array[N-j-1][N-y-2];
            }
            for(uint32_t x = j; x < N-(j+1); x++){
                array[N-x-1][j] = array[N-x-2][j];
            }
            array[j+1][j] = tmp;
        }
    }

    std::cout << "\nDESTINATION ARRAY" << std::endl;
    printArray(*array, N, N);

}
