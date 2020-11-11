#include "tCircularQueue.h"

tCircularQueue::tCircularQueue() : m_read_index(0), m_write_index(0)
{

}

tCircularQueue::tCircularQueue(size_t capacity)
{

}

tCircularQueue::~tCircularQueue()
{

}

bool tCircularQueue::push(const int& val)
{
	// Check if queue is full
	if (full())
	{
		return false;
	}
	
	// If queue isn't full add an item to the array
	auto current_index = m_write_index.load();
	// Increment the write index
	auto next_index = increment(current_index);
	m_data[current_index] = val;
	m_write_index.store(next_index);
	return true;

}

bool tCircularQueue::pop(int& val)
{
	// Check if queue is empty
	if (empty())
	{
		return false;
	}

	// Read data from queue
	auto current_index = m_read_index.load();
	// Increment read index
	val = m_data[current_index];
	m_read_index.store(increment(current_index));
	return true;
}


bool tCircularQueue::empty() const
{
	return m_read_index.load() == m_write_index.load();
}

bool tCircularQueue::full() const
{
	const auto next_write_index = increment(m_write_index.load());
	return (next_write_index == m_read_index.load());
}

size_t tCircularQueue::increment(size_t index) const
{
	return (index + 1) % SIZE;
}
