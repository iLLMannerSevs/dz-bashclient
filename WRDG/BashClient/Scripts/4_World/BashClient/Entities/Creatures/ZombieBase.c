modded class ZombieBase
{
	private static ref array<ZombieBase> m_AllZombies = new array<ZombieBase>();

	void ZombieBase()
	{
		if (IsMissionClient())
			m_AllZombies.Insert(this);
	}

	void ~ZombieBase()
	{
		if (IsMissionClient())
			m_AllZombies.RemoveItem(this);
	}

	static array<ZombieBase> GetAll()
	{
		return m_AllZombies;
	}
}