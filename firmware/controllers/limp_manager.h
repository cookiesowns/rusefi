#pragma once

#include "engine_ptr.h"

#include <cstdint>

// Only allows clearing the value, but never resetting it.
class Clearable {
public:
	void clear() {
		m_value = false;
	}

	operator bool() const {
		return m_value;
	}

private:
	bool m_value = true;
};

class LimpManager {
public:
	DECLARE_ENGINE_PTR;

	// This is called from periodicFastCallback to update internal state
	void updateState(int rpm);

	// Other subsystems call these APIs to determine their behavior
	bool allowElectronicThrottle() const;

	bool allowInjection() const;
	bool allowIgnition() const;

	bool allowTriggerInput() const;

	// Other subsystems call these APIs to indicate a problem has occured
	void etbProblem();
	void fatalError();

private:
	void setFaultRevLimit(int limit);

	// Start with no fault rev limit
	int32_t m_faultRevLimit = INT32_MAX;

	Clearable m_allowEtb;
	Clearable m_allowInjection;
	Clearable m_allowIgnition;
	Clearable m_allowTriggerInput;

	bool m_transientLimitInjection = false;
	bool m_transientLimitIgnition = false;
};
