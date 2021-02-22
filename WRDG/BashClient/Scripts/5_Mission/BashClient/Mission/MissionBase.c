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
}