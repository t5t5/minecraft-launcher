#ifndef LAUNCHER_P_H
#define LAUNCHER_P_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <Qpe/Qpe>

#include <ml/DataModel>

namespace Ui { class Launcher; }

namespace ml
{

class Launcher;
class LauncherPrivate
{
	QPE_DECLARE_PUBLIC(Launcher)
protected:
	Launcher* q_ptr;
public:
	LauncherPrivate();
	~LauncherPrivate();

	void initialize();
	void reset();

	Ui::Launcher* ui;
	DataModelPointer model;
};

} // namespace ml

#endif // LAUNCHER_P_H
