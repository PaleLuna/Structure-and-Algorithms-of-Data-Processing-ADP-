#pragma once

const unsigned short DEFAULTCAPACITY = 20;

class Stack
{
	public:
		Stack(unsigned capacity = DEFAULTCAPACITY);
		~Stack();

		bool Push(int var);
		bool Pop(int& var);
		bool GetHead(int& var);
		bool IsEmpty();
		void Clear();

	private:
		unsigned capacity;
		unsigned size;
		int* stack;
};

