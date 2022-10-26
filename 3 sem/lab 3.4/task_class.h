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
		return _prev;
	}

	void set_prev(ListNode* prev)
	{
		_prev = prev;
	}

	ListNode* get_next()
	{
		return _next;
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
		_first = nullptr;
		_last = nullptr;
	}
	void push_front(T value)
	{
		if (_first == nullptr)
		{
			_first = _last = new ListNode<T>(value);
			_first->set_prev(_last);
			_last->set_next(_first);
			_first->set_value(value);
			return;
		}
		else
		{
			auto new_node =  new ListNode<T>(value);
			new_node->set_prev(_last);
			new_node->set_next(_first);
			new_node->set_value(value);
			_first = new_node;
		}
	}
	void push_back(T value)
	{
		if (_first == nullptr)
		{
			_first = _last = new ListNode<T>(value);
			_first->set_prev(_last);
			_last->set_next(_first);
			_last->set_value(value);
			return;
		}
		else
		{
			auto new_node = new ListNode<T>(value);
			new_node->set_prev(_last);
			new_node->set_next(_first);
			new_node->get_prev()->set_next(new_node);
			new_node->get_next()->set_prev(new_node);
			new_node->set_value(value);
			_last = new_node;
		}
	}
	void pop_back(T value)
	{
		if (_first == nullptr)
		{
			cout << "список и так пустой, остановитесь\n";
		}
		else
		{
			auto prelast = _last->get_prev();
			delete _last;
			_last = prelast;
			_last->set_next(first);
			_last->set_prev(prelast->prev);
		}
	}
	void pop_front(T value)
	{
		if (_first == nullptr)
		{
			cout << "список и так пустой, остановитесь\n";
		}
		else
		{
			auto next_next = _first->get_next();
			delete _first;
			_first=next_next;
			_last->set_next(next_next->next);
			_last->set_prev(_last);
		}
	}
	ListNode<T>* first()
	{
		return _first;
	}
	ListNode<T>* last()
	{
		return _last;
	}

private:
	ListNode<T>* _first;
	ListNode<T>* _last;
};