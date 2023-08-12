#pragma once
#include <memory>
#include <vector>

template <typename T>
class Pool
{
private:
	std::vector<std::shared_ptr<T>> pool;

public:

	Pool<T>(int poolSize);
	~Pool();

	std::shared_ptr<T> Get();
	void Release(std::shared_ptr<T> obj);
};


