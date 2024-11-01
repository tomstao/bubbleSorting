#include <iostream>
#include <cstdlib>
#include <ctime>


int main()
{
    srand(time(NULL));
    int size_array = 0;
    char replay = 'Y';
    do
    {
        std::cout << "Enter size of array: ";
        while (!(std::cin >> size_array))
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Enter size of array: ";
        }
        int* array = new int[size_array];
        for (int i = 0; i < size_array; i++)
        {
            array[i] = rand() % 100;
        }
        for(int j = 0; j < size_array; j++)
        {

            for(int k = 0; k < size_array - j - 1; k++)
            {
                if(array[k] > array[k + 1])
                {   int temp = 0;
                    temp = array[k + 1];
                    array[k + 1] = array[k];
                    array[k] = temp;
                }
            }
        }
        for (int l = 0; l < size_array; l++)
        {
            if(array[l] < 10)
            {
                std::cout << '0' <<array[l] <<' ';
            } else std::cout << array[l] << " ";
            if((l + 1) % 10 == 0)
            {
                std::cout << std::endl;
            }
        }
        delete[] array;
        std::cout <<"Enter Y to continue or other key to exit: "<< std::endl;
        std::cin >> replay;
    } while (replay == 'Y' || replay == 'y');
    return 0;
}


