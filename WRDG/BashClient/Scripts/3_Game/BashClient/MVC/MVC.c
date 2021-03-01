modded class MultilineEditBoxWidgetController
{
	// Missed a spot
	override void Insert(TypeConverter typeConverter)
	{
		m_Widget.SetLine(m_Widget.GetLinesCount(), typeConverter.GetString());
	}
}