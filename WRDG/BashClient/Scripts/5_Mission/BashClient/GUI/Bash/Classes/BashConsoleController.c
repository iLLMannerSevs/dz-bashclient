class BashConsoleController : Controller
{
	string ConsoleInput;

	ref ObservableCollection<ref BashTextEntryView> LogEntries = new ObservableCollection<ref BashTextEntryView>(this);
}