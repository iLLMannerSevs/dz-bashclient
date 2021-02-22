class BashConsoleView : ScriptViewTemplate<BashConsoleController>
{
	static const int MAX_LINE_COUNT = 100;
	protected ref Timer m_UpdateTimer = new Timer(CALL_CATEGORY_GUI);
	
	void BashConsoleView()
	{
		m_UpdateTimer.Run(0.01, this, "UpdateTimer", null, true);
	}
	
	void ~BashConsoleView()
	{
		delete m_UpdateTimer;
	}
	
	void UpdateTimer()
	{
		if (GetGame().GetInput().LocalPress("UAUISelect")) {
			Print("The game should now attempt to run " + GetTemplateController().ConsoleInput);
				
			// Reset text since we hit ENTER
			GetTemplateController().ConsoleInput = string.Empty;
			GetTemplateController().NotifyPropertyChanged("ConsoleInput");
		}
	}
	
	void AddReadoutLine(string message)
	{
		if (GetTemplateController().LogEntries)
		{
			GetTemplateController().LogEntries.Insert(message);

			// Remove line when exceeds max lines
			if (GetTemplateController().LogEntries.Count() >= MAX_LINE_COUNT)
			{
				GetTemplateController().LogEntries.Remove(0);
			}
		}
	}

	void ExecuteConsoleInput()
	{
		string console_code = GetTemplateController().ConsoleInput;

		// insert our code in custom appending method
		GetGame().ExecuteEnforceScript("void bashConsoleMain() \n{\n" + console_code + "\n}\n", "bashConsoleMain");
	}
	
	override string GetLayoutFile()
	{
		return "WRDG/BashClient/GUI/Layouts/Console/console_new.layout";
	}
}