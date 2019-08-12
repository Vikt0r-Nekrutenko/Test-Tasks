#include "third_task.hpp"
#include "second_task.hpp"
#include "first_task.hpp"

int main()
{
    uint32_t task = 0;
    do{
        std::cout << "\nPlease, enter the task number:"
                     "\n1.Rotate array on 90 grade."
                     "\n2.Move subarray in array."
                     "\n3.Convert number to word."
                  << std::endl;
        std::cin >> task;
        switch (task) {
        case 1:
            startFirstTask();
            break;
        case 2:
            startSecondTast();
            break;
        case 3:
            startThirdTask();
            break;
        }
    }while(task);

    return 0;
}

