class BashConsoleModule : JMModuleBase
{
	protected ref BashConsoleMenuView m_ConsoleView;

	override void OnInit()
	{
		super.OnInit();


	}

	override void OnMissionStart()
	{
		super.OnMissionStart();

		m_ConsoleView = new BashConsoleMenuView();
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
		if (input.LocalRelease("UAUIQuickbarToggle", false))
		{
			if (GetConsoleView())
			{
				bool visible = GetConsoleView().IsVisible();
				GetConsoleView().Show(!visible);
			}
		}
		
		if (input.LocalRelease("UAUIBack", false))
		{
			if (GetConsoleView())
			{
				GetConsoleView().Show(false);
			}
		}
	}

	override void OnScriptLog(string message)
	{
		super.OnScriptLog(message);

		if (GetConsoleView())
			GetConsoleView().AddReadoutLine(message);
	}

	BashConsoleMenuView GetConsoleView()
	{
		if (!m_ConsoleView)
			m_ConsoleView = new BashConsoleMenuView();

		return m_ConsoleView;
	}

	override bool IsServer()
	{
		return false;
	}
}