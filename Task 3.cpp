#include <stdio.h> 
#include <chrono>
#include <iostream>
#include <algorithm>

#include <vector>
#include <array>
#include <deque>
#include <forward_list>
#include <list>




int main()
{
    const std::size_t counter = 1000;
    int random_value = 0;

    std::vector<int> test_vector_func;
    test_vector_func.reserve(counter);
    std::array<int, counter> test_array_func;

    std::deque<int> test_deque_func;

    std::forward_list<int> test_forward_list;
    std::forward_list<int> test_forward_list_func;

    std::list<int> test_list;
    std::list<int> test_list_func;
    for (int j = 0; j < counter; j++)
    {
        random_value = rand();
        test_vector_func.push_back(random_value);

        test_array_func[j] = random_value;

        test_deque_func.push_back(random_value);

        test_forward_list_func.push_front(random_value);
        test_forward_list.push_front(random_value);

        test_list.push_back(random_value);
        test_list_func.push_back(random_value);
    }

    test_forward_list.reverse();
    test_forward_list_func.reverse();
    using microseconds = std::chrono::duration<long long, std::micro>;
    //test vector, it hasnt method sort
    auto begin = std::chrono::steady_clock::now();
    std::sort(test_vector_func.begin(), test_vector_func.end());
    auto end = std::chrono::steady_clock::now();

    auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    std::cout << "The time of vec func: " << elapsed_ms.count() << " mc\n";
    std::cout << "The time of vec method: " << "hasnt got sort method" << " mc\n";

    //test array, it hasnt method sort
    begin = std::chrono::steady_clock::now();
    std::sort(test_array_func.begin(), test_array_func.end());
    end = std::chrono::steady_clock::now();

    elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    std::cout << "The time of array func: " << elapsed_ms.count() << " mc\n";
    std::cout << "The time of array method: " << "hasnt got sort method" << " mc\n";
    
    //test deque, it hasnt method sort
    begin = std::chrono::steady_clock::now();
    std::sort(test_deque_func.begin(), test_deque_func.end());
    end = std::chrono::steady_clock::now();

    elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    std::cout << "The time of deque func: " << elapsed_ms.count() << " mc\n";
    std::cout << "The time of deque method: " << "hasnt got sort method" << " mc\n";


    //test forward list
    std::cout << "The time of forward_list function: " << "hasnt got func" << " mc\n";

    //method
    begin = std::chrono::steady_clock::now();
    test_forward_list.sort();
    end = std::chrono::steady_clock::now();

    elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    std::cout << "The time of forward_list method: " << elapsed_ms.count() << " mc\n";

    //test list
    std::cout << "The time of list function: " << "hasnt got func" << " mc\n";

    //method
    begin = std::chrono::steady_clock::now();
    test_list.sort();
    end = std::chrono::steady_clock::now();

    elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    std::cout << "The time of list method: " << elapsed_ms.count() << " mc\n";

}
