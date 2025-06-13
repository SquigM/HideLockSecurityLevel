#pragma once

#include <REX/REX.h>

namespace HideLockSecurityLevel
{
	class Config
	{
		REX::INI::Str<REX::INI::SettingStore> lock_text;

		Config() :
			lock_text("Config", "lock_text", "Locked")
		{
			auto store = REX::INI::SettingStore::GetSingleton();
			store->Init(INI_PATH, "");
			store->Load();
			store->Save();
		}

	public:
		static constexpr const char* INI_PATH = "OBSE/Plugins/HideLockSecurityLevel.ini";
		static Config*               GetSingleton()
		{
			static Config config = Config();
			return &config;
		}

		std::string LockText() { return lock_text.GetValue(); }
	};
}
