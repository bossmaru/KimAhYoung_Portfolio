#include "unordered_map"
#include "map"
#include "BinarySearchTree.h"

// 해쉬 테이블 : 메모리를 주고 탐색시간을 취한다.
// 탐색 : 상수 시간... 해쉬충돌로 인한 체이닝에 따라 달라질 수 있다.
// 삽입 : 상수 시간
// 충돌, 체이닝(리스트) 있음

// 자가균형이진탐색트리(map)
// 탐색 : logN
// 삽입 : logN

// 해쉬테이블(umordered map) vs 자가균형이진탐색트(map)
// 해쉬 함수 후 충돌이 많이 일어날 경우... 자가균형이진탐색트리 승
// 충돌이 적을 경우... 해쉬테이블 승

int main()
{
#pragma region BST
	BinarySearchTree bst;
	bst.Insert(50);
	bst.Insert(40);
	bst.Insert(70);
	bst.Insert(30);
	bst.Insert(45);

	// bst.PrintTree(bst._root);

	auto searchNode = bst.Search(bst._root, 45);
	if (searchNode != nullptr)
	{
		cout << "해당 노드를 찾았습니다" << endl;
		cout << searchNode->key << endl;
	}
	else
	{
		cout << "해당 노드가 없습니다." << endl;
	}

	cout << "최소 노드는 " << bst.Min(bst._root)->key << "입니다." << endl;
	cout << "최대 노드는 " << bst.Max(bst._root)->key << "입니다." << endl;


	auto Node = bst.Search(bst._root, 60);
	auto previousNode = bst.Previous(Node);
	auto nextNode = bst.Next(Node);
	if (previousNode != nullptr)
		cout << previousNode->key << endl;
	if (nextNode != nullptr)
		cout << nextNode->key << endl;
#pragma endregion

	unordered_map<int, int> um;

	um[5] = 1;

	return 0;
}