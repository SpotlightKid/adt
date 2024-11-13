
//------------------------------------------------------------------------------
// This file was generated using the Faust compiler (https://faust.grame.fr),
// and the Faust post-processor (https://github.com/jpcima/faustpp).
//
// Source: adt.dsp
// Name: ADT
// Author: Christopher Arndt
// Copyright: 
// License: MIT License
// Version: 0.1
//------------------------------------------------------------------------------







#include "ADT.hpp"



#include <utility>
#include <cmath>

class ADT::BasicDsp {
public:
    virtual ~BasicDsp() {}
};

//------------------------------------------------------------------------------
// Begin the Faust code section

namespace {

template <class T> inline T min(T a, T b) { return (a < b) ? a : b; }
template <class T> inline T max(T a, T b) { return (a > b) ? a : b; }

class Meta {
public:
    // dummy
    void declare(...) {}
};

class UI {
public:
    // dummy
    void openHorizontalBox(...) {}
    void openVerticalBox(...) {}
    void closeBox(...) {}
    void declare(...) {}
    void addButton(...) {}
    void addCheckButton(...) {}
    void addVerticalSlider(...) {}
    void addHorizontalSlider(...) {}
    void addVerticalBargraph(...) {}
    void addHorizontalBargraph(...) {}
};

typedef ADT::BasicDsp dsp;

} // namespace

#define FAUSTPP_VIRTUAL // do not declare any methods virtual
#define FAUSTPP_PRIVATE public // do not hide any members
#define FAUSTPP_PROTECTED public // do not hide any members

// define the DSP in the anonymous namespace
#define FAUSTPP_BEGIN_NAMESPACE namespace {
#define FAUSTPP_END_NAMESPACE }


#if defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

#ifndef FAUSTPP_PRIVATE
#   define FAUSTPP_PRIVATE private
#endif
#ifndef FAUSTPP_PROTECTED
#   define FAUSTPP_PROTECTED protected
#endif
#ifndef FAUSTPP_VIRTUAL
#   define FAUSTPP_VIRTUAL virtual
#endif

#ifndef FAUSTPP_BEGIN_NAMESPACE
#   define FAUSTPP_BEGIN_NAMESPACE
#endif
#ifndef FAUSTPP_END_NAMESPACE
#   define FAUSTPP_END_NAMESPACE
#endif

FAUSTPP_BEGIN_NAMESPACE

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

FAUSTPP_END_NAMESPACE
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>
FAUSTPP_BEGIN_NAMESPACE

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

static float mydsp_faustpower2_f(float value) {
	return value * value;
}

class mydsp : public dsp {
	
 FAUSTPP_PRIVATE:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	float fConst3;
	FAUSTFLOAT fHslider1;
	float fRec2[2];
	FAUSTFLOAT fHslider2;
	float fRec4[2];
	int IOTA0;
	float fVec0[65536];
	float fConst4;
	FAUSTFLOAT fHslider3;
	float fConst5;
	float fRec5[2];
	float fRec6[2];
	float fRec7[2];
	float fRec8[2];
	float fVec1[131072];
	float fRec9[2];
	float fConst6;
	float fRec10[2];
	float fRec11[2];
	float fRec12[2];
	float fRec13[2];
	float fVec2[131072];
	FAUSTFLOAT fHslider4;
	float fConst7;
	float fRec14[2];
	float fRec15[2];
	float fConst8;
	float fRec16[2];
	float fRec17[2];
	float fRec18[2];
	float fRec19[2];
	float fVec3[131072];
	float fRec20[2];
	float fConst9;
	float fRec21[2];
	float fRec22[2];
	float fRec23[2];
	float fRec24[2];
	float fVec4[131072];
	float fRec3[3];
	float fRec1[3];
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	float fRec26[3];
	float fRec25[3];
	
 public:
	mydsp() {
	}
	
	void metadata(Meta* m) { 
		m->declare("author", "Christopher Arndt");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.19.1");
		m->declare("compile_options", "-a /home/chris/tmp/tmpel522spj.cpp -lang cpp -ct 1 -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.1.0");
		m->declare("description", "Automatic double tracking (not only) for vocals");
		m->declare("filename", "adt.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "1.3.0");
		m->declare("license", "MIT License");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.5.0");
		m->declare("name", "ADT");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.6.0");
		m->declare("spats.lib/name", "Faust Spatialization Library");
		m->declare("spats.lib/version", "1.1.0");
		m->declare("version", "0.1");
	}

	FAUSTPP_VIRTUAL int getNumInputs() {
		return 1;
	}
	FAUSTPP_VIRTUAL int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	FAUSTPP_VIRTUAL void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 44.1f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 3.1415927f / fConst0;
		fConst4 = 0.2f * fConst0;
		fConst5 = 0.001f * fConst0;
		fConst6 = 0.0005f * fConst0;
		fConst7 = 0.2205f / fConst0;
		fConst8 = 0.00075f * fConst0;
		fConst9 = 0.00025f * fConst0;
	}
	
	FAUSTPP_VIRTUAL void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(2e+01f);
		fHslider1 = FAUSTFLOAT(3.5e+03f);
		fHslider2 = FAUSTFLOAT(4e+01f);
		fHslider3 = FAUSTFLOAT(4e+01f);
		fHslider4 = FAUSTFLOAT(1e+02f);
		fHslider5 = FAUSTFLOAT(-4.0f);
		fHslider6 = FAUSTFLOAT(-3.0f);
	}
	
	FAUSTPP_VIRTUAL void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec2[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec4[l2] = 0.0f;
		}
		IOTA0 = 0;
		for (int l3 = 0; l3 < 65536; l3 = l3 + 1) {
			fVec0[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec5[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fRec6[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec7[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec8[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 131072; l8 = l8 + 1) {
			fVec1[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			fRec9[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fRec10[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fRec11[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec12[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = l13 + 1) {
			fRec13[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 131072; l14 = l14 + 1) {
			fVec2[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			fRec14[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			fRec15[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			fRec16[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			fRec17[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			fRec18[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			fRec19[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 131072; l21 = l21 + 1) {
			fVec3[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
			fRec20[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = l23 + 1) {
			fRec21[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = l24 + 1) {
			fRec22[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = l25 + 1) {
			fRec23[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = l26 + 1) {
			fRec24[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 131072; l27 = l27 + 1) {
			fVec4[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 3; l28 = l28 + 1) {
			fRec3[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 3; l29 = l29 + 1) {
			fRec1[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 3; l30 = l30 + 1) {
			fRec26[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 3; l31 = l31 + 1) {
			fRec25[l31] = 0.0f;
		}
	}
	
	FAUSTPP_VIRTUAL void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	
	FAUSTPP_VIRTUAL void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	FAUSTPP_VIRTUAL mydsp* clone() {
		return new mydsp();
	}
	
	FAUSTPP_VIRTUAL int getSampleRate() {
		return fSampleRate;
	}
	
	FAUSTPP_VIRTUAL void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("ADT");
		ui_interface->declare(&fHslider4, "1", "");
		ui_interface->declare(&fHslider4, "unit", "%");
		ui_interface->addHorizontalSlider("Pan Spread", &fHslider4, FAUSTFLOAT(1e+02f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider3, "2", "");
		ui_interface->declare(&fHslider3, "unit", "ms");
		ui_interface->addHorizontalSlider("Delay Spread", &fHslider3, FAUSTFLOAT(4e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider2, "3", "");
		ui_interface->declare(&fHslider2, "unit", "ct");
		ui_interface->addHorizontalSlider("Pitch Spread", &fHslider2, FAUSTFLOAT(4e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.5e+02f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider1, "4", "");
		ui_interface->declare(&fHslider1, "scale", "log");
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("Lowpass", &fHslider1, FAUSTFLOAT(3.5e+03f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider0, "5", "");
		ui_interface->declare(&fHslider0, "scale", "log");
		ui_interface->declare(&fHslider0, "unit", "Hz");
		ui_interface->addHorizontalSlider("Highpass", &fHslider0, FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider6, "6", "");
		ui_interface->declare(&fHslider6, "unit", "dB");
		ui_interface->addHorizontalSlider("Dry", &fHslider6, FAUSTFLOAT(-3.0f), FAUSTFLOAT(-9e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider5, "7", "");
		ui_interface->declare(&fHslider5, "unit", "dB");
		ui_interface->addHorizontalSlider("Wet", &fHslider5, FAUSTFLOAT(-4.0f), FAUSTFLOAT(-9e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
	}
	
	FAUSTPP_VIRTUAL void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = fConst1 * float(fHslider0);
		float fSlow1 = fConst1 * float(fHslider1);
		float fSlow2 = float(fHslider2);
		float fSlow3 = 0.00083333335f * fSlow2;
		float fSlow4 = std::pow(2.0f, -fSlow3);
		float fSlow5 = float(fHslider3);
		float fSlow6 = fConst5 * fSlow5;
		float fSlow7 = 0.00041666668f * fSlow2;
		float fSlow8 = std::pow(2.0f, fSlow7);
		float fSlow9 = fConst6 * fSlow5;
		float fSlow10 = fConst7 * float(fHslider4);
		float fSlow11 = std::pow(2.0f, fSlow3);
		float fSlow12 = fConst8 * fSlow5;
		float fSlow13 = std::pow(2.0f, -fSlow7);
		float fSlow14 = fConst9 * fSlow5;
		float fSlow15 = std::pow(1e+01f, 0.05f * float(fHslider5));
		float fSlow16 = 0.5f * std::pow(1e+01f, 0.05f * float(fHslider6));
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			fRec0[0] = fSlow0 + fConst2 * fRec0[1];
			float fTemp0 = std::tan(fConst3 * fRec0[0]);
			float fTemp1 = 1.0f / fTemp0;
			float fTemp2 = (fTemp1 + 1.4142135f) / fTemp0 + 1.0f;
			float fTemp3 = mydsp_faustpower2_f(fTemp0);
			float fTemp4 = fTemp3 * fTemp2;
			float fTemp5 = 1.0f - 1.0f / fTemp3;
			float fTemp6 = (fTemp1 + -1.4142135f) / fTemp0 + 1.0f;
			fRec2[0] = fSlow1 + fConst2 * fRec2[1];
			float fTemp7 = std::tan(fConst3 * fRec2[0]);
			float fTemp8 = 1.0f / fTemp7;
			float fTemp9 = (fTemp8 + 1.4142135f) / fTemp7 + 1.0f;
			float fTemp10 = 1.0f - 1.0f / mydsp_faustpower2_f(fTemp7);
			float fTemp11 = (fTemp8 + -1.4142135f) / fTemp7 + 1.0f;
			fRec4[0] = std::fmod(fRec4[1] + 257.0f - fSlow4, 256.0f);
			float fTemp12 = std::min<float>(0.02f * fRec4[0], 1.0f);
			float fTemp13 = float(input0[i0]);
			fVec0[IOTA0 & 65535] = fTemp13;
			float fTemp14 = ((fRec5[1] != 0.0f) ? (((fRec6[1] > 0.0f) & (fRec6[1] < 1.0f)) ? fRec5[1] : 0.0f) : (((fRec6[1] == 0.0f) & (fSlow6 != fRec7[1])) ? 0.0009765625f : (((fRec6[1] == 1.0f) & (fSlow6 != fRec8[1])) ? -0.0009765625f : 0.0f)));
			fRec5[0] = fTemp14;
			fRec6[0] = std::max<float>(0.0f, std::min<float>(1.0f, fRec6[1] + fTemp14));
			fRec7[0] = (((fRec6[1] >= 1.0f) & (fRec8[1] != fSlow6)) ? fSlow6 : fRec7[1]);
			fRec8[0] = (((fRec6[1] <= 0.0f) & (fRec7[1] != fSlow6)) ? fSlow6 : fRec8[1]);
			float fTemp15 = fVec0[(IOTA0 - int(std::min<float>(fConst4, std::max<float>(0.0f, fRec7[0])))) & 65535];
			float fTemp16 = fTemp15 + fRec6[0] * (fVec0[(IOTA0 - int(std::min<float>(fConst4, std::max<float>(0.0f, fRec8[0])))) & 65535] - fTemp15);
			fVec1[IOTA0 & 131071] = fTemp16;
			float fTemp17 = fRec4[0] + 256.0f;
			int iTemp18 = int(fTemp17);
			float fTemp19 = std::floor(fTemp17);
			int iTemp20 = int(fRec4[0]);
			float fTemp21 = std::floor(fRec4[0]);
			fRec9[0] = std::fmod(fRec9[1] + 257.0f - fSlow8, 256.0f);
			float fTemp22 = std::min<float>(0.02f * fRec9[0], 1.0f);
			float fTemp23 = ((fRec10[1] != 0.0f) ? (((fRec11[1] > 0.0f) & (fRec11[1] < 1.0f)) ? fRec10[1] : 0.0f) : (((fRec11[1] == 0.0f) & (fSlow9 != fRec12[1])) ? 0.0009765625f : (((fRec11[1] == 1.0f) & (fSlow9 != fRec13[1])) ? -0.0009765625f : 0.0f)));
			fRec10[0] = fTemp23;
			fRec11[0] = std::max<float>(0.0f, std::min<float>(1.0f, fRec11[1] + fTemp23));
			fRec12[0] = (((fRec11[1] >= 1.0f) & (fRec13[1] != fSlow9)) ? fSlow9 : fRec12[1]);
			fRec13[0] = (((fRec11[1] <= 0.0f) & (fRec12[1] != fSlow9)) ? fSlow9 : fRec13[1]);
			float fTemp24 = fVec0[(IOTA0 - int(std::min<float>(fConst4, std::max<float>(0.0f, fRec12[0])))) & 65535];
			float fTemp25 = fTemp24 + fRec11[0] * (fVec0[(IOTA0 - int(std::min<float>(fConst4, std::max<float>(0.0f, fRec13[0])))) & 65535] - fTemp24);
			fVec2[IOTA0 & 131071] = fTemp25;
			float fTemp26 = fRec9[0] + 256.0f;
			int iTemp27 = int(fTemp26);
			float fTemp28 = std::floor(fTemp26);
			int iTemp29 = int(fRec9[0]);
			float fTemp30 = std::floor(fRec9[0]);
			float fTemp31 = (fVec2[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp29))) & 131071] * (fTemp30 + (1.0f - fRec9[0])) + (fRec9[0] - fTemp30) * fVec2[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp29 + 1))) & 131071]) * fTemp22 + (fVec2[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp27))) & 131071] * (fTemp28 + (-255.0f - fRec9[0])) + (fRec9[0] + (256.0f - fTemp28)) * fVec2[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp27 + 1))) & 131071]) * (1.0f - fTemp22) + (fVec1[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp20))) & 131071] * (fTemp21 + (1.0f - fRec4[0])) + (fRec4[0] - fTemp21) * fVec1[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp20 + 1))) & 131071]) * fTemp12 + (fVec1[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp18))) & 131071] * (fTemp19 + (-255.0f - fRec4[0])) + (fRec4[0] + (256.0f - fTemp19)) * fVec1[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp18 + 1))) & 131071]) * (1.0f - fTemp12);
			fRec14[0] = fSlow10 + fConst2 * fRec14[1];
			float fTemp32 = fRec14[0] + 0.5f;
			fRec15[0] = std::fmod(fRec15[1] + 257.0f - fSlow11, 256.0f);
			float fTemp33 = std::min<float>(0.02f * fRec15[0], 1.0f);
			float fTemp34 = ((fRec16[1] != 0.0f) ? (((fRec17[1] > 0.0f) & (fRec17[1] < 1.0f)) ? fRec16[1] : 0.0f) : (((fRec17[1] == 0.0f) & (fSlow12 != fRec18[1])) ? 0.0009765625f : (((fRec17[1] == 1.0f) & (fSlow12 != fRec19[1])) ? -0.0009765625f : 0.0f)));
			fRec16[0] = fTemp34;
			fRec17[0] = std::max<float>(0.0f, std::min<float>(1.0f, fRec17[1] + fTemp34));
			fRec18[0] = (((fRec17[1] >= 1.0f) & (fRec19[1] != fSlow12)) ? fSlow12 : fRec18[1]);
			fRec19[0] = (((fRec17[1] <= 0.0f) & (fRec18[1] != fSlow12)) ? fSlow12 : fRec19[1]);
			float fTemp35 = fVec0[(IOTA0 - int(std::min<float>(fConst4, std::max<float>(0.0f, fRec18[0])))) & 65535];
			float fTemp36 = fTemp35 + fRec17[0] * (fVec0[(IOTA0 - int(std::min<float>(fConst4, std::max<float>(0.0f, fRec19[0])))) & 65535] - fTemp35);
			fVec3[IOTA0 & 131071] = fTemp36;
			float fTemp37 = fRec15[0] + 256.0f;
			int iTemp38 = int(fTemp37);
			float fTemp39 = std::floor(fTemp37);
			int iTemp40 = int(fRec15[0]);
			float fTemp41 = std::floor(fRec15[0]);
			fRec20[0] = std::fmod(fRec20[1] + 257.0f - fSlow13, 256.0f);
			float fTemp42 = std::min<float>(0.02f * fRec20[0], 1.0f);
			float fTemp43 = ((fRec21[1] != 0.0f) ? (((fRec22[1] > 0.0f) & (fRec22[1] < 1.0f)) ? fRec21[1] : 0.0f) : (((fRec22[1] == 0.0f) & (fSlow14 != fRec23[1])) ? 0.0009765625f : (((fRec22[1] == 1.0f) & (fSlow14 != fRec24[1])) ? -0.0009765625f : 0.0f)));
			fRec21[0] = fTemp43;
			fRec22[0] = std::max<float>(0.0f, std::min<float>(1.0f, fRec22[1] + fTemp43));
			fRec23[0] = (((fRec22[1] >= 1.0f) & (fRec24[1] != fSlow14)) ? fSlow14 : fRec23[1]);
			fRec24[0] = (((fRec22[1] <= 0.0f) & (fRec23[1] != fSlow14)) ? fSlow14 : fRec24[1]);
			float fTemp44 = fVec0[(IOTA0 - int(std::min<float>(fConst4, std::max<float>(0.0f, fRec23[0])))) & 65535];
			float fTemp45 = fTemp44 + fRec22[0] * (fVec0[(IOTA0 - int(std::min<float>(fConst4, std::max<float>(0.0f, fRec24[0])))) & 65535] - fTemp44);
			fVec4[IOTA0 & 131071] = fTemp45;
			float fTemp46 = fRec20[0] + 256.0f;
			int iTemp47 = int(fTemp46);
			float fTemp48 = std::floor(fTemp46);
			int iTemp49 = int(fRec20[0]);
			float fTemp50 = std::floor(fRec20[0]);
			float fTemp51 = (fVec4[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp49))) & 131071] * (fTemp50 + (1.0f - fRec20[0])) + (fRec20[0] - fTemp50) * fVec4[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp49 + 1))) & 131071]) * fTemp42 + (fVec4[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp47))) & 131071] * (fTemp48 + (-255.0f - fRec20[0])) + (fRec20[0] + (256.0f - fTemp48)) * fVec4[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp47 + 1))) & 131071]) * (1.0f - fTemp42) + (fVec3[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp40))) & 131071] * (fTemp41 + (1.0f - fRec15[0])) + (fRec15[0] - fTemp41) * fVec3[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp40 + 1))) & 131071]) * fTemp33 + (fVec3[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp38))) & 131071] * (fTemp39 + (-255.0f - fRec15[0])) + (fRec15[0] + (256.0f - fTemp39)) * fVec3[(IOTA0 - std::min<int>(65537, std::max<int>(0, iTemp38 + 1))) & 131071]) * (1.0f - fTemp33);
			float fTemp52 = 0.5f - fRec14[0];
			fRec3[0] = 0.25f * (fTemp52 * fTemp51 + fTemp32 * fTemp31) - (fRec3[2] * fTemp11 + 2.0f * fRec3[1] * fTemp10) / fTemp9;
			fRec1[0] = (fRec3[2] + fRec3[0] + 2.0f * fRec3[1]) / fTemp9 - (fRec1[2] * fTemp6 + 2.0f * fRec1[1] * fTemp5) / fTemp2;
			float fTemp53 = fSlow16 * fTemp13;
			output0[i0] = FAUSTFLOAT(fTemp53 + fSlow15 * ((fRec1[0] + fRec1[2] - 2.0f * fRec1[1]) / fTemp4));
			fRec26[0] = 0.25f * (fTemp32 * fTemp51 + fTemp52 * fTemp31) - (fTemp11 * fRec26[2] + 2.0f * fTemp10 * fRec26[1]) / fTemp9;
			fRec25[0] = (fRec26[2] + fRec26[0] + 2.0f * fRec26[1]) / fTemp9 - (fTemp6 * fRec25[2] + 2.0f * fTemp5 * fRec25[1]) / fTemp2;
			output1[i0] = FAUSTFLOAT(fTemp53 + fSlow15 * ((fRec25[0] + fRec25[2] - 2.0f * fRec25[1]) / fTemp4));
			fRec0[1] = fRec0[0];
			fRec2[1] = fRec2[0];
			fRec4[1] = fRec4[0];
			IOTA0 = IOTA0 + 1;
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			fRec9[1] = fRec9[0];
			fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
			fRec12[1] = fRec12[0];
			fRec13[1] = fRec13[0];
			fRec14[1] = fRec14[0];
			fRec15[1] = fRec15[0];
			fRec16[1] = fRec16[0];
			fRec17[1] = fRec17[0];
			fRec18[1] = fRec18[0];
			fRec19[1] = fRec19[0];
			fRec20[1] = fRec20[0];
			fRec21[1] = fRec21[0];
			fRec22[1] = fRec22[0];
			fRec23[1] = fRec23[0];
			fRec24[1] = fRec24[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
		}
	}

};
FAUSTPP_END_NAMESPACE


#if defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif



//------------------------------------------------------------------------------
// End the Faust code section




ADT::ADT()
{

    mydsp *dsp = new mydsp;
    fDsp.reset(dsp);
    dsp->instanceResetUserInterface();

}

ADT::~ADT()
{
}

void ADT::init(float sample_rate)
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.classInit(sample_rate);
    dsp.instanceConstants(sample_rate);
    clear();

}

void ADT::clear() noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.instanceClear();

}

void ADT::process(
    const float *in0,
    float *out0,float *out1,
    unsigned count) noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    float *inputs[] = {
        const_cast<float *>(in0),
    };
    float *outputs[] = {
        out0,out1,
    };
    dsp.compute(count, inputs, outputs);

}

const char *ADT::parameter_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "Pan Spread";
    
    case 1:
        return "Delay Spread";
    
    case 2:
        return "Pitch Spread";
    
    case 3:
        return "Lowpass";
    
    case 4:
        return "Highpass";
    
    case 5:
        return "Dry";
    
    case 6:
        return "Wet";
    
    default:
        return 0;
    }
}

const char *ADT::parameter_short_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "";
    
    case 1:
        return "";
    
    case 2:
        return "";
    
    case 3:
        return "";
    
    case 4:
        return "";
    
    case 5:
        return "";
    
    case 6:
        return "";
    
    default:
        return 0;
    }
}

const char *ADT::parameter_symbol(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "Pan_Spread";
    
    case 1:
        return "Delay_Spread";
    
    case 2:
        return "Pitch_Spread";
    
    case 3:
        return "Lowpass";
    
    case 4:
        return "Highpass";
    
    case 5:
        return "Dry";
    
    case 6:
        return "Wet";
    
    default:
        return 0;
    }
}

const char *ADT::parameter_unit(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "%";
    
    case 1:
        return "ms";
    
    case 2:
        return "ct";
    
    case 3:
        return "Hz";
    
    case 4:
        return "Hz";
    
    case 5:
        return "dB";
    
    case 6:
        return "dB";
    
    default:
        return 0;
    }
}

const ADT::ParameterRange *ADT::parameter_range(unsigned index) noexcept
{
    switch (index) {
    
    case 0: {
        static const ParameterRange range = { 100.0, 0.0, 100.0 };
        return &range;
    }
    
    case 1: {
        static const ParameterRange range = { 40.0, 0.0, 100.0 };
        return &range;
    }
    
    case 2: {
        static const ParameterRange range = { 40.0, 0.0, 150.0 };
        return &range;
    }
    
    case 3: {
        static const ParameterRange range = { 3500.0, 20.0, 20000.0 };
        return &range;
    }
    
    case 4: {
        static const ParameterRange range = { 20.0, 20.0, 20000.0 };
        return &range;
    }
    
    case 5: {
        static const ParameterRange range = { -3.0, -90.0, 10.0 };
        return &range;
    }
    
    case 6: {
        static const ParameterRange range = { -4.0, -90.0, 10.0 };
        return &range;
    }
    
    default:
        return 0;
    }
}

bool ADT::parameter_is_trigger(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool ADT::parameter_is_boolean(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool ADT::parameter_is_integer(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool ADT::parameter_is_logarithmic(unsigned index) noexcept
{
    switch (index) {
    
    case 3:
        return true;
    
    case 4:
        return true;
    
    default:
        return false;
    }
}

float ADT::get_parameter(unsigned index) const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        return dsp.fHslider4;
    
    case 1:
        return dsp.fHslider3;
    
    case 2:
        return dsp.fHslider2;
    
    case 3:
        return dsp.fHslider1;
    
    case 4:
        return dsp.fHslider0;
    
    case 5:
        return dsp.fHslider6;
    
    case 6:
        return dsp.fHslider5;
    
    default:
        (void)dsp;
        return 0;
    }
}

void ADT::set_parameter(unsigned index, float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        dsp.fHslider4 = value;
        break;
    
    case 1:
        dsp.fHslider3 = value;
        break;
    
    case 2:
        dsp.fHslider2 = value;
        break;
    
    case 3:
        dsp.fHslider1 = value;
        break;
    
    case 4:
        dsp.fHslider0 = value;
        break;
    
    case 5:
        dsp.fHslider6 = value;
        break;
    
    case 6:
        dsp.fHslider5 = value;
        break;
    
    default:
        (void)dsp;
        (void)value;
        break;
    }
}


float ADT::get_Pan_Spread() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider4;
}

float ADT::get_Delay_Spread() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider3;
}

float ADT::get_Pitch_Spread() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider2;
}

float ADT::get_Lowpass() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider1;
}

float ADT::get_Highpass() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider0;
}

float ADT::get_Dry() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider6;
}

float ADT::get_Wet() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider5;
}


void ADT::set_Pan_Spread(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider4 = value;
}

void ADT::set_Delay_Spread(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider3 = value;
}

void ADT::set_Pitch_Spread(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider2 = value;
}

void ADT::set_Lowpass(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider1 = value;
}

void ADT::set_Highpass(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider0 = value;
}

void ADT::set_Dry(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider6 = value;
}

void ADT::set_Wet(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider5 = value;
}



