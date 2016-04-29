module Nios (
clk,
rst_n,
led,
);
input clk, rst_n;
output [7:0] led;
DE2_115_QSYS DE2_115_QSYS_inst (
.clk_clk(clk),
.reset_reset_n(rst_n),
.led_export(led),
);
endmodule