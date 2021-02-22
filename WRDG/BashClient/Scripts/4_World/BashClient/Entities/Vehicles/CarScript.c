modded class CarScript
{
	private static ref array<CarScript> m_AllVehicles = new array<CarScript>();

	void CarScript()
	{
		if (IsMissionClient())
			m_AllVehicles.Insert(this);
	}

	void ~CarScript()
	{
		if (IsMissionClient())
			m_AllVehicles.RemoveItem(this);
	}

	static array<CarScript> GetAll()
	{
		return m_AllVehicles;
	}
}