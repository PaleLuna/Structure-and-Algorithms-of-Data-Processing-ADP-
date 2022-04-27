#pragma once

const unsigned short DEFAULTCAPACITY = 20;

class Stacks
{
	public:
		Stacks(unsigned capacity = DEFAULTCAPACITY);
		~Stacks();

		bool Push(int data, bool firstSrack);
		bool Pop(int& var, bool firstStack);

	private:
		unsigned capacity;
		unsigned firstStackSize;
		unsigned secondStackSize;

		int* stacks;

		void PushFirst(int data);
		void PushSecond(int data);

		void PopFirst(int& var);
		void PopSecond(int& var);
};

