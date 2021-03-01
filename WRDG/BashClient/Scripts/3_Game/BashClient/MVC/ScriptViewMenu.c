class ScriptViewMenu : ScriptView
{
	void Show(bool state)
	{
		if (!m_LayoutRoot)
			return;

		// imagine if we could just do `state ? OnShow() : OnHide();`
		if (state)
			OnShow();
		else
			OnHide();

		m_LayoutRoot.Show(state);
	}

	bool IsVisible()
	{
		if (!m_LayoutRoot)
			return false;

		return m_LayoutRoot.IsVisible();
	}

	void OnShow()
	{
		GetGame().GetUIManager().ShowCursor(true);
		GetGame().GetUIManager().EnterScriptedMenu(MENU_BASH, GetGame().GetUIManager().GetMenu());
		GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
	}

	void OnHide()
	{
		GetGame().GetUIManager().ShowCursor(false);
		GetGame().GetUIManager().CloseMenu(MENU_INGAME);
		GetGame().GetMission().PlayerControlEnable(true);
	}
}