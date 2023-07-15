#pragma once
template<class T> class Singleton
{
public:
	static T& Instance()
	{
		static T theSingleInstance; // assumes T has a protected default constructor
		return theSingleInstance;
	}
	//virtual ~Singleton(); //a virtual destructor is needed if we need to execute
	//code in the derived class' destructor.
};