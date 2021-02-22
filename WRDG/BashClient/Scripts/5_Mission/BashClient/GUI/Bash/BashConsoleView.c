class BashConsoleView : ScriptViewTemplate<BashConsoleController>
{
	override string GetLayoutFile()
	{
		return "WRDG/BashClient/GUI/Layouts/Console/console_window.layout";
	}
}