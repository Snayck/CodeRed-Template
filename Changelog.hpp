#pragma once
/*
    Changes in v1.4.1:
    - Added a new "GetOrCreateInstance" function in "Instances.hpp", if no instance of a class is found it will create one.
    - Improved all of the "GetInstanceOf" functions again to prevent a possible crash in "Instances.hpp".
    - Improved the "FindStaticClass" and "FindStaticFunction" functions in "Instances.cpp" to also be more safe.
    - The "MarkForDestroy" function will now also remove the object from the cached created object list if one is found.

    Changes in v1.4.0:
    - Revamped the entire project to use modern C++ standards, functions, and naming conventions.
    - Remade the console component in "Console.hpp/cpp", added macros for logging to std::cout, opening a console window, and using 24 hour or 12 hour timestamps.
    - Added new timestamp and clock utils in "Extensions/Time.hpp".
    - Added new random number and letter functions in "Math.hpp", as well as added a new "Plane" class.
    - Improved all the color classes and functions in "Colors.hpp/cpp", also added hashing and sorting operators.
    - Improved all the functions in "Formatting.hpp/cpp", as well as added inline functions and bug fixes.
    - Fixed a crash that could happen when using any of the "GetInstanceOf" functions.

    Changes in v1.3.9:
    - Added new functions for calling console commands with delays! See the "AsyncConsoleCommand" functions in "Manager.hpp/cpp".
    - Moved the "GRainbowColor::OnTick()" call to inside the "ManagerComponent::OnTick()" function in "Manager.cpp".
    - Optimized various instance functions in "Instances.hpp".
    - Optimized the color classes "FromHex" function in "Colors.cpp", also add support for parsing alpha channels.
    - Updated the "PlaceholderSDK" functions and classes.

    Changes in v1.3.8:
    - Remade and optimized a lot of the helper functions in "Formatting.hpp/cpp".

    Changes in v1.3.7:
    - Added extra radians, rotation, and degree conversion helpers in "Math.hpp".
    - Added a "FromUnrealRotator" function in the "Rotator" class in "Math.hpp/cpp", this helps auto convert unreal rotational units to degrees (0 to 360).
    - Fixed "IsStringDecimal" returning false for negative values in "Formatting.cpp".

    Changes in v1.3.6:
    - Added and improved constructors and operator overloads for the classes throughout "Manager.hpp/cpp".
    - Improved the "MarkInvincible" and "MarkForDestory" functions in "Instances.cpp".
    - Changed how variables are stored in "Manager.hpp", also variables names are now automatically set to lower case.

    Changes in v1.3.5:
    - Upgraded and improved a lot of the functions and classes in "Colors.hpp/cpp", as well as made the "Colors" namespace functions inline.
    - Added some inline functions for the string utils in "Formatting.hpp/cpp".

    Changes in v1.3.4:
    - Upgraded the project to ISO C++20.
    - Added an extra null check in "EventsComponent::ProcessEventDetour" in "Events.cpp".
    - Added three new functions, "Lerp", "Midpoint" and "DistanceTo", to all the vector classes in "Math.hpp/cpp".
    - Added a built in "VectorF::Rotate" function  in "Math.hpp/cpp".
    - Added a new templated "RandomRange" function in the "Math" namespace in "Math.hpp".
    - Added the "<numeric>" and "<random>" headers include to "pch.hpp" because thats needed for the new/updated functions in "Math.cpp".
    - Added new "Formatting::ReplaceAllChars" and "Formatting::Contains" functions in "Formatting.hpp/cpp".
    - Replaced all the "IsChar" functions in "Formatting.hpp/cpp" and replaced them with C++ library functions instead.
    - Changed the "ToLower" and "ToUpper" functions to use "std::transform" instead in "Formatting.cpp".
    - Fixed the "Formatting::RemoveFileChars" function missing a character in "Formatting.cpp".
    - Removed the "RotateUnreal" and "GetDistance" functions from the "Math" namespace, please use the built in functions in the vector classes instead.

    Changes in v1.3.3:
    - Revamped the console command and queue system, replaced it with "InternalCommand" and "ConsoleCommand" functions, they now automatically queue based on which thread you are calling them from!
    - Added a bunch of extra functions to the "Color" and "LinearColor" classes, they can convert the underlying color values to decimal or hex in "Colors.hpp/cpp".
    - Added some template saftey checks in "Instances.hpp".
    - Added a "Conjugate" function to the "Quat" class in "Math.hpp/cpp"
    - Changed how the "UnrealCommand" function works in "Manager.cpp", added checks to remove the original command and only pass the arguments.
    - Changed how color values are stored in the "Setting" class in "Manager.cpp", they are now stored as their hex values instead of decimal.
    - Changed/added functions for how the "IsValueValid" function is determined for the "Setting" class in "Manager.cpp" as well how "SetStringValue" works in combination.
    - Fixed the "GetInverse" and modified the "Rotate" function which returns a vector rotated by the given quat.
    - Removed the "bOverride" option for the "Setting" class in "Manager.hpp/cpp".

    Changes in v1.3.2:
    - Added some console logging ifdefs to remind new people using this template how it works.
    - Added some extra null checks for the functions in "Instances.hpp".
    - Added a default bool argument for the "SetStringValue" function in the "Setting" class called "bOverride", if set to true when setting a string it skips and saftey checks internally.
    - Changed the "ResetToDefault" function in "Setting" class to use the new bool argument set to true as explained above.
    - Fixed color values not resetting to default properly if you called the function from a different thread.
    - Fixed the "DecimalToHex" function in "Colors.cpp".

    Changes in v1.3.1:
    - Remade and added tons of extra functions to the "Setting" class in "Manager.hpp/cpp", the additions and changes include all new range and value functions, as well as extra saftey checks.
    - Remade and added a bunch of extra helper functions in "Formatting.hpp", you should uh check them out if you want.
    - Changed the "AreGlobalsValid" function in "Core.cpp".

    Changes in v1.3.0: 
    - Modified some of the arguments for function hooking in "Events.hpp", as well as added extra functions for using their index directly.
    - Improved and fixed various operators and functions for the color and math classes in both "Colors.hpp/cpp" and "Math.hpp/cpp".

    Changes in v1.2.9:
    - Fixed the "IsStringNumber" and "IsStringFloat" functions from returning false if the given string was negitive in "Formatting.cpp".
    - Added two new functions, "ToLinear" and "ToColor", to the color structs in "Colors.hpp" which auto converts color types from one to the other.
    - Added a new setting type, "TYPE_ROTATOR", and added a "GetRotatorValue" to accommodate this for the "Setting" class in "Manager.hpp/cpp".
    - Added a "GetQuat" function which returns a Quat version of a Rotator in "Math.hpp/cpp".
    - Changed the constructor for the "Setting" class in "Manager.hpp", moved the "SettingTypes" type to the front.
    - Changed the example for initializing module variables in the "Initialize" function in "Manager.cpp".

    Changes in v1.2.8:
    - Added the function "IsValueValid" for the "Setting" class, this checks if the given string value is valid for the settings type and is safe to parse. Both "InRange" and "SetVale" now use this function in "Manager.cpp".
    - Added a new enum called "ThreadTypes" in "Manager.hpp", used in settings for identifying when it is safe to call certain functions.
    - Added a default "ThreadTypes" argument for the functions "SetValue" and "ResetToDefault" for the "Setting" class in "Manager.hpp/cpp", if updating the setting is done outside of the game's thread (like ImGui) it will automatically queue the command for you.
    - Made certain members and functions in "Manager.hpp" static.

    Changes in v1.2.7:
    - Added four new functions in "Formatting.hpp", "IsStringNumber", "IsStringFloat", "EraseAllChars", and "RemoveAllChars".
    - Fixed a bug in the "SetValue" function that prevented some setitng types from applying in "Manager.cpp".
    - Renamed the function "AddToQueue" to "QueueCommand" and changed the "CommandQueue" to use a new custom class in "Manager.hpp/cpp".
    - Made the "DecimalToHex" function have a fill of 6 now in "Colors.cpp".

    Changes in v1.2.6:
    - Fixed functions still going through Process Event if their detour was set to false if there were multiple voids bound to the same function.
    - Added the "IsEventBlacklisted" function in "Events.hpp" as part of the "ManagerComponent", and also made the "PostEvent" class call this in its "Detour" function in "Manager.cpp".
    - Added a special case for setting a boolean value in the "Setting" class function "SetValue".
    - Changed the "DecimalToHex" function in "Colors.cpp" to use streams instead of strings.

    Changes in v1.2.5:
    - Added an option "bLogToConsole" argument for the "ConsoleCommand" function in "Manager.hpp".
    - Added logging the old vs new value when changing a settings value for the "ConsoleCommand" function in "Manager.cpp".
    - Added a range feature for the "Setting" class, you can now specific a minimum and maximum range when setting values now. The new functions are "HasRange", "InRange", and "SetRange".
    - Added an example of how to use the new "SetRange" funtion in the "Initialize" function in "Manager.cpp".
    - Added a "Searchable" option for the "Command" class in "Manager.hpp", it has a default value of "true" in the classes constructor.
    - Added new functions, "GetId" and "GetDefaultValue", for the "Setting" class in "Manager.hpp".
    - Remade how binding and triggering setting/command callbacks work completely, and removed storing argument data in the "Command" class itself.
    - Changed/optimized some functions for the "Setting" class in "Manager.cpp".
    - Removed "CommandTypes" for the "Command" class in "Manager.hpp" as its no longer used.

    Changes in v1.2.4:
    - Made the static function/class maps in "Instances.hpp" private, to access their contents you should use the new "FindStaticClass" and "FindStaticFunction" functions in the same file.
    - Added/renamed functions in the "GameState.hpp/cpp" files and made them more organized.
    - Fixed "GameStateComponent" not having the new virtual "OnCreate" and "OnDestory" functions.
    - Changed the hook functions in "Events.cpp" to use the new "FindStaticFunction" functions from "Instances.hpp".
    - Changed grabbing the actor in the "UnrealCommand" to grab its default instance, instead of a random one in "Manager.cpp".
    - Changed the pointer check for setting instances to the "Instances.cpp" file, and modified "Events.cpp" to show this.

    Changes in v1.2.3:
    - Added an argument callback option for the "Setting" class in "Manager.hpp", works similar to the "Command" classes arugment callback but the argument is the string value of the setting.
    - Added an optional argument for the "UnrealCommand" function in "Manager.hpp" called "bLogToConsole".
    - Fixed the "Lerp" function for the "VectorI" class taking a float instead of an integer in "Math.hpp".
    - Fixed the operators for the "Rotator" class in "Manager.cpp" saying struct instead of class.
    - Removed the "ShouldCallback" bool for the "Setting" class in "Manager.hpp", changed the check to see if the functions are null or not before calling instead of the bool value.
    - Reformatted the constructors in the "Colors.cpp", "Math.cpp", "Module.cpp", "Component.cpp", files.
    - Removed the "KeyPressed" function from "Manager.hpp", this should be handled by yourself in your own component or module.

    Changes in v1.2.2:
    - Changed function hooks in "Events.hpp" to use std::function, which also adds proper lambda support.
    - Fixed the "Detoured" bool prematurely getting set to true in "Events.cpp".

    Changes in v1.2.1:
    - Improved memory functions in "UnrealMemory.hpp", just look at them for yourself or something idk.
    - Improved the constructors for the "Setting" and "Command" classes in "Manager.cpp".
    - Added the virutal functions "OnCreate" and "OnDestroy" in "Component.hpp", these can be manually called outside of the classes constructor and deconstructor.
    - Added a "CreatedInstances" vector in "Instances.hpp", when a custom object instance is created it is added to this vector. On the components "OnDestory" function all custom instances are marked to be destroyed as well.
    - Added the "CreateVariable" function in "Manager.hpp" and moved creating variables from :ManagerComponent"'s constuctor to the "Initialize" function in "Manager.cpp".
    - Added the "AttachDetour" and "DetachDetour" functions in "Events.hpp", this is now called from "InitializeGlobals" in "Core.cpp".
    - Moved the detaching Process Event from "CoreComponent"'s deconstructor to "EventsComponent"'s deconstuctor in "Events.cpp".
    - Made "WriteToLog" default to "true" in "Console.cpp".
    - Renamed "FColorList" to "GColorList" in "Colors.hpp".

    Changes in v1.2.0:
    - Added an extra null check for creating commands, settings, and modules in "Manager.cpp".
    - Changed/added constuctors for the "Color" and "LinearColor" classes in "Math.hpp/cpp" to be explicit, explicit because there are now auto conversions for different color types.
    - Remade the "Colors" namespace and added a ton of extra functions in "Math.hpp/cpp".
    - Reformatting/added extra comments in "Instances.hpp/cpp", and updated the PlaceholderSDK to accommodate this.
    - Changed all macros in "Math.hpp" to use static constant expressions.
    - Added includes for "Extensions/Includes.hpp" for both the "Component.hpp" and "Module.hpp" files.
    - Added nullcheck for detaching detours in "Core.cpp".

    Changes in v1.1.9:
    - Removed the pointless additional constructors for the console component in "Console.hpp".
    - Improved functions for the console component such as writing and timestamp formatting in "Console.hpp".
    - Changed the null check for modules in the "Initialize" function to use ternaries in "Manager.cpp".
    - Improved/added extra comments in classes around the project.

    Changes in v1.1.8:
    - Added the "MarkInvincible" function in "Manager.hpp" which lets you easily prevent objects from being destroyed.
    - Added saftey checks for the "invincible" functions in "Manager.cpp".
    - Added a null check for updating modules settings when the "Initialize" function is called in "Manager.cpp".
    - Added virtual deconstructors for components and modules.
    - Reformatted some of the constructors for the color classes in "Colors.cpp".

    Changes in v1.1.7:
    - Added the "MarkForDestory" function in "Instances.hpp", and updated the PlaceholderSDK to accommodate this.
    - Fixed the "GetVector3DValue" function for the "Setting" class in "Manager.cpp", it still passed the type check even if it were a "TYPE_VECTOR_2D".
    - Changed some cast types for the template functions in "Instances.hpp".
    - Renamed some of the example settings in "Manager.cpp".

    Changes in v1.1.6:
    - Changed how settings and commands names are stored, in their classes they are now identified by an enum value; their names are assigned in the constructor for the "ManagerComponent" in "Manager.cpp".
    - Changed how settings and commands are created to go along with the new enum identifier, as well as how their shared pointers are now retrieved.
    - Changed how the "UpdateSettings" function works in "Module.hpp", there you can retrieve setting values all at once from "ManagerComponent" when a setting updates.
    - Added examples for how the "ResetSetting", "PrintModule", and "UnrealCommand" functions from "ManagerComponent" can be used as actual commands.
    - Remade all the math classes to use templated base classes in "Math.hpp", along with changing their names to pair with their underlying types.
    - Added a "Recalculate" function for the "LinearColor" class in "Colors.hpp", this is auto called in one of the constructors to recalculate the values if the user inputs an incorrect color space. For example they mistakenly put in a value from 0-255 instead of 0f-1f.
    - Added a few const variables to operators in both "Colors.hpp" and "Math.hpp".

    Changes in v1.1.5:
    - Changed all function hooks to use the new "PreEvent" and "PostEvent" classes, they have neat template functions that auto recast for you as well as an option to not detour the function through Process Event.
    - Removed the "ParseArguments" and "SplitArguments" functions in "Manager.hpp" and instead moved it to the "Format" namespace in "Formatting.hpp".
    - Renamed the "Functions" namespace to "Hooks" in "Events.hpp".
    - Renamed the "Queue" vector in "Manager.hpp" to "CommandQueue".
    - Moved the function hook typedefs in "Events.hpp" to inside the "EventsComponent" class.

    Changes in v1.1.4:
    - Added the "CreateInstance" function in "Instances.hpp", this allows you to create new objects of any type and have it be added to the GObjects table.
    - Added the "ResetSetting" function to "Manager.hpp", resets a setting to its original default value.
    - Added the "PrintModule" function to "Manager.hpp", prints out a modules information to the console.
    - Remade how Modules, Settings, and Commands are created. Please see the changes in "Manager.hpp" and "Manager.cpp" for examples.
    - Renamed the unreal rotator function in "Math.hpp" to RotateUnreal.
    - Renamed some of the "States" enum names in "GameState.hpp" to include "STATE_" in front, because we are purposefully not making this enum an enum class.
    - Added template flags to the PlaceholderSDK.

    Changes in v1.1.3:
    - Renamed the project from CodeRedUniversal to CodeRedTemplate.
    - Added support for Vector and Vector2D settings to "Manager.hpp".
    - Added some unreal unit/cm constants in "Math.cpp" and reformatted some comments there.

    Changes in v1.1.2:
    - Added a "GetAllowedStates" function for Modules.
    - Added the "ColorToLinear" and "LinearToColor" converter functions to the "Colors" namespace.
    - Added a std::find check for blacklisting functions in "Events.cpp".
    - Fixed one of the constructors for the LinearColor class in "Colors.hpp".
    - Changed all the FColor structs in FColorList and FRainbowColor to use all the new Color classes in "Colors.hpp".
    - Removed the "ModuleTypes" enum and field in the Module constructor, because why would you really need it in the first place.

    Changes in v1.1.1:
    - Added a "Quat" class in "Math.cpp", along with a bunch of defines/math helpers.
    - Added "Get" functions to the FRainbowColor class, this copies the data but guarantees you can't modify the original structs by mistake.
    - Renamed all "CR" math classes to just normal structs in "Math.hpp", also added extra math functions and operators for already exsiting classes.
    - Renamed all "CR" color classes to just normal structs in "Colors.hpp", also added some extra operators for them.
    - Updated the placeholder sdk with the new math structs so the project can compile.

    Changes in v1.1.0:
    - Added a "WhitelistEvent" function in "Events.hpp".
    - Added the maps "StaticClasses" and "StaticFunctions" in "Instances.hpp", here all of these objects are mapped by their full name to their pointer.
    - Added extra saftey checks and warnings for hooking functions.
    - Changed how hooking functions, and binding them work. Now you can hook multiple voids to a singluar function, before it would be limited to only one.
    - Removed the toggle for logging functions in the EventsComponent, that was messy anyway.

    Changes in v1.0.9:
    - Added the Formatting extension files, includes helpful stream utils.
    - Made the console logging in "Core.cpp" use the new formatting extensions.
    - Made the console component to use std::ofstream and be more efficient in terms of initializing.
    - Improved the "UnrealMemory" files which are based on UE4 source.
    - Removed the "Filesystem" extension files as they have no real use (yet).
 
    Changes in v1.0.8:
    - Fixed the constructor for the "Setting" class not properly setting color values.
    - Fixed the "HexToDecimal" function in "Colors.hpp".
    - Updated the commenting in "Instances.hpp".

    Changes in v1.0.7:
    - Added constructors in the CRColor structs for their retrospective unreal engine structs.
    - Added the "Colors" namespace in "Colors.hpp" with some small color utils.
    - Made the Command and Setting vector a map in "Manager.hpp", using their Command/Setting names as the key.
    - Completely remade settings and commands, and changed the "Manager" module to match this, along with examples.
    - Added "CreateCommand" and "CreateSetting" functions in "Manager.hpp".
    - Remade how "GetCommand" and "GetSetting" work in "Manager.hpp".
    - Removed the "ModifySetting" function in "Manager.hpp" as it's no longer needed.
    - When an argument isn't provided for a setting, it now displays its current value to the console.

    Changes in v1.0.6:
    - Added a command queue, for executing Process Event functions outside of the games main thread (like in ImGui render scenes).
    - Added "Math.hpp" & "Math.cpp" which include custom vector and rotator structs, along with some helper functions.
    - Changed how the unreal color for the structs in "Colors.hpp" is calculated.
    - Added some structs to the PlaceholderSDK to match the new operators in "Math.hpp".

    Changes in v1.0.5:
    - Added some extra operators for the custom color structs in "Colors.hpp".
    - Added example of where to put the FRainbowColor hook.
    - Added examples on how to bind commands to module functions, as well as toggling bools.
    - Added an example on how to blacklist events from going through process event in Initialize function.
    - Added function to split an argument string by spaces (getting each word from a string and inserting into a vector).
    - Added hex color phrasing to the ModifySetting function.
    - Added option for the bool setting to toggle true/false with 1/0.
    - Moved the null check for functions in process event.
    - Fixed the constructor for StringSetting.
    - Removed the "Enabled" bool in the module base class, you should be adding this in your custo module class itself.

    Changes in v1.0.4:
    - Added an option to blacklist events from going through Process Event.
    - Added a global rainbow color class in "Colors.hpp", and remade "FColorList".
    - Remade how function hooks are found in "EventsComponent", it now maps out all functions internal index and their name.
    - Made console logging more efficient if you were using multiple functions that used different colors.
    - Made the "GetTimestamp" function static.

    Changes in v1.0.3:
    - Changed typedef for post function hooks.
    - Made the States enum a normal enum instead of an enum class to reduce the need to cast to its underlying type.
    - Added an "Initialized" private member for modules.
    - Made modules initialize first, then function hooks/instances.
*/