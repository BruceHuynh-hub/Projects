library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity d_FF is
port(D, clk, rst : IN std_logic; Q : OUT std_logic);
end entity d_FF;
architecture d of d_FF is
begin
--Q <= '0' when rst = '1' ELSE D when rising_edge(clk); 
clock: process(clk,rst) begin
if (rst = '1') then
Q <= '0';
elsif (rising_edge(clk)) then
Q <= D;
end if;
end process clock;
end architecture d;

