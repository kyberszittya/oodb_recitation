#pragma once

#include "Person.h"
#include <iostream>

template <class T> class LinkedList;

template<class T> class LinkedListElem{
private:
	T *elem;
	LinkedListElem<T> *next;
public:
	LinkedListElem(T *elem):elem(elem), next(nullptr){}
	void setNextElement(LinkedListElem<T> *next){
		this->next = next;
	}
	friend LinkedList<T>;
};

template<class T> class LinkedList
{
private:
	LinkedListElem<T>* first;
	LinkedListElem<T>* last;
public:
	LinkedList() : first(nullptr), last(nullptr){}

	~LinkedList(){
		for (LinkedListElem<T>* elem = first;elem != nullptr;){
			LinkedListElem<T> *tmp_elem;
			tmp_elem = elem; 
			elem = elem->next;
			delete tmp_elem;
		}
	}

	void addNext(T *elem)
	{
		if (first == nullptr)
		{
			last = new LinkedListElem<T>(elem);
			first = last;
		}
		else
		{
			last->setNextElement(new LinkedListElem<T>(elem));
			last = last->next;
		}
	}

	void print()
	{
		for (LinkedListElem<T>* elem = first;
			elem != nullptr; elem = elem->next)
		{
			std::cout << *(elem->elem) << std::endl;
		}
	}
};