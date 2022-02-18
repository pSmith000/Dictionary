#pragma once

template<typename TKey, typename TValue>
class Dictionary
{
public:
	/// <summary>
	/// Sets the dictionary to have base items and values
	/// </summary>
	Dictionary<TKey, TValue>();

	/// <summary>
	/// Sets the dictionary equal to a different dictionary
	/// </summary>
	/// <param name="other">the other dictionary to set this one equal to</param>
	Dictionary<TKey, TValue>(const Dictionary<TKey, TValue>& other);

	/// <summary>
	/// The deconstructor for the dictionary
	/// </summary>
	~Dictionary<TKey, TValue>();

	/// <summary>
	/// Deletes all items in dictionary
	/// </summary>
	void clear();

	/// <summary>
	/// Checks to see if an item that has the given key is in the dictionary
	/// </summary>
	/// <param name="object">the key to check for</param>
	/// <returns>true if the item contains the key</returns>
	bool containsKey(const TKey object) const;

	/// <summary>
	/// Checks to see if an item that has the given value is in the dictionary
	/// </summary>
	/// <param name="object">the value to check for</param>
	/// <returns>true if the item contains the value</returns>
	bool containsValue(const TValue object) const;

	/// <summary>
	/// tries to find the item that matches the given key and changes the value to be the value inputed
	/// </summary>
	/// <param name="key">the key to check for</param>
	/// <param name="value">the value is chenged to the value asociated with the item</param>
	/// <returns>true if the key is found</returns>
	bool tryGetValue(const TKey key, TValue& value) const;

	/// <summary>
	/// creates a new item with the given key and value and adds it to the dictionary
	/// </summary>
	/// <param name="key">the key of the new item</param>
	/// <param name="value">the value of the new item</param>
	void addItem(const TKey key, const TValue& value);

	/// <summary>
	/// removes the item that has the given key
	/// </summary>
	/// <param name="key">the key to search for the item to delete</param>
	/// <returns>true if the item is deleted</returns>
	bool remove(const TKey key);

	/// <summary>
	/// removes the item that has the given key and gives back the value of the item that was removed
	/// </summary>
	/// <param name="key">the key to search for the item to delete</param>
	/// <param name="value">the value of the item that was removed</param>
	/// <returns>true if the item was deleted</returns>
	bool remove(const TKey key, TValue& value);

	/// <summary>
	/// gets the number of items in the dictionary
	/// </summary>
	/// <returns>the count of items in the dictionary</returns>
	int getCount() const;

	/// <summary>
	/// The overload of the equals operator to set one dictionary equal to another
	/// </summary>
	/// <param name="other">the other dictionary to set this one equal to</param>
	/// <returns>the dictionary that was set equal to the other</returns>
	const Dictionary<TKey, TValue>& operator =(const Dictionary<TKey, TValue> other);

	/// <summary>
	/// The overload of the bracket operator
	/// </summary>
	/// <param name="key">the key to search for</param>
	/// <returns>the value connected to the key</returns>
	TValue operator [](const TKey key);

private:
	/// <summary>
	/// A struct for the items in the dictionary
	/// </summary>
	struct Item
	{
		TKey itemKey;
		TValue itemValue;
	};
	//The items and the count of the items in the dictionary
	Item* m_items = nullptr;
	int m_count = 0;
};

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary()
{
	//Sets the variables to their bases
	m_items = nullptr;
	m_count = 0;
}

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary(const Dictionary<TKey, TValue>& other)
{
	//sets the variables to be that of the other dictionary
	m_items = other.m_items;
	m_count = other.m_count;
}

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::~Dictionary(){}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::clear()
{
	//Deletes the items to clear the dictionary
	delete m_items;
	m_count = 0;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsKey(const TKey object) const
{
	//for the length of the items
	for (int i = 0; i < getCount(); i++)
	{
		//if the items key is equal to the object
		if (m_items[i].itemKey == object)
			//return true
			return true;
	}
	//if the key wasn't foun return false
	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsValue(const TValue object) const
{
	//For the lenght of the items
	for (int i = 0; i < getCount(); i++)
	{
		//If the items value is equal to the object
		if (m_items[i].itemValue == object)
			//return true
			return true;
	}
	//if the value wasn't found return false
	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::tryGetValue(const TKey key, TValue& value) const
{
	//For the lenght of the items
	for (int i = 0; i < getCount(); i++)
	{
		//if the items key is equal to the key
		if (m_items[i].itemKey == key)
		{
			//set the value to the item value and return true
			value = m_items[i].itemValue;
			return true;
		}
	}
	//if the key wasn't found return false
	return false;
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::addItem(const TKey key, const TValue& value)
{
	//If the key is already in the dictionary
	if (containsKey(key))
		//return without adding an item
		return;
	//Create a temporary array with length og one more than the current array
	Item* tempArray = new Item[getCount() + 1];

	//Copy all the value from the array into the new array
	for (int i = 0; i < getCount(); i++)
	{
		tempArray[i].itemKey = m_items[i].itemKey;
		tempArray[i].itemValue = m_items[i].itemValue;
	}

	//Set the last item of the array to the key and value of the item trying to be added
	tempArray[getCount()].itemKey = key;
	tempArray[getCount()].itemValue = value;

	//delete the current list and set it equal to the new list
	delete[] m_items;
	m_items = tempArray;
	//Increase the count
	m_count++;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key)
{
	//If the key isn't in the dictionary
	if (!containsKey(key))
		//return without removing anything
		return false;

	//Create a new item pointer that is one smaller than the current pointer
	Item* tempArray = new Item[getCount() - 1];

	//For the length of the new array
	for (int i = 0; i < getCount() - 1; i++)
	{
		//if the key isn't the one to remove
		if (m_items[i].itemKey != key)
		{
			//copy the values to the new array
			tempArray[i] = m_items[i];
		}
	}

	//delete the current list and set it equal to the new list
	delete m_items;
	m_items = tempArray;
	//Decrease the count
	m_count--;
	return true;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key, TValue& value)
{
	//If the key isn't in the dictionary
	if (!containsKey(key))
		//return without removing anything
		return false;

	//Create a new item pointer that is one smaller than the current pointer
	Item* tempArray = new Item[getCount() - 1];

	//For the length of the new array
	for (int i = 0; i < getCount() - 1; i++)
	{
		//if the key isn't the one to remove
		if (m_items[i].itemKey != key)
		{
			//copy the values to the new array
			tempArray[i] = m_items[i];
		}
		//if not set the value equal to the value of the item being removed
		else
			value = m_items[i].itemValue;
	}

	//delete the current list and set it equal to the new list
	delete m_items;
	m_items = tempArray;
	//Decrease the count
	m_count--;
	return true;
}

template<typename TKey, typename TValue>
inline int Dictionary<TKey, TValue>::getCount() const
{
	//returns the number of items
	return m_count;
}

template<typename TKey, typename TValue>
inline const Dictionary<TKey, TValue>& Dictionary<TKey, TValue>::operator=(const Dictionary<TKey, TValue> other)
{
	//clears the dictionary
	clear();

	//for the lengtth of the other dictionarys items
	for (int i = 0; i < other.getCount(); i++)
	{
		//copy the items from the other dictionary to the current one
		addItem(other.m_items[i].itemKey, other.m_items[i].itemValue);
	}
	//set the count to the other count
	m_count = other.getCount();

	//return the current dictionary
	return *this;
}

template<typename TKey, typename TValue>
inline TValue Dictionary<TKey, TValue>::operator[](const TKey key)
{
	//For the length of the dictionary
	for (int i = 0; i < getCount(); i++)
	{
		//If the key is found
		if (m_items[i].itemKey == key)
		{
			//return the value associated with it
			return m_items[i].itemValue;
		}
	}
	//Else, return the default value
	return TValue();
}
