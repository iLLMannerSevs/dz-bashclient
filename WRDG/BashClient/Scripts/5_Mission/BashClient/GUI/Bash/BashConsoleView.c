class BashConsoleView : ScriptViewTemplate<BashConsoleController>
{
	static const int MAX_LINE_COUNT = 100;

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

	override string GetLayoutFile()
	{
		return "WRDG/BashClient/GUI/Layouts/Console/console_new.layout";
	}
}