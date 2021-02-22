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
			Print("The game should now attempt to run: " + GetTemplateController().ConsoleInput);

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
		GetGame().ExecuteEnforceScript("void bashMain() \n{\n" + console_code + "\n}\n", "bashMain");
	}

	void ExecuteConsoleInput_Ex()
	{
		FileHandle file;

		MakeDirectory("$profile:BashClient/");
		string script_path = "$profile:BashClient/script.c";
		file = OpenFile(script_path, FileMode.WRITE);

		string console_code = GetTemplateController().ConsoleInput;

		if (file)
		{
			string ex_script = "class BashScript\n{\n";
			ex_script += 		"void Main()\n{\n";
			ex_script += 		console_code + "\n}\n}\n";

			ex_script += 		"ref BashScript s_BashScript;\n";
			ex_script += 		"BashScript GetInstance()\n{\n";
			ex_script += 		"if (!s_BashScript)\n{\n";
			ex_script += 		"s_BashScript = new BashScript();\n}\n";
			ex_script += 		"return s_BashScript;\n}\n";

			FPrintln(file, ex_script);

			CloseFile(file);
		}

		ScriptModule bash_module = ScriptModule.LoadScript(GetGame().GameScript, script_path, true);

		if (bash_module)
		{
			Class instance;

			bash_module.CallFunction(null, "GetInstance", instance, null);

			if (instance)
				bash_module.CallFunction(instance, "Main", null, null);
		}
	}

	override string GetLayoutFile()
	{
		return "WRDG/BashClient/GUI/Layouts/Console/console_new.layout";
	}
}