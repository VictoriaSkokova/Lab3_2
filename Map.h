#pragma once
#include <iostream>
#include "Iterator.h"
#include "LinkedList.h"

using namespace std;

template <class item> class queue
{
	item *Queue; int head, tail, size_, Max;
public:
	queue(int maxQ) : head(0), tail(0), Max(maxQ), size_(0), Queue(new item[maxQ + 1]) {}
	~queue();
	bool empty() const { return (head % Max) == tail; }
	int size() const { return size_; }
	void push(item & item) { Queue[tail++] = item; tail %= Max; ++size_; }
	item front() const { return Queue[head % Max]; }
	void pop() { head++; head %= Max; --size_; }
};

template <class item>
queue<item>::~queue()
{
	free(Queue);
}

template <typename T >
class Map 
{
private:

	class Node
	{

	public:
		Node(T key, Node * next1 = nullptr, Node * next2 = nullptr) {
			this->next_left = next1;
			this->next_right = next2;
			this->key = key;
			this->parent = nullptr;
			this->color = 1;
			this->frequancy = 0;
			this->code = {};

		};
		bool color;
		size_t frequancy;
		string code;
		T key;
		Node * next_right, *next_left, *parent;

	};

	Node * root;
	size_t size;
public:
	Map();
	~Map();

	void set_code(string str, char data) { find(data)->code = str; };
	string get_code(char data) { return find(data)->code; };
	class TreeIterator : public Iterator<T> {
	protected:
		Node *current;
		TreeIterator(Node* root) : current(root) { }

	public:
		bool operator==(const nullptr_t) const override { return current == nullptr; }
		bool operator!=(const nullptr_t) const override { return !operator==(nullptr); }
		size_t operator*() const override
		{
			return current->frequancy;
		}
		T current_key()
		{
			return current->key;
		}
		bool current_color() { return current->color; }
		T current_code()
		{
			return current->code;
		}
		Node *get_cur() { return current; }
	};



	class BftIterator : public TreeIterator {
	private:
		queue<Node*> Nodes;
	public:
		BftIterator(Node *root, size_t size) : TreeIterator(root), Nodes(size) {}
		void operator++(int) override;
	};
	void reset_list();

	Node *get_leaf(Node *);
	void add_first(T);
	void remove(T);
	void delfix(Node*);
	Node * find(T);

	List <T> get_keys();
	void get_value();
	void clear();
	void insert(T);
	void insertfix(Node *&t);
	void leftrotate(Node *);
	void rightrotate(Node *);
	BftIterator create_bft_iterator() { return BftIterator(root, size); }
};



template<typename T>
void Map<T>::BftIterator::operator++(int)
{
	if (this->current->next_left != nullptr)
		Nodes.push(this->current->next_left);
	if (this->current->next_right != nullptr)
		Nodes.push(this->current->next_right);
	if (Nodes.size() > 0) {
		this->current = Nodes.front();
		Nodes.pop();
	}
	else
		this->current = nullptr;
}
