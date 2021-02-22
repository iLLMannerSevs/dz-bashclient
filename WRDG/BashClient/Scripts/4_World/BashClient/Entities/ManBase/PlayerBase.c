modded class PlayerBase
{
	private static ref array<PlayerBase> m_AllPlayers = new array<PlayerBase>();

	void PlayerBase()
	{
		if (IsMissionClient())
			m_AllPlayers.Insert(this);
	}

	void ~PlayerBase()
	{
		if (IsMissionClient())
			m_AllPlayers.RemoveItem(this);
	}

	static array<PlayerBase> GetAll()
	{
		return m_AllPlayers;
	}
}