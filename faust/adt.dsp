declare name "ADT";
declare description "Automatic double tracking (not only) for vocals";
declare version "0.1";
declare author "Christopher Arndt";
declare license "MIT License";

import("stdfaust.lib");

NVOICES = 4;
MAX_DELAY = (ma.SR / 20) * NVOICES;
WINDOW_SAMPLES = 256;
XFADE_SAMPLES = 50;
SMOOTH_SAMPLES = 1024;

easeOutCubic(x) = 1 - pow(1 - x, 3);

easeInOutCubic(x) = 4 * x * x * x, 1 - pow(-2 * x + 2, 3) / 2 : select2(x < 0.5);

delay(ms) = de.sdelay(MAX_DELAY, SMOOTH_SAMPLES, ba.sec2samp(ms / 1000));

transpose(ct) = ef.transpose(WINDOW_SAMPLES, XFADE_SAMPLES, ct / 100);

// Split input into four signals and:
//
// | Channel | Pan         | Delay            | Pitch Shift           |
// | ------- | ----------- | ---------------- | --------------------- |
// |    1    | 0-100 left  | 1/4 Delay Spread | 1/2 Pitch Spread down |
// |    2    | 0- 50 left  | 3/4 Delay Spread | 1/1 Pitch Spread up   |
// |    3    | 0- 50 right | 2/4 Delay Spread | 1/2 Pitch Spread up   |
// |    4    | 0-100 right | 1/1 Delay Spread | 1/1 Pitch Spread down |
//
channel(i, pan_spread, delay_spread, pitch_spread) = delay(delay_ms) : transpose(pitch) : sp.panner(pan)
with {
    delay_factor(x) = 1 * (x==1), 3 * (x==2), 2 * (x==3), 4 * (x==4) :> _;
    pitch_factor(x) = -1 * (x==1), 2 * (x==2), 1 * (x==3), -2 * (x==4) :> _;
    pitch = pitch_spread * 0.5 * pitch_factor(i + 1);
    delay_ms = delay_spread * 0.25 * delay_factor(i + 1);
    pan_side = -1, 1 : select2(i<2);  // channels 1/2 left, channels 3/4 right
    pan = 0.5 + (pan_spread * pan_side);
};

adt4x = _ <: par(i, NVOICES, channel(i, pan_spread, delay_spread, pitch_spread)) :> /(NVOICES), /(NVOICES)
with {
    pan_spread = hslider("[1] Pan Spread", 100, 0, 100, 1) / 200 : si.smoo;
    delay_spread = hslider("[2] Delay Spread [unit:ms]", 40, 0, 100, 1);
    pitch_spread = hslider("[3] Pitch Spread [unit:ct]", 40, 0, 150, 1);
};

out_mixer(fx, dry, wet, in) = fx(in) : *(wet), *(wet) : +(in  / 2 * dry), +(in / 2 * dry);

fc_lp = hslider("[4] Lowpass [unit:Hz] [scale:log]", 3500, 20, 20000, 0.1) : si.smoo;
fc_hp = hslider("[5] Highpass [unit:Hz] [scale:log]", 20, 20, 20000, 0.1) : si.smoo;

lpf = fi.lowpass(2, fc_lp);
hpf = fi.highpass(2, fc_hp);

lpf_stereo = lpf, lpf;
hpf_stereo = hpf, hpf;

process = out_mixer(
    adt4x : lpf_stereo : hpf_stereo,
    hslider("[6] Dry [unit:dB]", -3, -90, 10, 0.1) : ba.db2linear,
    hslider("[7] Wet [unit:dB]", -4, -90, 10, 0.1) : ba.db2linear
);
