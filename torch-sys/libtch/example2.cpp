#include "torch_api.h"
#include <iostream>

int main() {
    // Проверяем доступность CUDA
    bool cuda_available = atc_cuda_is_available();
    
    if (cuda_available) {
        std::cout << "CUDA доступна! Устройства:" << std::endl;
        
        // Получаем количество CUDA устройств
        int device_count = atc_cuda_device_count();
        
        for (int i = 0; i < device_count; ++i) {
            std::cout << "Устройство " << i << std::endl;
            
            // Можно добавить дополнительную информацию об устройстве
            // используя другие функции torch_api
        }
    } else {
        std::cout << "CUDA недоступна. Используется CPU." << std::endl;
    }

    return 0;
} 