		workspace "Lingod"   		
			architecture "x64"  

			configurations         
			{
				"Debug",
				"Release",
				"Dist"
			}

			startproject "Sandbox"

			outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" 
			IncludeDir = {}
			IncludeDir["GLFW"] = "Lingod/vendor/GLFW/include"
			IncludeDir["glad"] = "Lingod/vendor/glad/include"
			IncludeDir["imGUI"] = "Lingod/vendor/imGUI"
			IncludeDir["glm"] = "Lingod/vendor/glm"

			group "Dependencies"
				include "Lingod/vendor/GLFW"
				include "Lingod/vendor/glad"
				include "Lingod/vendor/imGUI"
			group ""

		

		project "Lingod"          
			location "Lingod"     
			kind "StaticLib" 
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
				"%{prj.name}/src/**.cpp",
				"%{prj.name}/vendor/glm/glm/**.hpp",
				"%{prj.name}/vendor/glm/glm/**.inl",
			}

			defines
			{
				"_CRT_SECURE_NO_WARNINGS"
			}
			includedirs       
			{
				"%{prj.name}/vendor/spdlog/include",
				"%{prj.name}/src",
				"%{IncludeDir.GLFW}",
				"%{IncludeDir.glad}",
				"%{IncludeDir.imGUI}",
				"%{IncludeDir.glm}"
			}


			links
			{
				"GLFW",
				"glad",
				"imGUI",
				"opengl32.lib"
			}



			filter "system:windows"   
				systemversion "latest"  

				defines               
				{
					"LG_PLAYFORM_WINDOWS",
					"LG_BUILD_DLL",
					"GLFW_INCLUDE_NONE"
				}
				
				filter "configurations:Debug" 
					defines "LG_DEBUG"
					runtime "Debug"
					symbols "on"     

				filter "configurations:Release"
					defines "LG_RELEASE"
					runtime "Release"
					optimize "on"   

				filter "configurations:Dist"
					defines "LG_DIST"
					runtime "Release"
					optimize "on"


project "Sandbox"         
			location "Sandbox"     
			kind "ConsoleApp"	  
			language "C++"		
			cppdialect "C++17"
			staticruntime "on"

			targetdir ("bin/" .. outputdir .. "/%{prj.name}")      
			objdir ("bin-int/" .. outputdir .. "/%{prj.name}")		

			files                
			{
				"%{prj.name}/src/**.h",
				"%{prj.name}/src/**.cpp",

			}

			includedirs        
			{
				"Lingod/src",
			    "Lingod/vendor/spdlog/include",
				"Lingod/vendor",
				"%{IncludeDir.glm}"
			}

			links
			{
				"Lingod"
			}
			filter "system:windows"   
				systemversion"latest"  

				defines              
				{
					"LG_PLAYFORM_WINDOWS",
				}
				
				filter "configurations:Debug" 
					defines "LG_DEBUG"
					runtime "Debug"
					symbols "on"       

				filter "configurations:Release"
					defines "LG_RELEASE"
					runtime "Release"
					optimize "on"   

				filter "configurations:Dist"
					defines "LG_DIST"
					runtime "Release"
					optimize "on"