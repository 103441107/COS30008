// COS30008, Final Exam, 2021
#pragma once
#include <stdexcept>
template<typename T>
class TTreePostfixIterator;
template<typename T>
class TTree
{
private:
	T fKey;
	TTree<T>* fLeft;
	TTree<T>* fMiddle;
	TTree<T>* fRight;
	TTree() : fKey(T()) // use default constructor to initialize fKey
	{
		fLeft = &NIL; // loop-back: The sub-trees of a TTree object with
		fMiddle = &NIL; // no children point to NIL.
		fRight = &NIL;
	}
	void addSubTree(TTree<T>** aBranch, const TTree<T>& aTTree)
	{
		if (!(*aBranch)->empty())
		{
			delete* aBranch;
		}
		*aBranch = const_cast<TTree<T>*>(&aTTree);
	}
public:
	using Iterator = TTreePostfixIterator<T>;
	static TTree<T> NIL; // sentinel
	// getters for subtrees
	const TTree<T>& getLeft() const { return *fLeft; }
	const TTree<T>& getMiddle() const { return *fMiddle; }
	const TTree<T>& getRight() const { return *fRight; }
	// add a subtree
	void addLeft(const TTree<T>& aTTree) { addSubTree(&fLeft, aTTree); }
	void addMiddle(const TTree<T>& aTTree) { addSubTree(&fMiddle, aTTree); }
	void addRight(const TTree<T>& aTTree) { addSubTree(&fRight, aTTree); }
	// remove a subtree, may through a domain error
	const TTree<T>& removeLeft() { return removeSubTree(&fLeft); }
	const TTree<T>& removeMiddle() { return removeSubTree(&fMiddle); }
	const TTree<T>& removeRight() { return removeSubTree(&fRight); }
	// Problem 1: TTree Basic Infrastructure
private:
	// remove a subtree, may through a domain error
	const TTree<T>& removeSubTree(TTree<T>** aBranch);
public:
	// TTree l-value constructor
	TTree(const T& aKey);
	// destructor (free sub-trees, must not free empty trees)
	~TTree();
	// return key value, may throw domain_error if empty
	const T& operator*() const;
	// returns true if this TTree is empty
	bool empty() const;
	// returns true if this TTree is a leaf
	bool leaf() const;
	// Problem 2: TTree Copy Semantics
	// copy constructor, must not copy empty TTree
	TTree(const TTree<T>& aOtherTTree);
	// copy assignment operator, must not copy empty TTree
	TTree<T>& operator=(const TTree<T>& aOtherTTree);
	// clone TTree, must not copy empty trees
	TTree<T>* clone() const;
	// Problem 3: TTree Move Semantics
	// TTree r-value constructor
	TTree(T&& aKey);
	// move constructor, must not copy empty TTree
	TTree(TTree<T>&& aOtherTTree);
	// move assignment operator, must not copy empty TTree
	TTree<T>& operator=(TTree<T>&& aOtherTTree);
	// Problem 4: TTree Postfix Iterator
	// return TTree iterator positioned at start
	Iterator begin() const;
	// return TTree iterator positioned at end
	Iterator end() const;
};
template<typename T>
TTree<T> TTree<T>::NIL;
// ------------------------------------------------------------------------------// 
template<typename T>
const TTree<T>& TTree<T>::removeSubTree(TTree<T>** aBranch) {
	if ((*aBranch)->empty()) {
		throw std::domain_error("Remove empty subtree");
	}
	auto& removedSubTree(**aBranch);
	*aBranch = &NIL;
	return removedSubTree;
}
template<typename T>
TTree<T>::TTree(const T& aKey) : fKey(aKey), fLeft(&NIL), fMiddle(&NIL),
fRight(&NIL) {
}
template<typename T>
TTree<T>::~TTree() {
	if (!fLeft->empty()) {
		delete fLeft;
	}
	if (!fMiddle->empty()) {
		delete fMiddle;
		fMiddle = &NIL;
	}
	if (!fRight->empty()) {
		delete fRight;
		fRight = &NIL;
	}
}
template<typename T>
const T& TTree<T>::operator*() const {
	if (empty()) {
		throw std::domain_error("Empty TTree encountered. ");
	}
	return fKey;
}
template<typename T>
bool TTree<T>::empty() const {
	return this == &NIL;
}
template<typename T>
bool TTree<T>::leaf() const {
	return fLeft->empty() && fMiddle->empty() && fRight->empty();
}
template<typename T>
TTree<T>::TTree(const TTree& aOtherTTree) :fLeft(&NIL), fMiddle(&NIL),
fRight(&NIL) {
	if (aOtherTTree.empty()) {
		throw std::domain_error("COPYING NIL");
	}
	fKey = aOtherTTree.fKey;
	if (!aOtherTTree.fLeft->empty()) {
		fLeft = new TTree(*aOtherTTree.fLeft);
	}
	if (!aOtherTTree.fMiddle->empty()) {
		fMiddle = new TTree(*aOtherTTree.fMiddle);
	}
	if (!aOtherTTree.fRight->empty()) {
		fRight = new TTree(*aOtherTTree.fRight);
	}
}
template <typename T>
TTree<T>& TTree<T>::operator=(const TTree& aOtherTTree) {
	TTree copy(aOtherTTree);
	std::swap(fKey, copy.fKey);
	std::swap(fLeft, copy.fLeft);
	std::swap(fMiddle, copy.fMiddle);
	std::swap(fRight, copy.fRight);
	return *this;
}
template <typename T>
TTree<T>* TTree<T>::clone() const
{
	if (!empty()) {
		return new TTree(*this);
	}
	else {
		return &NIL;
	}
}
template <typename T>
TTree<T>::TTree(T&& aKey) :fKey(std::move(aKey)), fLeft(&NIL), fMiddle(&NIL),
fRight(&NIL) {
}
template <typename T>
TTree<T>::TTree(TTree&& aOtherTTree) : fLeft(aOtherTTree.fLeft),
fMiddle(aOtherTTree.fMiddle), fRight(aOtherTTree.fRight) {
	if (aOtherTTree.empty()) {
		throw std::domain_error("MOVING NIL.");
	}
	fKey = std::move(aOtherTTree.fKey);
	aOtherTTree.fLeft = &NIL;
	aOtherTTree.fMiddle = &NIL;
	aOtherTTree.fRight = &NIL;
}
template <typename T>
TTree<T>& TTree<T>::operator=(TTree&& aOtherTTree) {
	if (aOtherTTree.empty()) {
		throw std::domain_error("MOVING NIL.");
	}
	if (this != &aOtherTTree) {
		fKey = std::move(aOtherTTree.fKey);
		fLeft = aOtherTTree.fLeft;
		fMiddle = aOtherTTree.fMiddle;
		fRight = aOtherTTree.fRight;
		aOtherTTree.fLeft = &NIL;
		aOtherTTree.fMiddle = &NIL;
		aOtherTTree.fRight = &NIL;
	}
	return *this;
}