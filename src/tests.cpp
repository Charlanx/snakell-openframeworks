#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/ll.h"
#include <iostream>

using namespace snakelinkedlist;

TEST_CASE("push_front") {
LinkedList * linkedList = new LinkedList();

SnakeBodySegment * sb1 = new SnakeBodySegment(0);
SnakeBodySegment * sb2 = new SnakeBodySegment(1);
SnakeBodySegment * sb3 = new SnakeBodySegment(2);
linkedList->push_front(*sb1);
linkedList->push_front(*sb2);

	REQUIRE_THAT(head->value == sb1);
	
}

TEST_CASE("push back") {
	LinkedList *linkedList = new LinkedList();

	SnakeBodySegment * sb1 = new SnakeBodySegment(0);
	SnakeBodySegment * sb2 = new SnakeBodySegment(1);
	SnakeBodySegment * sb3 = new SnakeBodySegment(2);

	linkedList->push_front(*sb1);
	linkedList->push_back(*sb2);






	REQUIRE_THAT(head->value == sb1);

}
TEST_CASE("empty") {
	LinkedList *linkedList = new LinkedList();

	SnakeBodySegment * sb1 = new SnakeBodySegment(0);
	SnakeBodySegment * sb2 = new SnakeBodySegment(1);
	SnakeBodySegment * sb3 = new SnakeBodySegment(2);

	linkedList->push_front(*sb1);
	linkedList->push_back(*sb2);
	linkedList->clear();




	REQUIRE_THAT(linkedList.empty() == true);
}
TEST_CASE("size") {
	LinkedList *linkedList = new LinkedList();

	SnakeBodySegment *sb1 = new SnakeBodySegment(0);
	SnakeBodySegment *sb2 = new SnakeBodySegment(1);
	SnakeBodySegment *sb3 = new SnakeBodySegment(2);

	linkedList->push_front(*sb1);
	linkedList->push_front(*sb2);
	linkedList->push_front(*sb3);


	REQUIRE_THAT(linkedList.size() == 3);

}
TEST_CASE("pop_front") {
	LinkedList *linkedList = new LinkedList();

	SnakeBodySegment *sb1 = new SnakeBodySegment(0);
	SnakeBodySegment *sb2 = new SnakeBodySegment(1);
	SnakeBodySegment *sb3 = new SnakeBodySegment(2);
	SnakeBodySegment *sb4 = new SnakeBodySegment(3);
	SnakeBodySegment *sb5 = new SnakeBodySegment(4);
	SnakeBodySegment *sb6 = new SnakeBodySegment(5);

	linkedList->push_front(*sb1);
	linkedList->push_front(*sb2);
	linkedList->push_front(*sb3);
	linkedList->push_front(*sb4);
	linkedList->push_front(*sb5);
	linkedList->push_front(*sb6);
	linkedList->pop_front();

	REQUIRE_THAT(linkedList.size == 5);

}
TEST_CASE("pop_back") {
	LinkedList *linkedList = new LinkedList();

	SnakeBodySegment *sb1 = new SnakeBodySegment(0);
	SnakeBodySegment *sb2 = new SnakeBodySegment(1);
	SnakeBodySegment *sb3 = new SnakeBodySegment(2);
	SnakeBodySegment *sb4 = new SnakeBodySegment(3);
	SnakeBodySegment *sb5 = new SnakeBodySegment(4);
	SnakeBodySegment *sb6 = new SnakeBodySegment(5);

	linkedList->push_front(*sb1);
	linkedList->push_front(*sb2);
	linkedList->push_front(*sb3);
	linkedList->push_front(*sb4);
	linkedList->push_front(*sb5);
	linkedList->push_front(*sb6);
	linkedList->pop_back();
	linkedList->pop_back();
	linkedList->pop_back();
	linkedList->pop_back();
	linkedList->pop_back();


	REQUIRE_THAT(head == sb1);

}
//Cited by
//https://stackoverflow.com/questions/14373934/iterator-loop-vs-index-loop
TEST_CASE("Iterator") {
	LinkedList * ll = new LinkedList<ElementType>();
	std::vector<ElementType> elementOfVectors = ll.GetVector();
	SnakeBodySegment *sb1 = new SnakeBodySegment(0);
	SnakeBodySegment *sb2 = new SnakeBodySegment(1);
	SnakeBodySegment *sb3 = new SnakeBodySegment(2);
	elementOfVectors.add(sb1);
	elementOfVectors.add(sb2);
	elementOfVectors.add(sb3);
	Iterator *it = new Iterator();
	for (auto it = elementOfVectors.begin(); it != elementOfVectors.end(); ++it) {
		it.add(*it);
	}
	REQUIRE_THAT(it == elementOfVectors);
	
