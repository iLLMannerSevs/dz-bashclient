class CfgPatches
{
	class BashClient_Scripts
	{
		requiredAddons[] = {"JM_CF_Scripts"};
	};
};

class CfgMods
{
	class BashClient
	{
		type = "mod";
		author = "Wardog";
		dir = "WRDG/BashClient";
		name = "Bash Client - Client Side Dev Environment";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				files[] = {"WRDG/BashClient/Scripts/3_Game"};
			};
			class worldScriptModule
			{
				files[] = {"WRDG/BashClient/Scripts/4_World"};
			};
			class missionScriptModule
			{
				files[] = {"WRDG/BashClient/Scripts/5_Mission"};
			};
		};
	};
};