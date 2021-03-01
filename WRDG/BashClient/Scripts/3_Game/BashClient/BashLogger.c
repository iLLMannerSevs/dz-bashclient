enum BashLogType
{
	NONE,
	INFO,
	DEBUG,
	WARN,
	ERROR
}

class BashLog
{
	static void Info(string s)
	{
		Print("[BASH][INFO] " + s);
		BashLogger.Log(BashLogType.INFO, s);
	}

	static void Debug(string s)
	{
		Print("[BASH][DEBUG] " + s);
		BashLogger.Log(BashLogType.DEBUG, s);
	}

	static void Warn(string s)
	{
		Print("[BASH][WARN] " + s);
		BashLogger.Log(BashLogType.WARN, s);
	}

	static void Error(string s)
	{
		Print("[BASH][ERROR] " + s);
		BashLogger.Log(BashLogType.ERROR, s);
	}
}

// needs refactor to include logger level
class BashLogger
{
	private static FileHandle _Logger;

	static void Log(BashLogType logType, string message)
	{
		MakeDirectory(BASH_ROOT_DIR);
		MakeDirectory(BASH_LOGS_DIR);

		_Logger = OpenFile(GetCurrentLogFile(), FileMode.APPEND);
		message = string.Format("[%1][%2] %3", GetTime(), typename.EnumToString(BashLogType, logType), message);

		FPrintln(_Logger, message);
		CloseFile(_Logger);
	}

	private static string GetTime(string format = "%1:%2:%3")
	{
		int hour, minute, second;
		GetHourMinuteSecond(hour, minute, second);

		return string.Format(format, hour.ToStringLen(2), minute.ToStringLen(2), second.ToStringLen(2));
	}

	private static string GetDate(string format = "%1.%2.%3")
	{
		int year, month, day;
		GetYearMonthDay(year, month, day);

		return string.Format(format, year.ToStringLen(2), month.ToStringLen(2), day.ToStringLen(2));
	}

	private static string GetCurrentLogFile()
	{
		return string.Format("%1%2.log", BASH_LOGS_DIR, GetDate());
	}
}