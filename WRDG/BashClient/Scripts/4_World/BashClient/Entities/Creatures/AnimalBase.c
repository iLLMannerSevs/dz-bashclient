modded class AnimalBase
{
	private static ref array<AnimalBase> m_AllAnimals = new array<AnimalBase>();

	void AnimalBase()
	{
		if (IsMissionClient())
			m_AllAnimals.Insert(this);
	}

	void ~AnimalBase()
	{
		if (IsMissionClient())
			m_AllAnimals.RemoveItem(this);
	}

	static array<AnimalBase> GetAll()
	{
		return m_AllAnimals;
	}
}