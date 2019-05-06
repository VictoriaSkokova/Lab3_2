#pragma once
#include <iostream>

using namespace std;

template <typename T>
class List
{
private:
	void add_first(T newElem, size_t);


	class Node
	{
	public:
		Node(T data, size_t fr, Node * next = nullptr) {
			this->data = data;
			this->next = next;
			this->prev = nullptr;
			this->freq = fr;
			this->code = {};
		}
		T data;
		size_t freq;
		string code;
		Node * prev;
		Node * next;
	};

	Node * current;
	Node * head;
	Node * tail;
	size_t size;
	size_t average_frequancy(Node*, Node*);
	void set_code(Node*, Node*, char); 
public:

	List();
	~List();

	size_t get_size() const;
	void push_back(T newElem, size_t);
	void push_front(T newElem, size_t);
	void pop_back();
	void pop_front();
	void print();
	string get_code_list(size_t);
	size_t get_freq_list(size_t);
	T get_alphabet_list(size_t);
	char get_data_list(size_t);  
	T at(size_t index) const;
	Node* get_back() { return tail; }; 
	Node* get_front() { return head; };  
	bool isEmpty();
	void set(size_t index, T newElem);
	void clear();
	void Delete(size_t);
	void insert(T, size_t, size_t);
	void sorting(Node*, Node*);  
	void make_group(Node*, Node*); 
	bool compare_str(string, string, int&); 

};
