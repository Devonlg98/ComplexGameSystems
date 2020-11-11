#include <mutex>		//std::mutex
#include <queue>		//std::queue
#include <atomic>		//std::atomic

class tCircularQueue
{
public:
	tCircularQueue();
	tCircularQueue(size_t capacity);
	~tCircularQueue();

	bool push(const int& val);
	bool pop(int& val);

	bool empty() const;
	bool full() const;

private:
	size_t increment(size_t index) const;

	std::atomic<size_t> m_read_index;
	std::atomic<size_t> m_write_index;

	static const int SIZE = 11;
	int m_data[SIZE];
};