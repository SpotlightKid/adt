declare name "ADT";
declare description "Automatic double tracking (not only) for vocals"";
declare author "Christopher Arndt";
declare license "MIT";

import("stdfaust.lib");

gain = hslider("[0]Gain [symbol: gain][abbrev: gain][unit: dB]", -6.0, -90.0, 30.0, 0.1):si.smoo;

process = _ * ba.db2linear(gain);
