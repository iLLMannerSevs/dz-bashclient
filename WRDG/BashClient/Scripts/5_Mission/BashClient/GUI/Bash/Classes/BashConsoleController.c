class BashConsoleController : Controller
{
	ref ObservableCollection<ref BashTextEntryView> LogEntries = new ObservableCollection<ref BashTextEntryView>(this);
}