modded class ItemBase
{
	private static ref array<ItemBase> m_AllItems = new array<ItemBase>();

	void ItemBase()
	{
		if (IsMissionClient())
			m_AllItems.Insert(this);
	}

	void ~ItemBase()
	{
		if (IsMissionClient())
			m_AllItems.RemoveItem(this);
	}

	static array<ItemBase> GetAll()
	{
		return m_AllItems;
	}
}