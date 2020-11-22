#pragma once

// Így csinálhatunk interfészt
class Queue
{
public:
	virtual ~Queue() {};
	virtual void push() = 0;
	virtual void pop()  = 0;
};

template<class T> class LinkedList
{
public:
	void add_elem();
	void delete_elem();
	ListNode* get();
};

template<class T> class LifoList: public LinkedList<T>, Queue
{
public:
	virtual void push() override {}
	virtual void pop() override {}
};

template<class T> class FifoList : public LinkedList<T>, Queue
{
public:
	virtual void push() override {}
	virtual void pop() override {}
};