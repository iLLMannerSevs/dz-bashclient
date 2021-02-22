class BashESPModule : JMModuleBase
{
	protected ref array<EntityAI> m_FilteredEntities;

	override void OnInit()
	{
		super.OnInit();

		m_FilteredEntities = {};
	}

	override bool IsServer()
	{
		return false;
	}
}