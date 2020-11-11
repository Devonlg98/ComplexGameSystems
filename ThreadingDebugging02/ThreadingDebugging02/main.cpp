#include <thread>		// std::thread
#include <mutex>		// std::mutex
#include <iostream>


std::mutex lockCout;	// Governs the use of console output

void printFunFacts(int num)
{

	// Get a lock to the console output
	// - Since this function is run first, this will get the lock first
	// - If the lock is acquired, execution continues
	// - if someone else has the lock, this blocks execution until 
	//   the lock can be obatined
	lockCout.lock();

	std::cout << "The are fun facts for the number " << num << std::endl;
	std::cout << "Five times my number is " << num * 5 << std::endl;
	if (num % 5 == 0)
	{
		std::cout << "This is evenly divisible by five" << std::endl;
	}
	else
	{
		std::cout << "This number is NOT divisible by five" << std::endl;
	}

	//Unlock mutex - this lets other threads access this resource
	lockCout.unlock();
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
		funThreads[i] = std::thread(printFunFacts, i);
	}


	for (size_t i = 0; i < 100; i++)
	{
		funThreads[i].join();
	}

	//printFunFacts(5);

	return 0;
}