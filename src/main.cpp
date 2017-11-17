#include <cstddef>
#include <cstdlib>
#include <string>
#include <iostream>
#include <chrono>
#include "Vector.h"
#include "LinkedList.h"



void test_appending();

void test_erasing();

void test_pop_first();

void test_pop_last();

void test_insert();

void perfomTest()
{
 system("clear");
 std::cout << "-----------------------------------------------------------------------\n";
 std::cout << "/Time Compare Test Menu/\n";
 std::cout << "/1/ Compare append 100000 int objects\n";
 std::cout << "/2/ Compare erase middle object from collection of 10000000 ints\n";
 std::cout << "/3/ Compare pop first object from collection of 100000 doubles\n";
 std::cout << "/4/ Compare pop last object from collection of 100000 doubles\n";
 std::cout << "/5/ Compare insert object in the middle of collection of 1000000 booleans \n";
 std::cout << "------------------------------------------------------------------------\n";
 std::cout << "Your choice:  ";

 int choice;
 std::cin >> choice;
 if (choice < 1 || choice > 5)
 {
     std::cout << "Select proper operation!";
     return;
 }
 switch(choice)
 {
     case 1:    test_appending();
                break;
     case 2:    test_erasing();
                break;
     case 3:    test_pop_first();
                break;
     case 4:    test_pop_last();
                break;
     case 5:    test_insert();
                break;
 }


}

void test_appending()
{
    aisdi::Vector<int> test_vector;
    aisdi::LinkedList<int> test_list;
    auto t1 = std::chrono::high_resolution_clock::now();

    for(int i=0;i<100000;i++)
        test_vector.append(i);

    auto t2 = std::chrono::high_resolution_clock::now();

    std::cout << "Vector appending took " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " milliseconds\n";

    auto t3 = std::chrono::high_resolution_clock::now();
    for(int i=0; i<100000; i++)
        test_list.append(i);

    auto t4 = std::chrono::high_resolution_clock::now();

    std::cout << "List appending " << std::chrono::duration_cast<std::chrono::milliseconds>(t4-t3).count() << " milliseconds\n";
    getchar();
    getchar();

}
void test_erasing()
{
    aisdi::Vector<int> test_vector;
    aisdi::LinkedList<int> test_list;
    for(int i = 0; i<10000000; i++)
    {
        test_list.append(14);
        test_vector.append(14);
    }
     auto t1 = std::chrono::high_resolution_clock::now(); 
     test_vector.erase(test_vector.end() - 500000);
     auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Vector erasing took " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " milliseconds\n";

    auto t3 = std::chrono::high_resolution_clock::now();
    test_list.erase(test_list.end() - 500000);
    auto t4 = std::chrono::high_resolution_clock::now();
    std::cout << "List erasing " << std::chrono::duration_cast<std::chrono::milliseconds>(t4-t3).count() << " milliseconds\n";
    getchar();
    getchar();
}

void test_pop_first()
{
    aisdi::Vector<double> test_vector;
    aisdi::LinkedList<double> test_list;
    for(int i = 0; i<100000; i++)
    {
        test_list.append(21.37);
        test_vector.append(21.37);
    }
    auto t1 = std::chrono::high_resolution_clock::now();
    test_vector.popFirst();
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Vector popFirst took " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " milliseconds\n";

    auto t3 = std::chrono::high_resolution_clock::now();
    test_list.popFirst();
    auto t4 = std::chrono::high_resolution_clock::now();
    std::cout << "List popFirst took " << std::chrono::duration_cast<std::chrono::milliseconds>(t4-t3).count() << " milliseconds\n";
    getchar();
    getchar();
}

void test_pop_last()
{
    aisdi::Vector<double> test_vector;
    aisdi::LinkedList<double> test_list;
    for(int i = 0; i<100000; i++)
    {
        test_list.append(21.37);
        test_vector.append(21.37);
    }
     auto t1 = std::chrono::high_resolution_clock::now();
    test_vector.popLast();
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Vector popLast took " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " milliseconds\n";

    auto t3 = std::chrono::high_resolution_clock::now();
    test_list.popLast();
    auto t4 = std::chrono::high_resolution_clock::now();
    std::cout << "List popLast took " << std::chrono::duration_cast<std::chrono::milliseconds>(t4-t3).count() << " milliseconds\n";
    getchar();
    getchar();
}

void test_insert()
{
    aisdi::Vector<bool> test_vector;
    aisdi::LinkedList<bool> test_list;
    for(int i = 0; i<1000000; i++)
    {
        test_list.append(1);
        test_vector.append(1);
    }
     auto t1 = std::chrono::high_resolution_clock::now();
    test_vector.insert(test_vector.begin()+500000, 0);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Vector inserting took " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " milliseconds\n";

    auto t3 = std::chrono::high_resolution_clock::now();
    test_list.insert(test_list.begin()+500000, 0);
    auto t4 = std::chrono::high_resolution_clock::now();
    std::cout << "List inserting took " << std::chrono::duration_cast<std::chrono::milliseconds>(t4-t3).count() << " milliseconds\n";
    getchar();
    getchar();
}



int main(int argc, char** argv)
{
  const std::size_t repeatCount = argc > 1 ? std::atoll(argv[1]) : 10000;

  for (std::size_t i = 0; i < repeatCount; ++i)
    perfomTest();


  return 0;
}

