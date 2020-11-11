#include <thread>		// std::thread
#include <mutex>		// std::mutex
#include <iostream>
#include <atomic>

std::mutex lockCout;	// Governs the use of console output

// Atmoic value can only be accessed by one thing at a time -- depending on settings
// This prevents multiple things from  
std::atomic<int>increments = 0;

void incrementValue()
{

	for (size_t i = 0; i < 10000; i++)
	{
		//order_seq_cst is the default order, sequential and consistent acrossed all threads
		// https://en.cppreference.com/w/cpp/atomic/memory_order
		// AIE slides also have info on this
		// Functionally equivalent to
		//++increments  
		increments.fetch_add(1, std::memory_order_seq_cst);
	}

}

int main()
{
	// Create a bunch of thread objects
	//
	// Since this is the parameter-less constructor, this doesn't actually
	// spawn a new thread of execution -- it's just empty

	std::thread funThreads[100];

	// Initalize all the thread objects and task them with calling the
	// printFunFacts function
	for (size_t i = 0; i < 100; i++)
	{
		funThreads[i] = std::thread(incrementValue);
	}


	for (size_t i = 0; i < 100; i++)
	{
		funThreads[i].join();
	}

	// Print final value of increments
	std::cout << increments << std::endl;
	//printFunFacts(5);

	return 0;
}