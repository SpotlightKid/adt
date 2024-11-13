
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






#pragma once
#ifndef ADT_Faust_pp_Gen_HPP_
#define ADT_Faust_pp_Gen_HPP_

#include <memory>

class ADT {
public:
    ADT();
    ~ADT();

    void init(float sample_rate);
    void clear() noexcept;

    void process(
        const float *in0,
        float *out0,float *out1,
        unsigned count) noexcept;

    enum { NumInputs = 1 };
    enum { NumOutputs = 2 };
    enum { NumActives = 7 };
    enum { NumPassives = 0 };
    enum { NumParameters = 7 };

    enum Parameter {
        p_Pan_Spread,
        p_Delay_Spread,
        p_Pitch_Spread,
        p_Lowpass,
        p_Highpass,
        p_Dry,
        p_Wet,
        
    };

    struct ParameterRange {
        float init;
        float min;
        float max;
    };

    static const char *parameter_label(unsigned index) noexcept;
    static const char *parameter_short_label(unsigned index) noexcept;
    static const char *parameter_symbol(unsigned index) noexcept;
    static const char *parameter_unit(unsigned index) noexcept;
    static const ParameterRange *parameter_range(unsigned index) noexcept;
    static bool parameter_is_trigger(unsigned index) noexcept;
    static bool parameter_is_boolean(unsigned index) noexcept;
    static bool parameter_is_integer(unsigned index) noexcept;
    static bool parameter_is_logarithmic(unsigned index) noexcept;

    float get_parameter(unsigned index) const noexcept;
    void set_parameter(unsigned index, float value) noexcept;

    
    float get_Pan_Spread() const noexcept;
    
    float get_Delay_Spread() const noexcept;
    
    float get_Pitch_Spread() const noexcept;
    
    float get_Lowpass() const noexcept;
    
    float get_Highpass() const noexcept;
    
    float get_Dry() const noexcept;
    
    float get_Wet() const noexcept;
    
    
    void set_Pan_Spread(float value) noexcept;
    
    void set_Delay_Spread(float value) noexcept;
    
    void set_Pitch_Spread(float value) noexcept;
    
    void set_Lowpass(float value) noexcept;
    
    void set_Highpass(float value) noexcept;
    
    void set_Dry(float value) noexcept;
    
    void set_Wet(float value) noexcept;
    

public:
    class BasicDsp;

private:
    std::unique_ptr<BasicDsp> fDsp;



};




#endif // ADT_Faust_pp_Gen_HPP_