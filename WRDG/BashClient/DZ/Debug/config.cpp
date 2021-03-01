class CfgPatches
{
	class BashClient_DZ_Debug
	{
		requiredAddons[] = {};
	};
};

class CfgVehicles
{
	class HouseNoDestruct;
	class BashShape_Cube : HouseNoDestruct
	{
		scope = 1;
		model = "BashClient\DZ\Debug\Shapes\cube.p3d";
	};
	class BashShape_Line : HouseNoDestruct
	{
		scope = 1;
		model = "BashClient\DZ\Debug\Shapes\line.p3d";
	};
	class BashShape_Sphere : HouseNoDestruct
	{
		scope = 1;
		model = "BashClient\DZ\Debug\Shapes\sphere.p3d";
	};
};