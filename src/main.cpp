#include "config.h"

namespace Hook
{
	struct Hook_SPrintF
	{
		static std::int64_t BSStringSPrintFFunc(RE::BSString& outName, const char* fmtString, const char* arg)
		{
			return BSStringSPrintFFuncHook(outName, fmtString, HideLockSecurityLevel::Config::GetSingleton()->LockText().c_str());
		}

		static inline REL::Hook BSStringSPrintFFuncHook{ REL::Offset(0x6912370), 0xEB6, BSStringSPrintFFunc };
	};
}

OBSE_PLUGIN_LOAD(const OBSE::LoadInterface* a_obse)
{
	OBSE::Init(a_obse, { .trampoline = true, .trampolineSize = 32 });

	HideLockSecurityLevel::Config::GetSingleton();

	return true;
}