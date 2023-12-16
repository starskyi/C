#pragma once
#pragma comment(lib,"mydll1.lib")
extern "C" _declspec(dllimport) int sum(int a, int b);
_declspec(dllimport) void hello();
