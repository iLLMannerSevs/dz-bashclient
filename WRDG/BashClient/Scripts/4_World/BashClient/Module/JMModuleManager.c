modded class JMModuleManager
{
	void OnScriptLog(string message)
	{
		for (int i = 0; i < m_ModuleList.Count(); i++)
		{
			if (m_ModuleList[i].IsEnabled())
			{
				m_ModuleList[i].OnScriptLog(message);
			}
		}
	}
}