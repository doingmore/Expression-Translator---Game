#ifndef storetail_H
#define storetail_H

template <typename T>
class tail
{
private:
	T m_array[10];
public:
	const bool find(const int& number)
	{
		for (int i = 0; i < 10; i++)
		{
			if (m_array[i] == number)
			{
				return true;
			}
		}
		return false;
	}

	void relocated()
	{
		for (int i = 9; i > 0; i--)
		{
			m_array[i] = m_array[i - 1];
		}
	}

	void push_front(const int& number)
	{
		relocated();
		m_array[0] = number;
	}

	T& operator[](int index)
	{
		return m_array[index];
	}
};

#endif // !storetail_H