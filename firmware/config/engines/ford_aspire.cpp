/**
 * @file    ford_aspire.cpp
 * @brief	1996 Ford Aspire default engine configuration
 *
 * FORD_ASPIRE_1996 = 3
 * set engine_type 3
 *
 * @date Sep 9, 2013
 * @author Andrey Belomutskiy, (c) 2012-2020
 */

#include "global.h"

#include "ford_aspire.h"

#include "allsensors.h"
#include "engine_math.h"
#include "advance_map.h"
#include "engine_configuration.h"

#if IGN_LOAD_COUNT == DEFAULT_IGN_LOAD_COUNT
static const ignition_table_t default_aspire_timing_table = {
/* RPM					800.000000	1213.333374	1626.666748	2040.000000	2453.333496	2866.666748	3280.000000	3693.333496	4106.666992	4520.000000	4933.333496	5346.666992	5760.000000	6173.333496	6586.666992	7000.000000*/
/* Load 1.200000 */{	-0.662000,	+7.730000,	+16.722000,	+23.139999,	+29.398001,	+31.268000,	+32.108002,	+30.436001,	+30.896000,	+26.656000,	+24.704000,	+25.108000,	+25.132000,	+25.459999,	+25.459999,	+25.459999},
/* Load 1.413333 */{	-0.546000,	+7.662000,	+16.882000,	+23.482000,	+29.520000,	+31.323999,	+32.108002,	+30.656000,	+30.468000,	+26.879999,	+24.746000,	+24.742001,	+29.032000,	+25.562000,	+25.562000,	+25.562000},
/* Load 1.626667 */{	-0.584000,	+7.870000,	+16.714001,	+23.025999,	+29.542000,	+31.166000,	+32.175999,	+30.540001,	+30.268000,	+26.416000,	+24.134001,	+25.007999,	+24.698000,	+26.167999,	+26.167999,	+26.167999},
/* Load 1.840000 */{	-0.584000,	+7.658000,	+16.714001,	+23.254000,	+29.351999,	+30.978001,	+32.141998,	+30.874001,	+30.896000,	+26.507999,	+24.558001,	+24.389999,	+25.761999,	+35.492001,	+35.492001,	+35.492001},
/* Load 2.053333 */{	-0.584000,	+7.862000,	+16.538000,	+23.254000,	+29.232000,	+31.296000,	+32.520000,	+30.142000,	+30.388000,	+25.903999,	+24.370001,	+24.082001,	+24.792000,	+24.351999,	+24.351999,	+24.351999},
/* Load 2.266667 */{	+1.364000,	+7.726000,	+16.806000,	+23.254000,	+29.639999,	+31.006001,	+32.298000,	+30.912001,	+29.882000,	+26.392000,	+24.664000,	+27.233999,	+25.374001,	+25.417999,	+25.417999,	+25.417999},
/* Load 2.480000 */{	-1.364000,	+10.490000,	+16.705999,	+22.441999,	+28.101999,	+30.238001,	+32.363998,	+30.719999,	+30.896000,	+26.608000,	+24.664000,	+24.431999,	+24.500000,	+25.510000,	+25.510000,	+25.510000},
/* Load 2.693333 */{	-9.864000,	+10.416000,	+11.680000,	+19.150000,	+25.754000,	+27.936001,	+32.554001,	+30.656000,	+30.153999,	+27.184000,	+25.252001,	+22.812000,	+24.452000,	+25.219999,	+25.219999,	+25.219999},
/* Load 2.906667 */{	-9.866000,	-5.452000,	-2.854000,	+17.212000,	+17.552000,	+20.688000,	+25.660000,	+27.809999,	+27.691999,	+27.224001,	+25.882000,	+25.360001,	+26.100000,	+27.992001,	+27.992001,	+27.992001},
/* Load 3.120000 */{	-9.864000,	-5.452000,	-2.854000,	+0.342000,	+12.526000,	+16.218000,	+21.364000,	+27.590000,	+25.780001,	+24.170000,	+24.664000,	+25.584000,	+26.490000,	+31.968000,	+31.968000,	+31.968000},
/* Load 3.333333 */{	-9.864000,	-5.516000,	-2.854000,	+0.226000,	+2.738000,	+3.816000,	+11.924000,	+18.808001,	+21.038000,	+21.538000,	+21.209999,	+22.228001,	+25.046000,	+25.156000,	+25.156000,	+25.156000},
/* Load 3.546667 */{	-9.866000,	-5.518000,	-2.854000,	-0.000000,	+3.022000,	+3.816000,	+6.428000,	+7.788000,	+19.426001,	+20.860001,	+19.966000,	+21.030001,	+21.396000,	+21.570000,	+21.570000,	+21.570000},
/* Load 3.760000 */{	-9.864000,	-5.516000,	-2.772000,	+0.226000,	+2.732000,	+3.500000,	+6.798000,	+8.102000,	+8.660000,	+9.500000,	+11.788000,	+20.132000,	+20.072001,	+20.510000,	+20.510000,	+20.510000},
/* Load 3.973333 */{	-9.864000,	-5.518000,	-2.854000,	-0.000000,	+2.880000,	+3.816000,	+6.420000,	+8.320000,	+8.426000,	+8.532000,	+11.470000,	+11.442000,	+13.610000,	+12.022000,	+12.022000,	+12.022000},
/* Load 4.186667 */{	-9.750000,	-5.518000,	-2.604000,	-0.000000,	+2.880000,	+3.654000,	+6.050000,	+6.888000,	+8.372000,	+9.364000,	+11.764000,	+11.732000,	+11.864000,	+12.376000,	+12.376000,	+12.376000},
/* Load 4.400000 */{	-0.350000,	-5.590000,	-0.502000,	-0.910000,	-0.864000,	-0.954000,	-1.324000,	+7.436000,	-1.170000,	-1.054000,	-2.058000,	-2.098000,	-2.636000,	+12.352000,	+12.352000,	+12.352000}
};
#endif

EXTERN_CONFIG;

static void setDefaultAspireMaps(DECLARE_CONFIG_PARAMETER_SIGNATURE) {
	setTimingLoadBin(1.2, 4.4 PASS_CONFIG_PARAMETER_SUFFIX);
	setTimingRpmBin(800, 7000 PASS_CONFIG_PARAMETER_SUFFIX);

#if IGN_LOAD_COUNT == DEFAULT_IGN_LOAD_COUNT
	MEMCPY(config->ignitionTable, default_aspire_timing_table);
#endif
}

void setFordAspireEngineConfiguration(DECLARE_CONFIG_PARAMETER_SIGNATURE) {
	setDefaultFrankensoConfiguration(PASS_CONFIG_PARAMETER_SIGNATURE);

	engineConfiguration->tpsMin = 100;
	engineConfiguration->tpsMax = 750;

	engineConfiguration->rpmHardLimit = 7000;

	/**
	 * 18K Ohm @ -20C
	 * 2.1K Ohm @ 24C
	 * 1K Ohm @ 49C
	 */
	// that's my custom resistor value!
	engineConfiguration->clt.config = {-20, 23.8889, 48.8889, 18000, 2100, 1000, 3300};

//	engineConfiguration->ignitionPinMode = OM_INVERTED;

	engineConfiguration->specs.cylindersCount = 4;
	engineConfiguration->specs.displacement = 1.3;
	// Denso 195500-2110
	engineConfiguration->injector.flow = 119.8;

	engineConfiguration->specs.firingOrder = FO_1_3_4_2;
	engineConfiguration->globalTriggerAngleOffset = 175;
	engineConfiguration->ignitionOffset = 87;
	engineConfiguration->extraInjectionOffset = 54 + 360;

	setDefaultAspireMaps(PASS_CONFIG_PARAMETER_SIGNATURE);
	// set_cranking_rpm 550
	engineConfiguration->cranking.rpm = 550;
	// set cranking_charge_angle 70
	engineConfiguration->crankingChargeAngle = 70;
	// set cranking_timing_angle 37
	engineConfiguration->crankingTimingAngle = -37;

	setSingleCoilDwell(PASS_CONFIG_PARAMETER_SIGNATURE);
	engineConfiguration->ignitionMode = IM_ONE_COIL;
	setOperationMode(engineConfiguration, FOUR_STROKE_CAM_SENSOR);
	engineConfiguration->useOnlyRisingEdgeForTrigger = true;
	engineConfiguration->trigger.type = TT_FORD_ASPIRE;

	engineConfiguration->injectionPins[4] = GPIO_UNASSIGNED;
	engineConfiguration->injectionPins[5] = GPIO_UNASSIGNED;

	engineConfiguration->HD44780width = 20;
	engineConfiguration->HD44780height = 4;

	// Frankenstein analog input #1: adc1
	// Frankenstein analog input #2: adc3
	// Frankenstein analog input #3: adc13
	// Frankenstein analog input #4: adc11
	// Frankenstein analog input #5: adc
	// Frankenstein analog input #6: adc
	// Frankenstein analog input #7: adc
	// Frankenstein analog input #8: adc
	// Frankenstein analog input #9: adc
	// Frankenstein analog input #10: adc
	// Frankenstein analog input #11: adc
	// Frankenstein analog input #12: adc


	engineConfiguration->tps1_1AdcChannel = EFI_ADC_3;
	engineConfiguration->vbattAdcChannel = EFI_ADC_0;
	engineConfiguration->map.sensor.hwChannel = EFI_ADC_4;
	engineConfiguration->mafAdcChannel = EFI_ADC_1;
	engineConfiguration->clt.adcChannel = EFI_ADC_11;
//	engineConfiguration->iat.adcChannel =

	engineConfiguration->map.sensor.type = MT_DENSO183;

	engineConfiguration->engineSnifferRpmThreshold = 13000;
	engineConfiguration->sensorSnifferRpmThreshold = 13000;
}
