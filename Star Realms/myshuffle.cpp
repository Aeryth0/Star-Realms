#include "myshuffle.hpp" 
#include <algorithm> 
#include <cstdlib>  
#include <vector>
#include <memory>
#include <Windows.h>

// SHUFFLE FONKSÝYONU
void myshuffle(std::vector<std::unique_ptr<card2>>& data) {
    int count = data.size();
    int seed = rand() * GetTickCount();
    srand(seed);

    for (int i = 0; i < count; ++i) {

        int j = rand() % count;
        std::swap(data[i], data[j]);
    }
}
