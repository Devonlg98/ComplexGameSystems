
#include <iostream>		//std::cout
#include <thread>

#include "tCircularQueue.h"




void push_function(tCircularQueue& a_circular_queue);
void pop_function(tCircularQueue& a_circular_queue);

const int MAX_VALUE = 50;

int main()
{
	tCircularQueue m_circular_queue;

	auto publisher = std::thread(push_function, std::ref(m_circular_queue));


	auto consumer = std::thread(pop_function, std::ref(m_circular_queue));

	consumer.join();
	publisher.join();
	return 0;
}


void push_function(tCircularQueue& a_circular_queue)
{
	int count = 0;
	while (count <= MAX_VALUE)
	{
		if (a_circular_queue.push(count))
		{
			std::cout << "Pushed " << count << " to the queue" << std::endl;
			count++;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void pop_function(tCircularQueue& a_circular_queue)
{
	int value = 0;
	while (value < MAX_VALUE)
	{
		if (a_circular_queue.pop(value))
		{
			std::cout << "Poppped " << value << " from the queue" << std::endl;
			value++;
		}
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}
}
