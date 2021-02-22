class BashConsoleModule : JMModuleBase
{
	protected ref BashConsoleView m_ConsoleView;

	override void OnInit()
	{
		super.OnInit();


	}

	override void OnMissionStart()
	{
		super.OnMissionStart();


	}

	override void OnMissionFinish()
	{
		super.OnMissionFinish();

		if (m_ConsoleView)
			delete m_ConsoleView;
	}

	override void OnMissionLoaded()
	{
		super.OnMissionLoaded();


	}

	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);

		Input input = GetGame().GetInput();
		if (input.LocalRelease("UAUIQuickbarToggle",false))
		{
			if (m_ConsoleView)
				delete m_ConsoleView;
			else
				m_ConsoleView = new BashConsoleView();
		}
	}

	override void OnScriptLog(string message)
	{
		super.OnScriptLog(message);

		if (!m_ConsoleView)
			return;

		if (m_ConsoleView)
			m_ConsoleView.GetTemplateController().LogEntries.Insert(new BashTextEntryView(message));
	}

	override bool IsServer()
	{
		return false;
	}
}