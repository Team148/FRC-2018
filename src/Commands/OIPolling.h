#ifndef OIPolling_H
#define OIPolling_H

#include "../CommandBase.h"

class OIPolling : public CommandBase {
public:
	OIPolling();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // OIPolling_H
