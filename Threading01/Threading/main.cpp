#include <iostream>		// std::cout
#include <fstream>
#include <string>		// std::getline
#include <thread>		//std::thread for all platforms
#include <vector>		//std::vector
#include <mutex>		// std:mutex

#include "logger.h"


void print(int i)
{
	// Function-static
	// - Initialize once
	// - Global to any calls to this function
	// - Global across multiple threads
	static std::mutex myMutex;

	//myMutex.lock();

	// When destroyed on exit this will automatically unlock
	std::lock_guard<std::mutex> guard(myMutex);

	std::cout << "Hello Thread" << i <<"\n";
	std::cout << "Neon Green is my favorite color\n";
	std::cout << "Pineapple on pizza is great\n";

	//myMutex.unlock();


}



int main()
{

	// Creates a thread that executes a function
	std::vector<std::thread> threads;
	
	for (size_t i = 0; i < 50; i++)
	{
		threads.push_back(std::thread(print, i));
	}
	// Rejoins this to main thread
	// - a blocking operation that halts execution on this thread until it completes
	for (size_t i = 0; i < threads.size(); i++)
	{
		threads[i].join();
	}

	return 0;
}