#include <iostream>
#include "bitset.hpp"

int main()
{
    try
    {
        // Create a Bitset object with an initial capacity of 16 bits
        Bitset myBitset(16);

        // Set some bits
        myBitset.set(3);
        myBitset.set(8);
        myBitset.set(15);

        // Print the contents of the bitset
        std::cout << "Bitset: ";
        for (int i = 0; i < 16; ++i)
        {
            std::cout << myBitset.test(i) << " ";
        }
        std::cout << std::endl;

        // Reset bit at index 3
        myBitset.reset(3);

        // Flip bit at index 6
        myBitset.flip(6);

        // Print the modified contents of the bitset
        std::cout << "Modified Bitset: ";
        for (int i = 0; i < 16; ++i)
        {
            std::cout << myBitset.test(i) << " ";
        }
        std::cout << std::endl;

        // Reverse the order of bits in the bitset
        myBitset.reverse();

        // Print the reversed contents of the bitset
        std::cout << "Reversed Bitset: ";
        for (int i = 0; i < 16; ++i)
        {
            std::cout << myBitset.test(i) << " ";
        }
        std::cout << std::endl;

        // Add some elements using push_back()
        myBitset.push_back(1);
        myBitset.push_back(0);
        myBitset.push_back(1);

        // Print the updated contents of the bitset
        std::cout << "Updated Bitset: ";
        for (int i = 0; i < 19; ++i) // 16 (original) + 3 (push_back)
        {
            std::cout << myBitset.test(i) << " ";
        }
        std::cout << std::endl;

        // Remove the last element using pop_back()
        myBitset.pop_back();

        // Print the final contents of the bitset
        std::cout << "Final Bitset: ";
        for (int i = 0; i < 18; ++i) // 16 (original) + 2 (pop_back)
        {
            std::cout << myBitset.test(i) << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
