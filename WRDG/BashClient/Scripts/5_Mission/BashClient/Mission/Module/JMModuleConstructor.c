modded class JMModuleConstructor
{
	override void RegisterModules(out array<typename> modules)
	{
		super.RegisterModules(modules);

		modules.Insert(BashCoreModule);
		modules.Insert(BashConsoleModule);
	}
}