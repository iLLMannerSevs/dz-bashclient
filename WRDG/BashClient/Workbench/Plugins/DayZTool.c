modded class DayZTool
{
	private const string WORKBENCH_TOOLS_DIR = "P:\\WRDG\\BashClient\\Workbench\\Tools\\";
	private const string WORKFLOW_TOOL = "DZWorkFlow.exe";

	void RunWorkflow(string params, bool wait = false)
	{
		string filepath = WORKBENCH_TOOLS_DIR;

		if (filepath.Length() < 2)
			return;

		filepath.Replace("\\", "/");

		if (filepath[1] != ":")
			return;

		int index = filepath.IndexOf("/");
		int last_index = index;

		while (index != -1)
		{
			last_index = index;
			index = filepath.IndexOfFrom(last_index + 1, "/");
		}

		if (last_index == -1)
			return;

		string path = filepath.Substring(0, last_index);

		Workbench.RunCmd("cmd /c \"cd " + path + " & call " + WORKFLOW_TOOL + " " + params + "\"", wait);
	}

	override void RunDayZBat(string filepath, bool wait = false)
	{
		if (filepath.Length() < 2) return;

		filepath.Replace("\\", "/");

		if (filepath[1] != ":")
		{
			string cwd;
			Workbench.GetCwd(cwd);
			filepath = cwd + "/" + filepath;
		}

		int index = filepath.IndexOf("/");
		int last_index = index;

		while(index != -1)
		{
			last_index = index;
			index = filepath.IndexOfFrom(last_index + 1, "/");
		}

		if (last_index == -1) return;

		string path = filepath.Substring(0, last_index);
		string bat = filepath.Substring(last_index + 1, filepath.Length() - last_index - 1);

		Workbench.RunCmd("cmd /c \"chdir /D " + path + " & call " + bat + "\"", wait);
	}

	void RunDayZBatList(array<string> filepaths)
	{
		foreach (string file: filepaths) {
			RunDayZBat(file, true);
		}
	}
}