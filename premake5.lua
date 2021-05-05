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
			kind "SharedLib" 
			language "C++"		
			cppdialect "C++17"
			staticruntime "off"

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
				cppdialect "C++17"    
				staticruntime "off"  
				systemversion "10.0"  

				defines               
				{
					"LG_PLAYFORM_WINDOWS",
					"LG_BUILD_DLL",
					"_WINDLL",
					"GLFW_INCLUDE_NONE"
				}
				
				postbuildcommands     
				{
					("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"),
					("{COPY} %{cfg.buildtarget.relpath}\" ../bin/" .. outputdir .. "/Sandbox\"")
				}

				filter "configurations:Debug" 
					defines "LG_DEBUG"
					staticruntime "off" 
					symbols "on"     

				filter "configurations:Release"
					defines "LG_RELEASE"
					staticruntime "off" 
					optimize "on"   

				filter "configurations:Dist"
					defines "LG_DIST"
					staticruntime "off" 
					optimize "on"


project "Sandbox"         
			location "Sandbox"     
			kind "ConsoleApp"	  
			language "C++"		
			staticruntime "off"


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
				"Lingod/vendor/imGUI",
				"%{IncludeDir.glm}"
			}

			links
			{
				"Lingod"
			}
			filter "system:windows"   
				cppdialect "C++17"    
				staticruntime "off"    
				systemversion"10.0"  

				defines              
				{
					"LG_PLAYFORM_WINDOWS",
				}
				
				filter "configurations:Debug" 
					defines "LG_DEBUG"
					staticruntime "off" 
					symbols "on"       

				filter "configurations:Release"
					defines "LG_RELEASE"
					staticruntime "off" 
					optimize "on"   

				filter "configurations:Dist"
					defines "LG_DIST"
					staticruntime "off" 
					optimize "on"