		workspace "Lingod"   		
			architecture "x64"  

			configurations         
			{
				"Debug",
				"Release",
				"Dist"
			}
		
			outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" 
			IncludeDir = {}
			IncludeDir["GLFW"] = "Lingod/vendor/GLFW/include"

			include "Lingod/vendor/GLFW"


		project "Lingod"          
			location "Lingod"     
			kind "SharedLib" 
			language "C++"		
			cppdialect "C++17"
			staticruntime "on"

			targetdir ("bin/" .. outputdir .. "/%{prj.name}")      
			objdir ("bin-int/" .. outputdir .. "/%{prj.name}")	

			pchheader "lgpch.h"
			pchsource "Lingod/src/lgpch.cpp"

			files               
			{
				"%{prj.name}/src/**.h",
				"%{prj.name}/src/**.cpp"

			}

			includedirs       
			{
				"%{prj.name}/vendor/spdlog/include",
				"%{prj.name}/src",
				"%{IncludeDir.GLFW}"
			}


			links
			{
				"GLFW",
				"opengl32.lib"
			}



			filter "system:windows"   
				cppdialect "C++17"    
				staticruntime "on"    
				systemversion "10.0"  

				defines               
				{
					"LG_PLAYFORM_WINDOWS",
					"LG_BUILD_DLL",
					"_WINDLL"
				}
				
				postbuildcommands     
				{
					("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
				}

				filter "configurations:Debug" 
					defines "LG_DEBUG"
					symbols "On"     

				filter "configurations:Release"
					defines "LG_RELEASE"
					optimize "On"   

				filter "configurations:Dist"
					defines "LG_DIST"
					optimize "On"


project "Sandbox"         
			location "Sandbox"     
			kind "ConsoleApp"	  
			language "C++"		
			staticruntime "on"


			targetdir ("bin/" .. outputdir .. "/%{prj.name}")      
			objdir ("bin-int/" .. outputdir .. "/%{prj.name}")		

			files                
			{
				"%{prj.name}/src/**.h",
				"%{prj.name}/src/**.cpp"
			}

			includedirs        
			{
				"Lingod/src",
			"Lingod/vendor/spdlog/include",

			}

			links
			{
				"Lingod"
			}
			filter "system:windows"   
				cppdialect "C++17"    
				staticruntime "on"    
				systemversion"10.0"  

				defines              
				{
					"LG_PLAYFORM_WINDOWS",
				}
				
				filter "configurations:Debug" 
					defines "LG_DEBUG"
					symbols "On"       

				filter "configurations:Release"
					defines "LG_RELEASE"
					optimize "On"   

				filter "configurations:Dist"
					defines "LG_DIST"
					optimize "On"