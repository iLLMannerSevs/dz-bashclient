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

		m_ConsoleView = new BashConsoleView();
		m_ConsoleView.GetLayoutRoot().Show(false);
	}

	override void OnMissionFinish()
	{
		super.OnMissionFinish();

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
			{
				m_ConsoleView.GetLayoutRoot().Show(!m_ConsoleView.GetLayoutRoot().IsVisible());
			}
		}
	}

	override void OnScriptLog(string message)
	{
		super.OnScriptLog(message);

		if (!m_ConsoleView)
			return;

		if (m_ConsoleView && m_ConsoleView.GetTemplateController().LogEntries) 
		{
			m_ConsoleView.AddReadoutLine(message);
		}
			
	}

	override bool IsServer()
	{
		return false;
	}
}