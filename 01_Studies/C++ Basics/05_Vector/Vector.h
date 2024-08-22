#pragma once

// int
class Vector
{
public:
	Vector()
		: _size(0)
		, _capacity(0)
	{
	}

	~Vector()
	{
		delete[] _data;
	}

	void Reserve(int capacity)
	{
		if (capacity > _capacity)
		{
			int* new_data = new int[capacity];
			if (_size != 0)
			{
				for (int i = 0; i < _size; i++)
				{
					new_data[i] = _data[i];
				}
			}
			delete[] _data;
			_data = new_data;
			_capacity = capacity;
		}
	}

	void PushBack(int value)
	{
		if (_size == _capacity)
		{
			int* new_data = new int[_capacity * 2];
			if (_size != 0)
			{
				for (int i = 0; i < _size; i++)
				{
					new_data[i] = _data[i];
				}
			}
			delete[] _data;
			_data = new_data;
			_capacity *= 2;
		}
		_data[_size++] = value;
	}

	void PopBack()
	{
		if (_size > 0)
		{
			_data[_size] = NULL;
			_size--;
		}
	}

	void Clear()
	{
		if (_size > 0)
		{
			for (int i = 0; i < _size; i++)
			{
				_data[_size] = NULL;
				_size--;
			}
			_size = 0;
		}
	}

	const int& Size()
	{
		return _size;
	}

	const int& Capacity()
	{
		return _capacity;
	}

	int operator[](int index)
	{
		if (index >= _size)
		{
			return 0;
		}

		return _data[index];
	}

private:
	int _size = 0;
	int _capacity = 0;

	// 시작하는 애 주소
	int* _data = nullptr;
};

