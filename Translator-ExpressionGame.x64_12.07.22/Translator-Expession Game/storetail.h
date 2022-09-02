#ifndef storetail_H
#define storetail_H

#define length_tail 30

template <typename T>
class tail
{
private:
	T m_array[length_tail];
	void relocated()
	{
		for (int i = length_tail - 1; i > 0; i--)
		{
			m_array[i] = m_array[i - 1];
		}
	}
public:
	bool find(const int& number) const
	{
		for (int i = 0; i < length_tail; i++)
		{
			if (m_array[i] == number)
			{
				return true;
			}
		}
		return false;
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
