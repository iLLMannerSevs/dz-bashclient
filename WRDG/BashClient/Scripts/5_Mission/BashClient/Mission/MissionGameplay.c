modded class MissionGameplay
{
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