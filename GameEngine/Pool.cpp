#include "Pool.h"

template <typename T>
Pool<T>::Pool(int poolSize)
{
	for (int i = 0; i < poolSize; ++i) {
		pool.push_back(std::make_shared<T>());
	}
}

template <typename T>
std::shared_ptr<T> Pool<T>::Get()
{
	if (!pool.empty())
	{
		std::shared_ptr<T> obj = pool.back();
		pool.pop_back();
		return obj;
	}
	return nullptr;
}

template <typename T>
void Pool<T>::Release(std::shared_ptr<T> obj)
{
	pool.push_back(obj);
}
