#pragma once

#ifdef _DEBUG
#include <crtdbg.h>
//predefinovanie klucoveho slova new pre DEBUG rezim
#define DBG_NEW new (_NORMAL_BLOCK, __FILE__, __LINE__)

/// <summary>
/// pre vytvorenie konstantneho objektu pre indikaciu nedealokovanej pamati
/// </summary>
class MemLeak
{
public:
	~MemLeak() { _CrtDumpMemoryLeaks(); }
};

const MemLeak dummyLeak;
#else
#define DBG_NEW new
#endif // _DEBUG
