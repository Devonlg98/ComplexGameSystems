#include <iostream>		// std::cout
#include <thread>		//std::thread for all platforms
#include <mutex>		// std:mutex
#include <atomic>       // std::atomic
#include <chrono>

#include "BaseApplication.h"

class multithreaded_application : public BaseApplication
{
public:
    multithreaded_application();
    ~multithreaded_application() = default;
    void Tick() override;


private:
    std::thread m_render_thread;
    std::thread m_pathfinding_thread;
    std::mutex m_render_data_mutex;
    std::atomic<bool> m_waiting_to_write;

};
