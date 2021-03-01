class BashConsoleController : Controller
{
	string ConsoleInput;

	ref ObservableCollection<string> LogEntries = new ObservableCollection<string>(this);
}