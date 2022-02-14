#pragma once

template<typename TKey, typename TValue>
class Dictionary
{
	

public:
	Dictionary<TKey, TValue>();
	Dictionary<TKey, TValue>(const Dictionary<TKey, TValue>& other);
	~Dictionary<TKey, TValue>();

	void clear();
	bool containsKey(const TKey object) const;
	bool containsValue(const TValue object) const;
	bool tryGetValue(const TKey key, const TValue& value) const;
	void addItem(const TKey key, const TValue& value) const;
	bool remove(const TKey key);
	bool remove(const TKey key, TValue& value);
	int getCount() const;
	const Dictionary<TKey, TValue>& operator =(const Dictionary<TKey, TValue> other);


private:
	struct Item
	{
		TKey itemKey;
		TValue itemValue;
	};

	Item* m_items = nullptr;
	int m_count = 0;
	
};

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary()
{
	m_items = nullptr;
	m_count = 0;
}

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary(const Dictionary<TKey, TValue>& other)
{
	m_items = other.m_items;
	m_count = other.m_count;
}

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::~Dictionary()
{
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::clear()
{
	for (int i = 0; i < m_count; i++)
	{
		m_items = nullptr;

	}
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsKey(const TKey object) const
{
	for (int i = 0; i < m_count; i++)
	{
		if (m_items[i].itemKey == object)
			return true;
	}
	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsValue(const TValue object) const
{
	for (int i = 0; i < m_count; i++)
	{
		if (m_items[i].itemValue == object)
			return true;
	}
	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::tryGetValue(const TKey key, const TValue& value) const
{
	return false;
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::addItem(const TKey key, const TValue& value) const
{
	Item* newItem = new Item();
	newItem->itemKey = key;
	newItem->itemValue = value;

	m_count++;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key)
{
	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key, TValue& value)
{
	return false;
}

template<typename TKey, typename TValue>
inline int Dictionary<TKey, TValue>::getCount() const
{
	return m_count;
}

template<typename TKey, typename TValue>
inline const Dictionary<TKey, TValue>& Dictionary<TKey, TValue>::operator=(const Dictionary<TKey, TValue> other)
{
	// TODO: insert return statement here
}
