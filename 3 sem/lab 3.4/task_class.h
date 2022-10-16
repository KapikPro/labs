#pragma once

template<typename T>
class ListNode
{
public:
	ListNode(T value)
	{
		_value = value;
		_prev = nullptr;
		_next = nullptr;
	}

	T get_value()
	{
		return _value;
	}

	void set_value(T value)
	{
		_value = value;
	}

	ListNode* get_prev()
	{
		return prev;
	}

	void set_prev(ListNode* prev)
	{
		_prev = prev;
	}

	ListNode* get_next()
	{
		return next;
	}

	void set_next(ListNode* next)
	{
		_next = next;
	}

private:
	T _value;
	ListNode* _prev;
	ListNode* _next;
};

template<typename T>
class LinkedList
{
public:
	LinkedList()
	{
		first = nullptr;
		last = nullptr;
	}
	void push_front(T value)
	{
		if (first == nullptr)
		{
			first = last = new ListNode<T>(value);
			first->set_prev(last);
			last->set_next(first);
			return;
		}
		else
		{
			auto new_node =  new ListNode<T>(value);
			new_node->prev->set_prev(last);
			new_node->next->set_next(first);
			first = new_node;
		}
	}
	void push_back(T value)
	{
		if (first == nullptr)
		{
			first = last = new ListNode<T>(value);
			first->set_prev(last);
			last->set_next(first);
			return;
		}
		else
		{
			auto new_node = new ListNode<T>(value);
			new_node->prev->set_prev(last);
			new_node->next->set_next(first);
			last = new_node;
		}
	}
	void pop_back(T value)
	{
		if (first == nullptr)
		{
			cout << "список и так пустой, остановитесь\n";
		}
		else
		{
			auto prelast = last->get_prev();
			delete last;
			last = prelast;
			last->set_next(first);
			last->set_prev(prelast->prev);
		}
	}
	void pop_front(T value)
	{
		if (first == nullptr)
		{
			cout << "список и так пустой, остановитесь\n";
		}
		else
		{
			auto next_next = first->get_next();
			delete first;
			first=next_next;
			last->set_next(next_next->next);
			last->set_prev(last);
		}
	}
private:
	ListNode<T>* first;
	ListNode<T>* last;
};