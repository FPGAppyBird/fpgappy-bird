create_clock -period 20 [get_ports clk]
derive_clock_uncertainty
set_input_delay 0 -clock clk [all_inputs]
set_output_delay 0 -clock clk [all_outputs]