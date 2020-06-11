#include <iostream>
#include <string>
using namespace std;
template <class T>
class Stack
{
private:
	int size;
	int topIndex;
	T* arr;
public:
	Stack()
	{
		size = 0;
		topIndex = 0;
		arr = new T[this->size];
	}
	Stack(T size)
	{
		this->size = size;
		topIndex = this->size - 1;
		arr = new T[this->size];
	}
	void Push(T num)
	{
		int* temp = new T[size + 1];

		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		temp[size] = num;
		size = size + 1;
		delete[] arr;
		arr = temp;
	}
	void Pop()
	{
		int* temp = new T[size - 1];
		int a = 0;
		for (int i = 0; i < size; i++)
		{
			if (i != size - 1)
			{
				temp[a] = arr[i];  a++;
			}
		}
		this->size = size - 1;
		this->topIndex = size;
		delete[] arr;
		arr = temp;
	}

	T Peek() const
	{
		return arr[topIndex - 1];
	}
	T GetCount() const
	{
		return topIndex;
	}
	bool IsEmpty() const
	{
		return topIndex == 0;
	}
	bool IsFull()const
	{
		return topIndex == this->size;
	}
	void Print() const
	{
		for (int i = 0; i < size; i++)
		{
			if (i + 1 == size)
			{
				cout << arr[i] << endl;
			}
			else
			{
				cout << arr[i] << ", ";
			}
		}
	}
	~Stack()
	{
		delete[] arr;
	}
};


int main()
{
	bool a = 1;
	int s = 0;
	Stack<int> st;
	st.Push(12);
	st.Push(13);
	st.Push(12);
	st.Push(11);
	st.Push(7);
	st.Push(888);
	st.Print();
	st.Pop();
	st.Print();
	s = st.Peek();
	cout << s << endl;
	s = st.GetCount();
	cout << s << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~\n|1 = true, 0 = false|\n~~~~~~~~~~~~~~~~~~~~~" << endl;
	a = st.IsEmpty();
	cout << a << endl;
	a = st.IsFull();
	cout << a << endl;

	system("pause");
	return 0;
}