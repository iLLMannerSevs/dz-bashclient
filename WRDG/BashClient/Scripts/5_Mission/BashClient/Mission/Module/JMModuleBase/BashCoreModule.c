class BashCoreModule : JMModuleBase
{
	protected ref BashHudView m_HudView;

	override void OnInit()
	{
		super.OnInit();

		MakeDirectory("$profile:BashClient/");
	}

	override void OnMissionStart()
	{
		super.OnMissionStart();


	}

	override void OnMissionFinish()
	{
		super.OnMissionFinish();

		if (m_HudView)
			delete m_HudView;
	}

	override void OnMissionLoaded()
	{
		super.OnMissionLoaded();

		if (!m_HudView)
			m_HudView = new BashHudView();
	}

	override void OnScriptLog(string message)
	{
		super.OnScriptLog(message);

		if (!m_HudView)
			return;
	}

	override bool IsServer()
	{
		return false;
	}
}