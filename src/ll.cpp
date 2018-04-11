#include <utility>
#include "C:/Users/Charlie Jung/Desktop/Template/templatell/templatell/ref_ll.h"

template<typename ElementType>
snakelinkedlist::LinkedList<ElementType>::LinkedList() : head_(nullptr), size_(0) {
	head_ = nullptr;
}

template<typename ElementType>
snakelinkedlist::LinkedList<ElementType>::LinkedList(const std::vector<ElementType> &values) : head_(nullptr), tail_(nullptr), size_(0) {
	for (int unsigned i = 0; i < values.size(); i++) {
		this->push_back(values[i]);
	}
}

// Copy constructor
template<typename ElementType>
snakelinkedlist::LinkedList<ElementType>::LinkedList(const LinkedList<ElementType>& source) {
	if (this == &source) {
		return;
	}
	head_ = nullptr;
	ListNode *current_node = source.head;
	while (current_node != nullptr) {
		push_back(current_node->value_);
		current_node = current_node->next_;

	}
}

// Move constructor
template<typename ElementType>
snakelinkedlist::LinkedList<ElementType>::LinkedList(LinkedList<ElementType>&& source) noexcept {
	if (*this == source) {
		return *this;
	}
	ListNode * new_pointer = this->head;
	ListNode * source_pointer = source.head;
	while (source_pointer != nullptr) {
		ListNode * temp_node = new ListNode();
		new_pointer->next_ = temp_node;
		push_front(source_pointer->value_);
		temp_node->value_ = source_pointer->value_;
		temp_node->next_ = nullptr;
		source_pointer = source_pointer->next_;
		delete temp_node;
	}
	return *this;
}

// Destructor
template<typename ElementType>
snakelinkedlist::LinkedList<ElementType>::~LinkedList() {
	clear();
}

// Copy assignment operator
template<typename ElementType>
snakelinkedlist::LinkedList<ElementType>& LinkedList<ElementType>::operator= (const LinkedList<ElementType>& source) {
	if (*this == source) {
		return *this;
	}
	ListNode * source_pointer = source.head;
	while (source_pointer != nullptr) {
		this->clear();
		this->push_back(source_pointer->value_);
		source_pointer = source_pointer->next_;
	}
	return *this;
}

// Move assignment operator
template<typename ElementType>
snakelinkedlist::LinkedList<ElementType>& LinkedList<ElementType>::operator= (LinkedList<ElementType>&& source) noexcept {
	if (*this == source) {
		return *this;
	}
	ListNode * new_pointer = this->head;
	ListNode * source_pointer = source.head;
	while (source_pointer != nullptr) {
		ListNode * temp_node = new ListNode();
		new_pointer->next_ = temp_node;
		push_front(source_pointer->value_);
		temp_node->value_ = source_pointer->value_;
		temp_node->next_ = nullptr;
		source_pointer = source_pointer->next_;
		delete temp_node;
	}
	return *this;
}

template<typename ElementType>
void snakelinkedlist::LinkedList<ElementType>::push_front(ElementType value) {
	ListNode *new_node = new ListNode();
	new_node->next_ = head_;
	new_node->value_ = value;
	head_ = new_node;
}

template<typename ElementType>
void snakelinkedlist::LinkedList<ElementType>::push_back(ElementType value) {
	if (empty()) {
		ListNode * current_node = new ListNode();
		current_node->value_ = value;
		current_node->next_ = nullptr;
		head_ = current_node;
		return;
	}
	ListNode * current_node = nullptr;
	current_node = head_;
	while (current_node->next_ != nullptr) {
		current_node = current_node->next_;
	}
	ListNode * new_node = new ListNode();
	current_node->next_ = new_node;
	new_node->next_ = nullptr;
	new_node->value_ = value_;
}

template<typename ElementType>
snakelinkedlist::ElementType LinkedList<ElementType>::front() const{
	if (empty()) {
		return ElementType();
	}
	return head_->value_;
}

template<typename ElementType>
snakelinkedlist::ElementType LinkedList<ElementType>::back() const {
	if (empty()) {
		return ElementType();
	}
	ListNode * current_node = nullptr;
	current_node = head_;
	while (current_node->next_ != nullptr) {
		current_node = current_node->next_;
	}
	return current_node->value_;
	
}

template<typename ElementType>
void snakelinkedlist::LinkedList<ElementType>::pop_front() {
	if (empty()) {
		return;
	}
	ListNode * temp_pointer = nullptr;
	temp_pointer = head_;
	head_ = head_->next_;
	delete temp_pointer;
}

template<typename ElementType>
void snakelinkedlist::LinkedList<ElementType>::pop_back() {
	if (empty()) {
		return;
	}
	ListNode * current_node = nullptr;
	current_node = head_;
	if (current_node->next_ == nullptr) {
		delete current_node;
		return;
	}
	while (current_node->next_->next_ != nullptr) {
		current_node = current_node->next_;
	}
	ListNode * last_node = current_node->next_;
	current_node->next_ = nullptr;
	delete last_node;
}

template<typename ElementType>
int snakelinkedlist::LinkedList<ElementType>::size() const {
	int sizeOfLinkedList = 0;
	ListNode * current_node = nullptr;
	current_node = head_;
	if (current_node->next_ == nullptr) {
		return 1;
	}
	while (current_node_ != nullptr) {
		current_node = current_node->next_;
		sizeOfLinkedList++;
	}
	return sizeOfLinkedList;
 }

template<typename ElementType>
snakelinkedlist::std::vector<ElementType> LinkedList<ElementType>::GetVector() const {
	std::vector<ElementType> temp_vector;
	ListNode * current_node = nullptr;
	current_node = head_;
	while (current_node != nullptr) {
		temp_vector.push_back(current_node->value_);
	}
	return temp_vector;
}

template<typename ElementType>
bool snakelinkedlist::LinkedList<ElementType>::empty() const {
	if (head_ == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

template<typename ElementType>
void snakelinkedlist::LinkedList<ElementType>::clear() {
	if (this->head_ == nullptr) {
		return;
	}
	ListNode * current_node = nullptr;
	current_node = head_;
	while (current_node != nullptr) {
		ListNode * temp_pointer = current_node;
		current_node = current_node->next_;
		delete temp_pointer;
	}
}

template<typename ElementType>
snakelinkedlist::std::ostream& operator<<(std::ostream& os, const LinkedList<ElementType>& list) {
	if (list.head_ == nullptr) {
		return os;
	}
	ListNode * current = list.head_;
	while (current == nullptr) {
		ElementType sbs = current->value_;
		os << sbs << ", ";
		current = current->next;
	}
	ElementType sbs = current->value_;
	os << sbs;
	return os;
}

template<typename ElementType>
void snakelinkedlist::LinkedList<ElementType>::RemoveNth(int n) {
	ListNode * current = head_;
	int count = 0;
	while (current != nullptr) {
		current = current->next_;
		count += 1;
	}
	if (n < 0 || n > count) {
		return;
	}
	current = head_;
	for (int i = 0; i < count; i++) {
		if (n == 0) {
			ListNode * temp = nullptr;
			temp = current->next_;
			head_ = temp;
			delete current;
			return;

		}
		if (i == (n - 1)) {
			//if n is at the head or the tail.
			ListNode * temp = current->next_;
			current->next_ = current->next_->next_;
			delete temp;
			break;
		}
		if (n == (count - 1)) {
			ListNode * temp = nullptr;
			temp = current->next_;
			current->next_ = nullptr;
			delete temp;
			return;
		}
		current = current->next_;

	}
}


template<typename ElementType>
bool snakelinkedlist::LinkedList<ElementType>::operator==(const LinkedList<ElementType> &rhs) const {
	ListNode * left_pointer = this->head_;
	ListNode * right_pointer = rhs.head_;
	while (left_pointer != nullptr || right_pointer != nullptr) {
		if (left_pointer != right_pointer) {
			return false;
		}
		left_pointer = left_pointer->next_;
		right_pointer = right_pointer->next_;
	}
	return true;
}

template<typename ElementType>
bool snakelinkedlist::operator!=(const LinkedList<ElementType>& lhs, const LinkedList<ElementType> &rhs) {
	return !(lhs == rhs);
}

template<typename ElementType>
typename snakelinkedlist::LinkedList<ElementType>::Iterator& LinkedList<ElementType>::Iterator::operator++() {

}
//Cited from:
//https://courses.engr.illinois.edu/cs126/sp2018/slides/L21-Templates.pdf

template<typename ElementType>
ElementType& snakelinkedlist::LinkedList<ElementType>::Iterator::operator*() {
	return current->value_;
}

//Cited from:
//https://courses.engr.illinois.edu/cs126/sp2018/slides/L21-Templates.pdf
template<typename ElementType>
bool snakelinkedlist::LinkedList<ElementType>::Iterator::operator!=(const LinkedList<ElementType>::Iterator& other) {
	return (current != rhs.current);
}

//Cited from:
//https://courses.engr.illinois.edu/cs126/sp2018/slides/L21-Templates.pdf
template<typename ElementType>
typename snakelinkedlist::LinkedList<ElementType>::Iterator LinkedList<ElementType>::begin() {
	Iterator start;
	start.current = head_;
	return start;
}

//Cited from:
//https://courses.engr.illinois.edu/cs126/sp2018/slides/L21-Templates.pdf
template<typename ElementType>
typename snakelinkedlist::LinkedList<ElementType>::Iterator LinkedList<ElementType>::end() {
	Iterator stop;
	stop.current = nullptr;
	return stop;
}



//Cited from:
//https://www.ics.uci.edu/~irani/s11_22/CodeExamples/GenericList.java
template<typename ElementType>
snakelinkedlist::LinkedList<ElementType>::Iterator() : current_(nullptr) {
	LinkedList<ElementType> list = new LinkedList < ElementType();
	LinkedList<ElementType>.Iterator iterator = list.iterator();
}
