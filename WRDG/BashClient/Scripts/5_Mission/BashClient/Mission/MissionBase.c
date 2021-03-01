modded class MissionBase
{
	void MissionBase()
	{
		if (IsServer() && GetGame().IsMultiplayer())
		{
			//BashErrorPrint(string.Format("Unable to run %1 v%2.%3 in server environment... Requesting game exit!", BASH_CLIENT_NAME, BASH_CLIENT_MAJOR_VER, BASH_CLIENT_MINOR_VER));
			//GetGame().RequestExit(0);
		}
	}

	override UIScriptedMenu CreateScriptedMenu(int id)
	{
		UIScriptedMenu menu = super.CreateScriptedMenu(id);

		switch (id)
		{
			case MENU_BASH:
			{
				menu = new BashMenu();
				break;
			}
		}

		return menu;
	}

	override void OnEvent(EventType eventTypeId, Param params)
	{
		super.OnEvent(eventTypeId, params);

		switch (eventTypeId)
		{
			case ScriptLogEventTypeID:
			{
				Param1<string> log_params = Param1<string>.Cast(params);
				GetModuleManager().OnScriptLog(log_params.param1);
			}
		}
	}
}