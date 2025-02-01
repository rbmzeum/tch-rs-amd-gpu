#include <torch/torch.h>
#include <iostream>

int main() {
    torch::Device device(torch::kCUDA, 0);

    // Вывод списка доступных устройств
    if (torch::cuda::is_available()) {
        std::cout << "CUDA is available! Devices:" << std::endl;
        for (int i = 0; i < torch::cuda::device_count(); ++i) {
            std::cout << "Device " << i << std::endl;
        }
    } else {
        std::cout << "No GPU devices available. Using CPU." << std::endl;
        device = torch::Device(torch::kCPU);
    }

    // Создаем тензор и перемещаем его на выбранное устройство.
    auto tensor = torch::tensor({1.0, 2.0, 3.0}).to(device);
    
    // Выводим тензор.
    std::cout << tensor << std::endl;

    return 0;
}
