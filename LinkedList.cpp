#include "LinkedList.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <math.h>


using namespace std;

template<typename T>
size_t List<T>::average_frequancy(Node* first, Node*last)
{
	Node* current = first;
	size_t sum = 0;
	while (current != last->next)
	{

		sum += current->freq;
		current = current->next;
	}
	return round(sum / 2.0);
}

template<typename T>
void List<T>::set_code(Node *first, Node *last, char sign)
{
	Node* current = first;
	while (current != last)
	{
		current->code += sign;
		current = current->prev;
	}
}

template<typename T>
List<T>::List()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
size_t List<T>::get_size() const
{
	return size;
}


template<typename T>
void List<T>::push_back(T newElem, size_t freq)
{
	if (size == 0) {
		head = new Node(newElem, freq);
		tail = head;
	}
	else {

		tail->next = new Node(newElem, freq);
		tail->next->prev = tail;
		tail = tail->next;
	}
	size++;

}


template<typename T>
void List<T>::push_front(T newElem, size_t freq)
{
	if (size == 0)
		add_first(newElem, freq);
	else
	{
		head->prev = new Node(newElem, freq, head);
		head = head->prev;

	}

	size++;
}


template<typename T>
void List<T>::pop_back()
{

	if (size == 0) return;

	if (size == 1) {
		head = nullptr;
		tail = nullptr;
		delete head;
		delete tail;

	}
	else {
		Node * current = head;
		do
		{
			current = current->next;
		} while (current->next != tail);
		current->next = nullptr;
		current->next->prev = nullptr;
		delete tail;
		tail = current;

	}
	size--;

}


template<typename T>
void List<T>::pop_front()
{
	if (size == 0) return;
	if (size == 1)
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
		return;
	}
	else
	{
		Node *current = head->next;
		head->next = nullptr;
		current->prev = nullptr;
		delete head;
		head = current;
	}
	size--;
}


template<typename T>
void List<T>::print()
{
	Node * current = tail;
	while (current != nullptr)
	{
		cout << current->data;
		cout << '-' << current->code << '-' << current->freq << '\n';
		current = current->prev;
	}

}


template<typename T>
string List<T>::get_code_list(size_t index)
{
	Node* current = head;
	int i = 0;
	while (i != index) { i++; current = current->next; }
	return current->code;
}

template<typename T>
size_t List<T>::get_freq_list(size_t index)
{
	Node* current = head;
	int i = 0;
	while (i != index) { i++; current = current->next; }
	return current->freq;
}

template<typename T>
T List<T>::get_alphabet_list(size_t index)
{
	Node* current = head;
	int i = 0;
	while (i != index) { i++; current = current->next; }
	return current->data;
}

template<typename T>
char List<T>::get_data_list(size_t index)
{
	Node* current = head;
	int i = 0;
	while (i != index) { i++; current = current->next; }
	return current->data;
}


template<typename T>
T List<T>::at(size_t index) const
{
	if (index >= size) {
		throw out_of_range("Index is greater than list size");
	}
	else {
		size_t count = 0;
		Node * current = head;
		while (count != index) {
			current = current->next;
			count++;
		}
		cout << current->data;
		return current->data;
	}
}


template<typename T>
bool List<T>::isEmpty()
{
	if (size == 0)
		return true;
	return false;
}


template<typename T>
void List<T>::set(size_t index, T newElem)
{

	if (index >= size) {
		return;
	}
	else {
		size_t count = 0;
		Node * current = head;
		while (count != index) {
			current = current->next;
			count++;
		}
		current->data = newElem;

	}
}

template<typename T>
void List<T>::clear()
{
	Node* current = head;
	while (current != nullptr)
	{
		Node* next = current->next;
		current = nullptr;
		delete current;
		current = next;
	}
	head = tail = nullptr;
	size = 0;
}



template<typename T>
void List<T>::Delete(size_t index)
{
	if (size == 0 || index > size) throw out_of_range("List is empty");

	Node * current = head;
	if (index == 0)
	{
		pop_front();
		return;
	}
	size_t i = index;
	while (i != index - 1)
	{
		current = current->next;
		i--;
	}
	if (current->prev != nullptr)
		current->prev->next = current->next;
	if (current->next->next != nullptr)
	{
		current->next = current->next->next;
		delete current;
	}
	else
	{
		current->next = nullptr;
		delete current->next;
	}

	if (size == 1)
		head = tail = nullptr;

	size--;
}

template<typename T>
void List<T>::insert(T newElem, size_t freq, size_t index)
{
	if (index >= size) {
		throw out_of_range("Index is greater than list size");
	}
	else {

		size_t count = 0;
		Node * current = head;
		if (index == 0)
		{
			push_front(newElem, freq);
		}
		else
		{
			while (count != index - 1) {
				current = current->next;
				count++;
			}

			Node *El = new Node(newElem, freq, current->next);
			current->next->prev = El;
			current->next = El;

		}
		size++;
	}
}


template<typename T>
void List<T>::add_first(T newElem, size_t freq)
{
	head = new Node(newElem, freq);
	tail = head;
}

template<typename T>
void List<T>::sorting(Node* left, Node* right)
{
	if (left == right) return;
	Node *start = left;
	Node *current = left->next;
	size_t frequancy;
	T inf;
	while (1)
	{
		if (start->freq >= current->freq)
		{
			frequancy = current->freq;
			inf = current->data;
			current->data = start->data;
			current->freq = start->freq;
			start->freq = frequancy;
			start->data = inf;
		}
		if (current == right) break;
		current = current->next;
	}
	frequancy = left->freq;
	inf = left->data;
	left->data = current->data;
	left->freq = current->freq;
	current->data = inf;
	current->freq = frequancy;
	Node *old_current = current;
	current = current->prev;
	if (current != nullptr)
	{
		if ((left->prev != current) && (current->next != left))
			sorting(left, current);
	}
	current = old_current;
	current = current->next;
	if (current != nullptr)
	{
		if ((current->prev != right) && (right->next != current))
			sorting(current, right);

	}
}

template<typename T>
void List<T>::make_group(Node *first, Node *last)
{
	if (last == first) return;
	if (last->prev == first) { first->code += '0'; last->code += '1'; }
	else
	{
		Node* current = first;
		Node* merge = nullptr;
		size_t sum = 0;
		size_t check = average_frequancy(first, last);
		while (current != last->next)
		{
			sum += current->freq;
			if (sum <= check || merge == nullptr)
			{
				current->code += '0';
				merge = current;
			}
			else
			{
				current->code += '1';

			}
			current = current->next;
		}
		make_group(first, merge);
		make_group(merge->next, last);
	}
}

template<typename T>
bool List<T>::compare_str(string str, string code, int &size)
{
	for (int i = 0; i < code.length(); i++)
	{
		size++;
		if (code[i] != str[i]) return false;
	}
	return true;
}