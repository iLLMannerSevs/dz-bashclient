class BashConsoleMenuView : ScriptViewMenuTemplate<BashConsoleController>
{
	protected const int MAX_LINE_COUNT = 100;
	protected ref Timer m_UpdateTimer = new Timer(CALL_CATEGORY_GUI);

	void BashConsoleMenuView()
	{
		m_UpdateTimer.Run(0.01, this, "UpdateTimer", null, true);
	}

	void ~BashConsoleMenuView()
	{
		delete m_UpdateTimer;
	}

	void UpdateTimer()
	{
		if (GetGame().GetInput().LocalPress("UAUISelect")) {
			//Print("The game should now attempt to run: " + GetTemplateController().ConsoleInput);

			ExecuteEnf_Ex(GetTemplateController().ConsoleInput);

			// Reset text since we hit ENTER
			GetTemplateController().ConsoleInput = string.Empty;
			GetTemplateController().NotifyPropertyChanged("ConsoleInput");
		}
	}

	void AddReadoutLine(string message)
	{
		if (!GetTemplateController())
			return;

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

	void ExecuteEnf(string code)
	{
		// insert our code in custom appending method
		GetGame().ExecuteEnforceScript("void bashMain() \n{\n" + code + "\n}\n", "bashMain");
	}

	void ExecuteEnf_Ex(string code)
	{
		FileHandle file;

		MakeDirectory("$profile:BashClient/");
		string script_path = "$profile:BashClient/script.c";
		file = OpenFile(script_path, FileMode.WRITE);

		if (file)
		{
			string ex_script =  "static void main()\n{\n" + code + "\n}";
			FPrintln(file, ex_script);
			CloseFile(file);
		}

		ScriptModule bash_module = ScriptModule.LoadScript(GetGame().GetMission().MissionScript, script_path, true);

		if (!bash_module)
		{
			BashLog.Error(string.Format("Invalid syntax in script console input \"%1\"", code));
			return;
		}

		bash_module.Call(null, "main", null);
	}

	override string GetLayoutFile()
	{
		return "WRDG/BashClient/GUI/Layouts/Console/console_multi.layout";
	}
}