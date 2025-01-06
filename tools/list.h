#ifndef __LIST_H__
#define __LIST_H__

#include<mutex>
#include<condition_variable>
#include<queue>
#include<memory>

/**
 * @brief 消息队列
 */
template<class T> class MessageQueue
{
public:
	typedef std::shared_ptr<MessageQueue> ptr;

	/**
     * @brief 推入消息
     */
	void push(const T& msg)
    {
		std::unique_lock<std::mutex>lck(_mtx);
		_queue.push(msg);
		_cv.notify_one();
	}

    /**
     * @brief 轮询消息
     */
	bool poll(T& msg)
    {
		std::unique_lock<std::mutex>lck(_mtx);
		if (_queue.size())
		{
			msg = _queue.front();
			_queue.pop();
			return true;
		}
		return false;
	}

    /**
     * @brief 等待消息
     */
	void wait(T& msg)
    {
		std::unique_lock<std::mutex>lck(_mtx);
		while (!_queue.size()) _cv.wait(lck);
		msg = _queue.front();
		_queue.pop();
	}

    /**
     * @brief 消息大小
     */
	size_t size()
    {
		std::unique_lock<std::mutex>lck(_mtx);
		return _queue.size();
	}
private:
	//队列
	std::queue<T> _queue;
	//互斥变量
	std::mutex _mtx;
	//条件变量
	std::condition_variable _cv;
};

#endif // !LIST_H