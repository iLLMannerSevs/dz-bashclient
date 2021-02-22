class BashTextEntryView : ScriptViewTemplate<BashTextEntryController>
{
	void BashTextEntryView(string message)
	{
		GetTemplateController().EntryText = message;
		GetTemplateController().NotifyPropertyChanged("EntryText");
	}

	override string GetLayoutFile()
	{
		return "WRDG/BashClient/GUI/Layouts/text_entry.layout";
	}
}