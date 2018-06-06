#pragma once

#include "Element.h"


template <class TKey, class TValue>
class Map {

private:

	int size;

	int count = 0;

public:

	Element<TKey, TValue> *array;

	Map(int);

	~Map();

	void Put(TKey, TValue);

	TValue* Get(int&);

	void Remove(TValue);

	int Count();

	void GetALL(TValue*&);

	void Sort_descen();

	void Sort_ascen();

	void Sort_spec_ascen();

	void Sort_spec_descen();

};


template <class TKey, class TValue>
Map<TKey, TValue>::Map(int  k) {

	size = k;

	array = new Element<TKey, TValue>[size];

}



template <class TKey, class TValue>
Map<TKey, TValue>::~Map() {

	delete[] array;

}

template <class TKey, class TValue>
void Map<TKey, TValue>::Put(TKey key, TValue value) {

	if (count == size) {

		Element<TKey, TValue> *tmp = array;

		size *= 2;

		array = new Element<TKey, TValue>[size];

		memcpy(array, tmp, sizeof(Element<TKey, TValue>) * count);

		delete[] tmp;

	}

	array[count].key = key;

	array[count].value = value;

	count++;

}
template <class TKey, class TValue>
TValue* Map<TKey, TValue>::Get(int& _num) {

	for (int i = 0; i < count; i++) 
	{
		if (i == _num)
		{
			TValue *tmp = new TValue[1];
			tmp[0] = array[i].value;
			TValue *Arr = new TValue[1];
			Arr[0] = tmp[0];

			return Arr;
		}
	}

	return NULL;

}

template <class TKey, class TValue>
void Map<TKey, TValue>::Remove(TValue value) {

	for (int i = 0; i < count; i++) {

		if (value == array[i].value) {

			array[i] = array[count - 1];

			count--;

		}

	}

}


template <class TKey, class TValue>
int Map<TKey, TValue>::Count() {

	return count;
}

template <class TKey, class TValue>
void Map<TKey, TValue>::GetALL(TValue*& newArr) {

	newArr = new TValue[count];

	TValue *tmp = new TValue[count];

	for (int i = 0; i < count; i++) {

		tmp[i] = array[i].value;

		newArr[i] = tmp[i];

	}

}
