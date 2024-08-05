#include "waiting_once_api.hpp"

void waiting_once::call_once_waiting(init_function f)
{
	// TODO: implement this
	std::call_once(flag, [=]()
				   {
		f();
		cv.notify_all(); });
	std::unique_lock lock(mutex);
	cv.wait(lock);
	return;
}
